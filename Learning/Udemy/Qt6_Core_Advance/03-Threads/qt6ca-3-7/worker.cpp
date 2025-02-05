/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/3/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename worker.cpp
 *
 * class Worker
 *
 * brief
 *
 *
 *****************************************************************************/
#include "worker.h"
#include <QDebug>
#include <QThread>

Worker::Worker(QObject *parent)
    : QObject{parent}
{}

void Worker::work()
{
    for (int i = 0; i < 10; i++) {
        qInfo() << "Work" << i << QThread::currentThread();
        QThread::currentThread()->msleep(1000);
    }
}
