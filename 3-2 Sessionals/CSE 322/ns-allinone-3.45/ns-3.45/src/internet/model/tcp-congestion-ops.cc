/*
 * Copyright (c) 2015 Natale Patriciello <natale.patriciello@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 *
 */#include "tcp-congestion-ops.h"
#include "ns3/log.h"
#include <cmath>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("TcpCongestionOps");

NS_OBJECT_ENSURE_REGISTERED(TcpCongestionOps);

TypeId
TcpCongestionOps::GetTypeId()
{
    static TypeId tid =
        TypeId("ns3::TcpCongestionOps").SetParent<Object>().SetGroupName("Internet");
    return tid;
}

TcpCongestionOps::TcpCongestionOps()
    : Object()
{
}

TcpCongestionOps::TcpCongestionOps(const TcpCongestionOps& other)
    : Object(other)
{
}

TcpCongestionOps::~TcpCongestionOps()
{
}

void
TcpCongestionOps::IncreaseWindow(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);
}

void
TcpCongestionOps::PktsAcked(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked, const Time& rtt)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked << rtt);
}

void
TcpCongestionOps::CongestionStateSet(Ptr<TcpSocketState> tcb,
                                     const TcpSocketState::TcpCongState_t newState)
{
    NS_LOG_FUNCTION(this << tcb << newState);
}

void
TcpCongestionOps::CwndEvent(Ptr<TcpSocketState> tcb, const TcpSocketState::TcpCAEvent_t event)
{
    NS_LOG_FUNCTION(this << tcb << event);
}

bool
TcpCongestionOps::HasCongControl() const
{
    return false;
}

void
TcpCongestionOps::CongControl(Ptr<TcpSocketState> tcb,
                              const TcpRateOps::TcpRateConnection& /* rc */,
                              const TcpRateOps::TcpRateSample& /* rs */)
{
    NS_LOG_FUNCTION(this << tcb);
}


NS_OBJECT_ENSURE_REGISTERED(TcpNewReno);

TypeId
TcpNewReno::GetTypeId()
{
    static TypeId tid = TypeId("ns3::TcpNewReno")
                            .SetParent<TcpCongestionOps>()
                            .SetGroupName("Internet")
                            .AddConstructor<TcpNewReno>();
    return tid;
}

TypeId
TcpRenoJ::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::TcpRenoJ")
                            .SetParent<TcpNewReno>()
                            .SetGroupName("Internet")
                            .AddConstructor<TcpRenoJ>();
    return tid;
}

TcpNewReno::TcpNewReno()
    : TcpCongestionOps()
{
    NS_LOG_FUNCTION(this);
}

TcpNewReno::TcpNewReno(const TcpNewReno& sock)
    : TcpCongestionOps(sock)
{
    NS_LOG_FUNCTION(this);
}

TcpNewReno::~TcpNewReno()
{
}

TcpRenoJ::TcpRenoJ()
    : TcpNewReno(),
      m_lastPacketSize(0),
      m_lastRtt(Time::Max()),
      m_eqB(0),
      m_baseRtt(Time::Max())
{
    NS_LOG_FUNCTION(this);
}

TcpRenoJ::TcpRenoJ(const TcpRenoJ& sock)
    : TcpNewReno(sock),
      m_lastPacketSize(0),
      m_lastRtt(Time::Max()),
      m_eqB(0),
      m_baseRtt(Time::Max())
{
    NS_LOG_FUNCTION(this);
}

TcpRenoJ::~TcpRenoJ()
{
}

void
TcpRenoJ::PktsAcked(Ptr<TcpSocketState> tcb,
                    uint32_t segmentsAcked,
                    const Time& rtt)
{
    if (rtt.IsZero() || segmentsAcked == 0)
        return;

    uint32_t currentSize = segmentsAcked * tcb->m_segmentSize;

    if (m_baseRtt == Time::Max() || rtt < m_baseRtt)
        m_baseRtt = rtt;

    if (m_lastRtt != Time::Max())
    {
        double deltaRtt = rtt.GetSeconds() - m_lastRtt.GetSeconds();
        if (deltaRtt > 0)
        {
            double deltaSize = std::abs((double)currentSize - (double)m_lastPacketSize);
            m_eqB = deltaSize / deltaRtt;
        }
    }

    m_lastPacketSize = currentSize;
    m_lastRtt        = rtt;
}

uint32_t
TcpNewReno::SlowStart(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    if (segmentsAcked >= 1)
    {
        tcb->m_cWnd += tcb->m_segmentSize;
        NS_LOG_INFO("In SlowStart, updated to cwnd " << tcb->m_cWnd
                    << " ssthresh " << tcb->m_ssThresh);
        return segmentsAcked - 1;
    }

    return 0;
}

uint32_t
TcpRenoJ::SlowStart(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    if (segmentsAcked >= 1)
    {
        uint32_t currentCwnd = tcb->m_cWnd.Get();
        uint32_t ssthresh    = tcb->m_ssThresh.Get();
        uint32_t mss         = tcb->m_segmentSize;

        uint32_t maxReasonableSsthresh = 60 * mss;
        if (ssthresh > maxReasonableSsthresh)
        {
            tcb->m_cWnd += mss;
            return segmentsAcked - 1;
        }

        double S    = (double)(ssthresh + mss);
        double half = S / 2.0;

        uint32_t newCwnd;

        if ((double)currentCwnd < half)
        {
            newCwnd = currentCwnd + mss;
        }
        else
        {
            double x        = std::log2((double)currentCwnd / (double)mss);
            double SoverTwo = S / 2.0;
            double target   = S - SoverTwo * SoverTwo * std::pow(2.0, -x);

            if (target < (double)currentCwnd || target > (double)ssthresh)
            {
                newCwnd = currentCwnd + mss;
            }
            else
            {
                newCwnd = static_cast<uint32_t>(target);
                newCwnd = std::min(newCwnd, ssthresh);
                newCwnd = std::max(newCwnd, currentCwnd);
            }
        }

        tcb->m_cWnd = newCwnd;
        return segmentsAcked - 1;
    }

    return 0;
}

void
TcpNewReno::CongestionAvoidance(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    if (segmentsAcked > 0)
    {
        double adder =
            static_cast<double>(tcb->m_segmentSize * tcb->m_segmentSize) / tcb->m_cWnd.Get();
        adder = std::max(1.0, adder);
        tcb->m_cWnd += static_cast<uint32_t>(adder);
        NS_LOG_INFO("In CongAvoid, updated to cwnd " << tcb->m_cWnd
                    << " ssthresh " << tcb->m_ssThresh);
    }
}

void
TcpNewReno::IncreaseWindow(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    if (tcb->m_cWnd < tcb->m_ssThresh)
        segmentsAcked = SlowStart(tcb, segmentsAcked);

    if (tcb->m_cWnd >= tcb->m_ssThresh)
        CongestionAvoidance(tcb, segmentsAcked);
}


void 
TcpRenoJ::IncreaseWindow(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    if (tcb->m_ssThresh.Get() > 55 * tcb->m_segmentSize)
        tcb->m_ssThresh = 30 * tcb->m_segmentSize; // 21 theke 56 er majhamajhi

    if (tcb->m_cWnd < tcb->m_ssThresh)
        segmentsAcked = SlowStart(tcb, segmentsAcked);

    if (tcb->m_cWnd >= tcb->m_ssThresh)
        CongestionAvoidance(tcb, segmentsAcked);
}

std::string TcpNewReno::GetName() const { return "TcpNewReno"; }
std::string TcpRenoJ::GetName()   const { return "TcpRenoJ"; }

uint32_t
TcpNewReno::GetSsThresh(Ptr<const TcpSocketState> state, uint32_t bytesInFlight)
{
    NS_LOG_FUNCTION(this << state << bytesInFlight);
    return std::max(2 * state->m_segmentSize, bytesInFlight / 2);
}

uint32_t
TcpRenoJ::GetSsThresh(Ptr<const TcpSocketState> state,
                      uint32_t bytesInFlight)
{
    if (m_eqB > 0 && m_baseRtt != Time::Max())
    {
        double   ssthresh = m_eqB * m_baseRtt.GetSeconds();
        uint32_t minVal   = 21 * state->m_segmentSize;
        uint32_t maxVal   = 55 * state->m_segmentSize;
        uint32_t result   = static_cast<uint32_t>(ssthresh);
        result = std::max(result, minVal);
        result = std::min(result, maxVal);
        return result;
    }

    return std::max(2 * state->m_segmentSize, bytesInFlight / 2);
}

void
TcpRenoJ::CongestionStateSet(Ptr<TcpSocketState> tcb,
                              const TcpSocketState::TcpCongState_t newState)
{
    if (newState == TcpSocketState::CA_OPEN)
    {
        m_lastRtt        = Time::Max();
        m_lastPacketSize = 0;
        m_eqB            = 0;
    }
}

Ptr<TcpCongestionOps> TcpNewReno::Fork() { return CopyObject<TcpNewReno>(this); }
Ptr<TcpCongestionOps> TcpRenoJ::Fork()   { return CopyObject<TcpRenoJ>(this); }

} // namespace ns3