/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/6/2025
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
  Make a library

  Why
  We want to see how

  How
  CMake add sub dirs

*/

#include <QCoreApplication>
#include "../mylib/mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Hello from my app";

    Mylib lib;
    lib.test();

    return a.exec();
}
