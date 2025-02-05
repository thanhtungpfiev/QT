/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
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
#include <QThread>

Counter::Counter(QMutex *mutex, int *value)
{
    m_mutex = mutex;
    m_value = value;
}

void Counter::run()
{
    m_mutex->lock();
    QThread::currentThread()->msleep(50);
    *m_value = *m_value + 1;
    qInfo() << *m_value << QThread::currentThread();
    m_mutex->unlock();
}
