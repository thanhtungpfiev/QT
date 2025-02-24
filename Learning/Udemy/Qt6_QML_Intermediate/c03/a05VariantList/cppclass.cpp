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
#include <QColor>
#include <QDate>
#include <QDebug>

CppClass::CppClass(QObject *parent)
    : QObject(parent)
    , qmlRootObject(nullptr)
{}

void CppClass::passFromQmlToCpp(QVariantList list, QVariantMap map)
{
    qDebug() << "Received variant list and map from QML";
    qDebug() << "List :";
    for (int i{0}; i < list.size(); i++) {
        qDebug() << "List item :" << list.at(i).toString();
    }

    qDebug() << "Map :";
    for (int i{0}; i < map.keys().size(); i++) {
        qDebug() << "Map item :" << map.keys().at(i) << " " << map[map.keys().at(i)].toString();
    }
}

QVariantList CppClass::getVariantListFromCpp()
{
    QVariantList list;
    list << 123.3 << QColor(Qt::cyan) << "Qt is great" << 10;
    return list;
}

QVariantMap CppClass::getVariantMapFromCpp()
{
    QVariantMap map;
    map.insert("movie", "Game of Thrones");
    map.insert("names", "John Snow");
    map.insert("role", "Main Character");
    map.insert("release", QDate(2011, 4, 17));
    return map;
}

void CppClass::setQmlRootObject(QObject *value)
{
    qmlRootObject = value;
}

void CppClass::triggerJSCall()
{
    qDebug() << "Calling JS";
    QVariantList list; //array
    list << 123.3 << QColor(Qt::cyan) << "Qt is great" << 10;

    QVariantMap map; //object
    map.insert("movie", "Game of Thrones");
    map.insert("names", "John Snow");
    map.insert("role", "Main Character");
    map.insert("release", QDate(2011, 4, 17));

    QMetaObject::invokeMethod(qmlRootObject,
                              "arrayObjectFunc",
                              Q_ARG(QVariant, QVariant::fromValue(list)),
                              Q_ARG(QVariant, QVariant::fromValue(map)));
    qDebug() << "Called JS";
}
