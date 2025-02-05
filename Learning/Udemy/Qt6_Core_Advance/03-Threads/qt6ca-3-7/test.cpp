/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/3/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename test.cpp
 *
 * class Test
 *
 * brief
 *
 *
 *****************************************************************************/
#include "test.h"
#include <QDebug>

Test::Test(QObject *parent)
    : QThread{parent}
{}

void Test::run()
{
    m_timer.singleShot(3000, this, &Test::test);
    // test();
}

void Test::test()
{
    qInfo() << "TESTING" << currentThread();

    terminate();
}
