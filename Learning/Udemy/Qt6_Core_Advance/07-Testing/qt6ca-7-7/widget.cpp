/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename widget.cpp
 *
 * class Widget
 *
 * brief
 *
 *
 *****************************************************************************/
#include "widget.h"
#include <QDebug>
#include <QTest>

Widget::Widget(QObject *parent)
    : QObject(parent)
{}

void Widget::testFor()
{
    QVector<int> list;
    list.fill(0, 100);

    //Called multiple times!
    QBENCHMARK
    {
        for (int i = 0; i < list.size(); i++) {
            //Do Stuff
        }
    }
}

void Widget::testForEach()
{
    QVector<int> list;
    list.fill(0, 100);

    //Called multiple times!
    QBENCHMARK
    {
        foreach (int value, list) {
            //Do Stuff
        }
    }
}

void Widget::testString()
{
    QString him = "Bryan";
    QString her = "Tammy";

    QBENCHMARK
    {
        int ret = him.compare(her);
    }
}

void Widget::testComp()
{
    QString him = "Bryan";
    QString her = "Tammy";

    QBENCHMARK
    {
        QCOMPARE(him, her);
    }
}
