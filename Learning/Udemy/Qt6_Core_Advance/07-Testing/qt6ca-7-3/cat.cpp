/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cat.cpp
 *
 * class Cat
 *
 * brief
 *
 *
 *****************************************************************************/
#include "cat.h"
#include <QDebug>

Cat::Cat(QObject *parent)
    : QObject(parent)
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::public_test()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::test()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::play()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::meow()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::sleep()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::speak(QString value)
{
    Q_UNUSED(value);
    qInfo() << Q_FUNC_INFO;
}

void Cat::private_test()
{
    qInfo() << Q_FUNC_INFO;
}
