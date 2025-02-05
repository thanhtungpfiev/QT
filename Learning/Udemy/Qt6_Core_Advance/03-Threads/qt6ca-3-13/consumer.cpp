/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename customer.cpp
 *
 * class Consumer
 *
 * brief
 *
 *
 *****************************************************************************/
#include "consumer.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QThread>

Consumer::Consumer(QMutex *mutex, QWaitCondition *valueReady, int *value, QObject *parent)
    : QObject{parent}
{
    m_mutex = mutex;
    m_valueReady = valueReady;
    m_value = value;
}

void Consumer::run()
{
    qInfo() << "Consumer running";
    m_mutex->lock();
    qInfo() << "Consumer locked the mutex";
    if (*m_value == 0) {
        qInfo() << "Consumer is waiting on a value";
        m_valueReady->wait(m_mutex);
    }
    qInfo() << "Consuming: " << *m_value;
}
