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
  Mutex

  Why
  We want to protect an object from thread issues

  How
  QMutex

  Two threads updating the same thing at the same time

 */
#include <QCoreApplication>
#include <QDebug>
#include <QMutex>
#include <QThread>
#include <QThreadPool>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main");
    QThreadPool *pool = QThreadPool::globalInstance();

    qInfo() << "Max threads: " << pool->maxThreadCount();
    QMutex mutex;
    int value = 0;

    for (int i = 0; i < 100; ++i) {
        Counter *c = new Counter(&mutex, &value);
        c->setAutoDelete(true);
        pool->start(c);
    }

    return a.exec();
}
