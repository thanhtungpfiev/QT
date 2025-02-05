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
    Intro to Qt Concurrent

    Why
    Its very easy
    Removes the complexity of threading
    Baked right into Qt

    How
    QtConcurrent

*/

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>

int do_map(int value)
{
    qInfo() << "Do stuff: " << value;
    int num = value * 10;
    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> values;
    for (int i = 0; i < 9; i++) {
        values << i;
    }

    qInfo() << "Starting...";
    QList<int> updated = QtConcurrent::blockingMapped(values, &do_map);
    qInfo() << "Finished";
    qInfo() << values;
    qInfo() << updated;

    return a.exec();
}
