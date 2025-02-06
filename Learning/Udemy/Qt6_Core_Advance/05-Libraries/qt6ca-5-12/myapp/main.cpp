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
  Use an static lib

  Why
  We want to link the lib directly into our binary

  How
  Build the lib in static
  Explain the ".a" file
  Copy it to /lib
  Copy the includes to the /inc
  Modify CMakeLists.txt

  ldd = linux
  otool -l   = mac

*/

#include <QCoreApplication>
#include "inc/mylib/mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mylib lib;
    lib.test();

    return a.exec();
}
