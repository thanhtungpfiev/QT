/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename dog.cpp
 *
 * class Dog
 *
 * brief
 *
 *
 *****************************************************************************/
#include "dog.h"
#include <QDebug>

Dog::Dog(QObject *parent)
    : QObject(parent)
{
    qInfo() << "Constructor";
}

void Dog::initTestCase()
{
    qInfo() << "initTestCase";
}

void Dog::init()
{
    qInfo() << "init";
}

void Dog::cleanup()
{
    qInfo() << "cleanup";
}

void Dog::cleanupTestCase()
{
    qInfo() << "cleanupTestCase";
}

void Dog::bark()
{
    qInfo() << "bark bark bark";
}

void Dog::rollover()
{
    qInfo() << "*rolls*";
}
