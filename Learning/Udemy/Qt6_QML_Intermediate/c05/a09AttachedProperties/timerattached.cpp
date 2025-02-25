/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename timerattached.cpp
 *
 * class TimerAttached
 *
 * brief
 *
 *
 *****************************************************************************/
#include "timerattached.h"

TimerAttached::TimerAttached(QObject *parent)
    : QObject{parent}
    , m_timer(new QTimer(this))
    , m_interval(2000)
    , m_running(false)
{
    connect(m_timer, &QTimer::timeout, this, &TimerAttached::timeout);
}

int TimerAttached::interval() const
{
    return m_interval;
}

void TimerAttached::setInterval(int newInterval)
{
    if (m_interval == newInterval)
        return;
    m_interval = newInterval;
    emit intervalChanged();
}

bool TimerAttached::running() const
{
    return m_running;
}

void TimerAttached::setRunning(bool newRunning)
{
    if (m_running == newRunning)
        return;
    m_running = newRunning;
    if (!m_running) {
        m_timer->stop();
    } else {
        m_timer->start(m_interval);
    }
    emit runningChanged();
}
