/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename manager.cpp
 *
 * class Manager
 *
 * brief
 *
 *
 *****************************************************************************/
#include "manager.h"
#include <QDebug>
#include <QThread>
#include "counter.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    for (int i = 0; i < 5; i++) {
        QThread *thread = new QThread(this);
        thread->setObjectName("Thread " + QString::number(i));
        qInfo() << "Created: " << thread->objectName();
        connect(thread, &QThread::started, this, &Manager::started);
        connect(thread, &QThread::finished, this, &Manager::finished);
        threads.append(thread);
    }
}

void Manager::start()
{
    qInfo() << "Starting...";
    foreach (QThread *thread, threads) {
        qInfo() << "Starting: " << thread->objectName();
        Counter *c = new Counter();
        c->moveToThread(thread);
        connect(thread, &QThread::started, c, &Counter::start);
        thread->start();
    }
}

void Manager::started()
{
    qInfo() << "Starting" << sender();
    QThread *thread = qobject_cast<QThread *>(sender());
    if (!thread)
        return;
    qInfo() << "Started: " << thread->objectName();
}

void Manager::finished()
{
    qInfo() << "Finishing" << sender();
    QThread *thread = qobject_cast<QThread *>(sender());
    if (!thread)
        return;
    qInfo() << "Children" << thread->children().length();
    qInfo() << "Finished: " << thread->objectName();

    threads.removeAll(thread);
    delete thread;
}
