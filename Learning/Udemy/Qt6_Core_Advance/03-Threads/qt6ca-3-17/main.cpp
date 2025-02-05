/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/5/2025
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
  QtConcurrent::run

  Why
  Easily run on a thread

  How
  QtConcurrent::run

 */

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>

void loop()
{
    for (int i = 0; i < 10; ++i) {
        qInfo() << "Loop" << i << " on: " << QThread::currentThread();
    }
}

void test()
{
    qInfo() << "Test on: " << QThread::currentThread();
    loop();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main");

    QThreadPool pool;
    QFuture<void> future = QtConcurrent::run(&pool, test);
    qInfo() << "Main on: " << QThread::currentThread();

    return a.exec();
}
