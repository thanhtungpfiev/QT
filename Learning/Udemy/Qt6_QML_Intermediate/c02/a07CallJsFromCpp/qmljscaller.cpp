/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename qmljscaller.cpp
 *
 * class QmlJSCaller
 *
 * brief
 *
 *
 *****************************************************************************/
#include "qmljscaller.h"
#include <QDebug>
#include <QVariant>

QmlJSCaller::QmlJSCaller(QObject *parent)
    : QObject{parent}
{}

void QmlJSCaller::cppMethod(QString parameter)
{
    qDebug() << "This is C++ talking, calling QML Javascript function";
    callJSMethod(parameter);
}

void QmlJSCaller::setQmlRootObject(QObject *value)
{
    qmlRootObject = value;
}

void QmlJSCaller::callJSMethod(QString param)
{
    QVariant returnedValue;
    QVariant cppParameter = QVariant::fromValue(param);

    QMetaObject::invokeMethod(qmlRootObject,
                              "qmlJSFunction",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, cppParameter));

    qDebug() << "C++ talking, done calling QML Javascript, the return value is: "
             << returnedValue.toString();
}
