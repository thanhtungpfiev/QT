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
  Testing for failure

  Why
  This is the reason for testing

  How
  QFAIL QVERIFY QCOMPARE QWARN

*/

#include <QCoreApplication>
#include <QTest>
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget widget;
    widget.setAge(46);
    QTest::qExec(&widget);
    return a.exec();
}
