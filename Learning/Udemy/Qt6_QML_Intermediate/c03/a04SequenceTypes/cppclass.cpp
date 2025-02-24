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
{
    mVector.append("One");
    mVector.append("Two");
    mVector.append("Three");
    mVector.append("Four");
}

void CppClass::qmlArrayToCpp(QVector<QString> vector)
{
    foreach (QString string, vector) {
        qDebug() << string;
    }
}

QVector<QString> CppClass::retrieveStrings()
{
    return mVector;
}
