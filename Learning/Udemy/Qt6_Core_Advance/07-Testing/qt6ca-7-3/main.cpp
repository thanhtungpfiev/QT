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
  Lets test

  Why
  To see how it works

  How
  Example

 */

#include <QCoreApplication>
#include <QTest>
#include "cat.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat cat;
#ifdef QT_DEBUG
    QTest::qExec(&cat);
#endif
    return a.exec();
    return a.exec();
}
