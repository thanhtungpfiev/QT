/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename %{Cpp:License:FileName}
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 *****************************************************************************/
/*

  What
  Wait conditions

  Why
  Sync threads

  How
  QWaitCondition

 */

#include <QCoreApplication>
#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include "consumer.h"
#include "producer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWaitCondition valueReady;
    QMutex mutex;
    QThread producerThread;
    QThread consumerThread;
    int value = 0;

    Producer *producer = new Producer(&mutex, &valueReady, &value);
    Consumer *consumer = new Consumer(&mutex, &valueReady, &value);

    producer->moveToThread(&producerThread);
    consumer->moveToThread(&consumerThread);

    QObject::connect(&producerThread, &QThread::started, producer, &Producer::run);
    QObject::connect(&consumerThread, &QThread::started, consumer, &Consumer::run);

    producerThread.start();
    consumerThread.start();

    return a.exec();
}
