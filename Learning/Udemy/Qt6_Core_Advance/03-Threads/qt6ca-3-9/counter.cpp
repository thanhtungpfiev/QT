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
#include <QRandomGenerator>
#include <QThread>

Counter::Counter() {}

void Counter::run()
{
    qInfo() << "Starting: " << QThread::currentThread();

    for (int i = 0; i < 20; i++) {
        qInfo() << QThread::currentThread() << " = " << i;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(100));
        QThread::currentThread()->msleep(value);
    }

    qInfo() << "Finished: " << QThread::currentThread();
}
