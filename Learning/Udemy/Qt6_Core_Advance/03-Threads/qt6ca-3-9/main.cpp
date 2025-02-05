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
  Thread Pools

  Why
  We want multiple resuable threads

  How
  QTreadPool and QRunnable

 */

#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main");

    QThreadPool *pool = QThreadPool::globalInstance();
    qInfo() << pool->maxThreadCount() << " Threads";

    for (int i = 0; i < 100; i++) {
        Counter *c = new Counter();
        c->setAutoDelete(true);
        pool->start(c);
    }

    return a.exec();
}
