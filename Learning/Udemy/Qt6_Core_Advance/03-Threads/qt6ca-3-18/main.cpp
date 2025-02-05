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
  Qt Concurrent issues

  Why
  We live in the real world
  Its great, but we lose a lot of control

  How
  Example code: we have to use Futures to get values back

*/
#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>

void test(QString name, int max)
{
    for (int i = 0; i < max; i++) {
        qInfo() << name << i << QThread::currentThread();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString name = "name";

    QFuture<void> future = QtConcurrent::run(test, name, 5);
    qInfo() << "Do stuff here";

    future.waitForFinished();
    qInfo() << "Done";

    return a.exec();
}
