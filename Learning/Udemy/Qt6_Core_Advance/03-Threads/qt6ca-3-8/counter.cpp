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

Counter::Counter(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed";
}

Counter::~Counter()
{
    qInfo() << this << "Destructed";
}

void Counter::start()
{
    qInfo() << this << "Started";
    for (int i = 0; i < 20; i++) {
        qInfo() << QThread::currentThread()->objectName() << " = " << i;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(500));
        QThread::currentThread()->msleep(value);
        qInfo() << QThread::currentThread()->objectName() << " Complete";
    }
    qInfo() << this << "Completed";
    deleteLater();

    QThread::currentThread()->quit();
}
