/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
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
#include <QDebug>

Counter::Counter(QObject *parent)
    : QObject{parent}
    , m_count(0)
    , m_up(true)
    , m_timer(new QTimer(this))
{
    qDebug() << "Created counter instance";
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, [=]() {
        int count = m_count;
        if (m_up) {
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

bool Counter::up() const
{
    return m_up;
}

void Counter::setUp(bool newUp)
{
    if (m_up == newUp)
        return;
    m_up = newUp;
    emit upChanged();
}

void Counter::start()
{
    m_timer->start();
}

void Counter::stop()
{
    m_timer->stop();
}
