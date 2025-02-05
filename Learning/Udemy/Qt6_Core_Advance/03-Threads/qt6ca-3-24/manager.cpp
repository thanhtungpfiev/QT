/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/5/2025
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
#include <QtConcurrent>
#include "worker.h"

Manager::Manager(QObject *parent)
    : QObject(parent)
{}

Manager::~Manager()
{
    quit();
}

void Manager::process()
{
    QFuture<void> value = QtConcurrent::run(Manager::createWorker, this);
}

void Manager::quit()
{
    qInfo() << "Stopping Manager";
    emit stop();
}

void Manager::createWorker(Manager *manager)
{
    qInfo() << "Creating Worker";
    Worker *worker = new Worker();
    connect(manager, &Manager::start, worker, &Worker::start); // Qt::QueuedConnection
    connect(manager, &Manager::stop, worker, &Worker::stop);   // Qt::QueuedConnection
    worker->start();
    // emit start();
}
