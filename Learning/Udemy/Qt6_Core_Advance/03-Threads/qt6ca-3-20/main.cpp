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
  Returning values

  Why
  We want to get the result

  How
  Future results

*/

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>

int multiply(const int &value)
{
    qInfo() << "Called: " << value;
    int num = value * 10;
    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for (int i = 0; i < 100; i++) {
        list.append(i);
    }

    QFutureWatcher<int> watcher;
    QFuture<int> future = QtConcurrent::mapped(list, &multiply);
    watcher.setFuture(future);

    //Set signals and slots here

    qInfo() << "Back in main!";

    //Do other things with the watcher if needed
    watcher.waitForFinished();

    qInfo() << "Done";
    qInfo() << future.results();

    return a.exec();
}
