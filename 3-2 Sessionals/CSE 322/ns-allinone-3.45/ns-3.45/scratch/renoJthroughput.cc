/*
 * TCP RenoJ - throughput output to file
 * Topology: n0 --- r1 ---[1Mbps bottleneck]--- r2 --- n3
 */

#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/packet-sink.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ipv4-global-routing-helper.h"

#include <fstream>
#include <string>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("TcpRenoJThroughput");

std::ofstream g_throughputFile;

static void
CalculateThroughput(Ptr<PacketSink> sink)
{
    static uint64_t lastTotalRx = 0;
    double   curTime    = Simulator::Now().GetSeconds();
    uint64_t curRx      = sink->GetTotalRx();
    double   throughput = (curRx - lastTotalRx) * 8.0 / (0.5 * 1000.0); // Kbps
    lastTotalRx = curRx;

    g_throughputFile << curTime << "\t" << throughput << "\n";
    g_throughputFile.flush();

    Simulator::Schedule(Seconds(0.5), &CalculateThroughput, sink);
}

int
main(int argc, char* argv[])
{
    bool     tracing  = false;
    uint32_t maxBytes = 0;

    CommandLine cmd(__FILE__);
    cmd.AddValue("tracing",  "Enable tracing", tracing);
    cmd.AddValue("maxBytes", "Max bytes (0=unlimited)", maxBytes);
    cmd.Parse(argc, argv);

    g_throughputFile.open("throughput-RenoJ.tr");
    g_throughputFile << "# Time(s)\tThroughput(Kbps)\n";

    NodeContainer nodes;
    nodes.Create(4); // n0=sender, n1=router1, n2=router2, n3=receiver

    PointToPointHelper accessLink;
    accessLink.SetDeviceAttribute("DataRate", StringValue("10Mbps"));
    accessLink.SetChannelAttribute("Delay",   StringValue("1ms"));

    PointToPointHelper bottleneck;
    bottleneck.SetDeviceAttribute("DataRate", StringValue("1Mbps"));
    bottleneck.SetChannelAttribute("Delay",   StringValue("10ms"));
    bottleneck.SetQueue("ns3::DropTailQueue", "MaxSize", StringValue("27p"));

    NetDeviceContainer d01 = accessLink.Install(nodes.Get(0), nodes.Get(1));
    NetDeviceContainer d12 = bottleneck.Install(nodes.Get(1), nodes.Get(2));
    NetDeviceContainer d23 = accessLink.Install(nodes.Get(2), nodes.Get(3));

    // Set RenoJ BEFORE installing internet stack
    Config::SetDefault("ns3::TcpL4Protocol::SocketType",
                       TypeIdValue(TcpRenoJ::GetTypeId()));

    InternetStackHelper internet;
    internet.Install(nodes);

    Ipv4AddressHelper ipv4;
    ipv4.SetBase("10.1.1.0", "255.255.255.0");
    ipv4.Assign(d01);
    ipv4.SetBase("10.1.2.0", "255.255.255.0");
    ipv4.Assign(d12);
    ipv4.SetBase("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer i23 = ipv4.Assign(d23);

    Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    uint16_t port = 9;

    PacketSinkHelper sinkHelper("ns3::TcpSocketFactory",
                                InetSocketAddress(Ipv4Address::GetAny(), port));
    ApplicationContainer sinkApps = sinkHelper.Install(nodes.Get(3));
    sinkApps.Start(Seconds(0));
    sinkApps.Stop(Seconds(500));

    BulkSendHelper source("ns3::TcpSocketFactory",
                          InetSocketAddress(i23.GetAddress(1), port));
    source.SetAttribute("MaxBytes", UintegerValue(maxBytes));
    ApplicationContainer sourceApps = source.Install(nodes.Get(0));
    sourceApps.Start(Seconds(0));
    sourceApps.Stop(Seconds(500));

    if (tracing)
    {
        AsciiTraceHelper ascii;
        bottleneck.EnableAsciiAll(ascii.CreateFileStream("renoj.tr"));
    }

    Ptr<PacketSink> sink1 = DynamicCast<PacketSink>(sinkApps.Get(0));
    Simulator::Schedule(Seconds(0.5), &CalculateThroughput, sink1);

    Simulator::Stop(Seconds(500));
    Simulator::Run();
    Simulator::Destroy();

    g_throughputFile.close();

    Ptr<PacketSink> sink2 = DynamicCast<PacketSink>(sinkApps.Get(0));
    std::cout << "Total Bytes Received: " << sink2->GetTotalRx() << std::endl;

    return 0;
}