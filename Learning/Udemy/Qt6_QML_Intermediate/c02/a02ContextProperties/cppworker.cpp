/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/21/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cppworker.cpp
 *
 * class CppWorker
 *
 * brief
 *
 *
 *****************************************************************************/
#include "cppworker.h"
#include <QDebug>

CppWorker::CppWorker(QObject *parent)
    : QObject{parent}
{}

void CppWorker::regularMethod()
{
    qDebug() << "This is C++ talking, regularMethod called.";
}

QString CppWorker::regularMethodWithReturn(QString name, int age)
{
    qDebug() << "This is C++ talking, name: " << name << ", age: " << age;
    return QString(name + ":" + QString::number(age) + " years old");
}

void CppWorker::cppSlot()
{
    qDebug() << "This is C++ talking, cppSlot called";
}
