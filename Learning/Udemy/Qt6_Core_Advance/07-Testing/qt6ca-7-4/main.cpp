/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
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
  Basic testing

  Why
  Lets look deeper at testing

  How
  Example code

 */

#include <QCoreApplication>
#include <QTest>
#include "dog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Dog dog;
    QTest::qExec(&dog);

    return a.exec();
}
