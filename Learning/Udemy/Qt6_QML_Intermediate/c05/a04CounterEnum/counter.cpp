/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename counter.cpp
 *
 * class Counter
 *
 * brief
 *
 *
 *****************************************************************************/
#include "counter.h"

Counter::Counter(QObject *parent)
    : QObject{parent}
    , m_count(0)
    , m_counting(Counting::CountDirection::UP)
    , m_timer(new QTimer(this))
{
    m_timer->setInterval(500);
    connect(m_timer, &QTimer::timeout, [=]() {
        int count = m_count;
        if (m_counting == Counting::CountDirection::UP) {
            setCount(++count);
        } else {
            setCount(--count);
        }
    });
}

int Counter::count() const
{
    return m_count;
}

void Counter::setCount(int newCount)
{
    if (m_count == newCount)
        return;
    m_count = newCount;
    emit countChanged();
}

Counting::CountDirection Counter::counting() const
{
    return m_counting;
}

void Counter::setCounting(const Counting::CountDirection &newCounting)
{
    if (m_counting == newCounting)
        return;
    m_counting = newCounting;
    emit countingChanged();
}

void Counter::start()
{
    m_timer->start();
}

void Counter::stop()
{
    m_timer->stop();
}
