/*
 * Copyright (c) 2015 Natale Patriciello <natale.patriciello@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 *
 */
#include "tcp-congestion-ops.h"

#include "ns3/log.h"

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

// RENO

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
/*New Code*/


TypeId 
TcpRenoJ::GetTypeId(void){
    static TypeId tid = TypeId("ns3::TcpRenoJ")
                            .SetParent<TcpNewReno>()
                            .SetGroupName("Internet")
                            .AddConstructor<TcpRenoJ>();
    return tid;
}


TcpRenoJ::TcpRenoJ()
    : TcpNewReno()
{
    NS_LOG_FUNCTION(this);
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

TcpRenoJ::TcpRenoJ (const TcpRenoJ& sock) 
    : TcpNewReno (sock) 
    {
        NS_LOG_FUNCTION(this);
    }   

TcpNewReno::~TcpNewReno()
{
}

TcpRenoJ::~TcpRenoJ()
{
}

/**
 * @brief Tcp NewReno slow start algorithm
 *
 * Defined in RFC 5681 as
 *
 * > During slow start, a TCP increments cwnd by at most SMSS bytes for
 * > each ACK received that cumulatively acknowledges new data.  Slow
 * > start ends when cwnd exceeds ssthresh (or, optionally, when it
 * > reaches it, as noted above) or when congestion is observed.  While
 * > traditionally TCP implementations have increased cwnd by precisely
 * > SMSS bytes upon receipt of an ACK covering new data, we RECOMMEND
 * > that TCP implementations increase cwnd, per:
 * >
 * >     cwnd += min (N, SMSS)                      (2)
 * >
 * > where N is the number of previously unacknowledged bytes acknowledged
 * > in the incoming ACK.
 *
 * The ns-3 implementation respect the RFC definition. Linux does something
 * different:
 * \code{.cpp}
   u32 tcp_slow_start(struct tcp_sock *tp, u32 acked)
   {
     u32 cwnd = tp->snd_cwnd + acked;

     if (cwnd > tp->snd_ssthresh)
       cwnd = tp->snd_ssthresh + 1;
     acked -= cwnd - tp->snd_cwnd;
     tp->snd_cwnd = min(cwnd, tp->snd_cwnd_clamp);

     return acked;
   }
   \endcode
 *
 * As stated, we want to avoid the case when a cumulative ACK increases cWnd more
 * than a segment size, but we keep count of how many segments we have ignored,
 * and return them.
 *
 * @param tcb internal congestion state
 * @param segmentsAcked count of segments acked
 * @return the number of segments not considered for increasing the cWnd
 */
uint32_t
TcpNewReno::SlowStart(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    if (segmentsAcked >= 1)
    {
        tcb->m_cWnd += tcb->m_segmentSize;
        NS_LOG_INFO("In SlowStart, updated to cwnd " << tcb->m_cWnd << " ssthresh "
                                                     << tcb->m_ssThresh);
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

        uint32_t ssthresh = tcb->m_ssThresh.Get();

        uint32_t mss = tcb->m_segmentSize;

        uint32_t midpoint = (ssthresh + mss)  / 2 ;


        if (currentCwnd < midpoint){
            tcb->m_cWnd +=mss ;
        }
        else{
            double x = std::log2((double)currentCwnd / (double)mss);

            

            // f2(x) = ssthresh + 1 1- {(ssthresh+1)^2/4} *2^-x
            // ei function ta mid point cross korle use korbo as else er moddhe asi ekhn hocche ei fn ta likhbo 

            double f2 = ssthresh + 1 - ((std::pow(ssthresh + 1, 2) / 4) * std::pow(2, -x));

            if(f2 > currentCwnd){
                uint32_t increment = static_cast<uint32_t>(f2 - currentCwnd);
                tcb->m_cWnd += std::max(uint32_t(1), increment);  
            }
          

        }
        return segmentsAcked - 1;
    }

    return 0;
}









/**
 * @brief NewReno congestion avoidance
 *
 * During congestion avoidance, cwnd is incremented by roughly 1 full-sized
 * segment per round-trip time (RTT).
 *
 * @param tcb internal congestion state
 * @param segmentsAcked count of segments acked
 */
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
        NS_LOG_INFO("In CongAvoid, updated to cwnd " << tcb->m_cWnd << " ssthresh "
                                                     << tcb->m_ssThresh);
    }
}

/**
 * @brief Try to increase the cWnd following the NewReno specification
 *
 * @see SlowStart
 * @see CongestionAvoidance
 *
 * @param tcb internal congestion state
 * @param segmentsAcked count of segments acked
 */
void
TcpNewReno::IncreaseWindow(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
{
    NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    if (tcb->m_cWnd < tcb->m_ssThresh)
    {
        segmentsAcked = SlowStart(tcb, segmentsAcked);
    }

    if (tcb->m_cWnd >= tcb->m_ssThresh)
    {
        CongestionAvoidance(tcb, segmentsAcked);
    }

    /* At this point, we could have segmentsAcked != 0. This because RFC says
     * that in slow start, we should increase cWnd by min (N, SMSS); if in
     * slow start we receive a cumulative ACK, it counts only for 1 SMSS of
     * increase, wasting the others.
     *
     * // Incorrect assert, I am sorry
     * NS_ASSERT (segmentsAcked == 0);
     */
}

std::string
TcpNewReno::GetName() const
{
    return "TcpNewReno";
}
std::string
TcpRenoJ::GetName() const{
    return "TcpRenoJ";
}
uint32_t
TcpNewReno::GetSsThresh(Ptr<const TcpSocketState> state, uint32_t bytesInFlight)
{
    NS_LOG_FUNCTION(this << state << bytesInFlight);

    return std::max(2 * state->m_segmentSize, bytesInFlight / 2);
}


/*new coe lekhtesi ekhane */

uint32_t
TcpRenoJ::GetSsThresh(Ptr<const TcpSocketState> state, uint32_t bytesInFlight)
{
    NS_LOG_FUNCTION(this << state << bytesInFlight);

    return std::max(2 * state->m_segmentSize, bytesInFlight / 2);

}


Ptr<TcpCongestionOps>
TcpNewReno::Fork()
{
    return CopyObject<TcpNewReno>(this);
}


Ptr<TcpCongestionOps>
TcpRenoJ::Fork()
{
    return CopyObject<TcpRenoJ>(this);
}


} // namespace ns3
