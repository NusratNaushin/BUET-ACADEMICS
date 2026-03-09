#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/packet-sink.h"
#include "ns3/point-to-point-module.h"

#include <fstream>
#include <string>

using namespace ns3;


//s0--r1--r2--r3
NS_LOG_COMPONENT_DEFINE("TcpBulkSendExampleWithRenoJ");

static void
CwndChange(uint32_t oldCwnd, uint32_t newCwnd)
{
    std::cout << Simulator::Now().GetSeconds() << "\t" << newCwnd << std::endl;
}

int
main(int argc, char* argv[])
{
    bool tracing = false;
    uint32_t maxBytes = 0;

    CommandLine cmd(__FILE__);
    cmd.AddValue("tracing", "Flag to enable/disable tracing", tracing);
    cmd.AddValue("maxBytes", "Total number of bytes for application to send", maxBytes);
    cmd.Parse(argc, argv);

    Config::SetDefault("ns3::TcpL4Protocol::SocketType",
                       TypeIdValue(TcpRenoJ::GetTypeId()));

    Config::SetDefault("ns3::TcpSocket::InitialSlowStartThreshold",
                       UintegerValue(30 * 536));

    NodeContainer nodes;
    nodes.Create(4);

    PointToPointHelper accessLink;
    accessLink.SetDeviceAttribute("DataRate", StringValue("10Mbps"));
    accessLink.SetChannelAttribute("Delay", StringValue("1ms"));

    PointToPointHelper bottleneck;
    bottleneck.SetDeviceAttribute("DataRate", StringValue("1Mbps"));
    bottleneck.SetChannelAttribute("Delay", StringValue("10ms"));
    bottleneck.SetQueue("ns3::DropTailQueue", "MaxSize", StringValue("27p"));   
    NetDeviceContainer d01 = accessLink.Install(nodes.Get(0), nodes.Get(1));
    NetDeviceContainer d12 = bottleneck.Install(nodes.Get(1), nodes.Get(2));
    NetDeviceContainer d23 = accessLink.Install(nodes.Get(2), nodes.Get(3));

    

    InternetStackHelper internet;
    internet.Install(nodes);

    Ipv4AddressHelper ipv4;
    ipv4.SetBase("10.1.1.0", "255.255.255.0");
    ipv4.Assign(d01);
    ipv4.SetBase("10.1.2.0", "255.255.255.0");
    Ipv4InterfaceContainer i12 = ipv4.Assign(d12);
    ipv4.SetBase("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer i23 = ipv4.Assign(d23);

    Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    uint16_t port = 9;

    BulkSendHelper source("ns3::TcpSocketFactory",
                          InetSocketAddress(i23.GetAddress(1), port));
    source.SetAttribute("MaxBytes", UintegerValue(maxBytes));
    ApplicationContainer sourceApps = source.Install(nodes.Get(0));
    sourceApps.Start(Seconds(0));
    sourceApps.Stop(Seconds(10));

    PacketSinkHelper sink("ns3::TcpSocketFactory",
                          InetSocketAddress(Ipv4Address::GetAny(), port));
    ApplicationContainer sinkApps = sink.Install(nodes.Get(3));
    sinkApps.Start(Seconds(0));
    sinkApps.Stop(Seconds(10));

    Simulator::Schedule(Seconds(0.01), []() {
        Config::ConnectWithoutContext(
            "/NodeList/0/$ns3::TcpL4Protocol/SocketList/*/CongestionWindow",
            MakeCallback(&CwndChange));
    });

    if (tracing)
    {
        AsciiTraceHelper ascii;
        bottleneck.EnableAsciiAll(ascii.CreateFileStream("tcp-bulk-send.tr"));
        bottleneck.EnablePcapAll("tcp-bulk-send", false);
    }

    Simulator::Stop(Seconds(10));
    Simulator::Run();
    Simulator::Destroy();

    Ptr<PacketSink> sink1 = DynamicCast<PacketSink>(sinkApps.Get(0));
    std::cout << "Total Bytes Received: " << sink1->GetTotalRx() << std::endl;

    return 0;
}