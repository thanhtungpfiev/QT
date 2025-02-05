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
  Threaded example

  Why
  We want to see a simple example bringing it all together

  How
  Manager controller workers

*/

#include <QCoreApplication>
#include <QTextStream>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Manager manager;
    QTextStream cin(stdin);
    qInfo() << "Type START to begin";
    qInfo() << "Type QUIT to quit";

    do {
        QString command;
        cin >> command;

        if (command.toUpper() == "START")
            manager.process();
        if (command.toUpper() == "QUIT")
            manager.quit();

    } while (true);

    return a.exec();
}
