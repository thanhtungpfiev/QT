/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cppclass.cpp
 *
 * class CppClass
 *
 * brief
 *
 *
 *****************************************************************************/
#include "cppclass.h"

CppClass::CppClass(QObject *parent)
    : QObject(parent)
{}

void CppClass::cppSlot()
{
    qDebug() << "C++ here, cppSlot called";
    emit sendDateTime(QDateTime::currentDateTime());
    emit sendTime(QTime::currentTime());
}

void CppClass::timeSlot(QTime time)
{
    qDebug() << "Time from QML is :" << time;
}

void CppClass::dateTimeSlot(QDateTime datetime)
{
    qDebug() << "DateTime from QML is :" << datetime;
}
