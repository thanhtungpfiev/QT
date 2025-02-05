/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/5/2025
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
    : QObject{parent}
{}

void Test::finished()
{
    // When Qt Concurent is done
    qInfo() << this << "Processing...";
}
