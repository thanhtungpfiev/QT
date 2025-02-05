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
    Signals and slots across threads

    Why
    Some minor complications

    How
    Qt Signal Types

*/
#include <QCoreApplication>
#include <QThreadPool>
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget *producer = new Widget();
    Widget *consumer = new Widget();

    producer->setObjectName("Producer");
    consumer->setObjectName("Consumer");
    producer->setIsSender(true);
    consumer->setIsSender(false);
    producer->setAutoDelete(true);
    consumer->setAutoDelete(true);

    QObject::connect(producer, &Widget::started, consumer, &Widget::workStarted);
    QObject::connect(producer, &Widget::update, consumer, &Widget::workReady);
    QObject::connect(producer, &Widget::finished, consumer, &Widget::workFinished);

    QThreadPool::globalInstance()->start(producer);
    QThreadPool::globalInstance()->start(consumer);

    return a.exec();
}
