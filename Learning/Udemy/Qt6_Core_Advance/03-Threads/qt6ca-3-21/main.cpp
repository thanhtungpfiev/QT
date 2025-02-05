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
  Future watcher signals and slots

  Why
  We want to use Qt signals and slots

  How
  QFutureWatcher Slots

*/

#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;
    test.process();

    return a.exec();
}
