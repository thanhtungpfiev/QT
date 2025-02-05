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
  Sync future values

  Why
  We want values in the future in a specific order

  How
  QFutureSynchronizer

*/

#include <QCoreApplication>
#include <QtConcurrent>

void dostuff(int value)
{
    for (int i = 0; i < 10; i++) {
        QThread::currentThread()->msleep(100);
        qInfo() << "Thread: " << value << " = " << i;
    }
}

void runthread()
{
    QFutureSynchronizer<void> sync;
    for (int i = 0; i < 3; i++) {
        QFuture<void> f = QtConcurrent::run(&dostuff, i);
        sync.addFuture(f);
    }

    //sync.waitForFinished();
    //waitForFinished called in the QFutureSynchronizer deconstructor
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    runthread();
    qInfo() << "Done";

    return a.exec();
}
