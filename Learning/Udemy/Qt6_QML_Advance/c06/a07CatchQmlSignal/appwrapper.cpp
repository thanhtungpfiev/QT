/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename appwrapper.cpp
 *
 * class AppWrapper
 *
 * brief
 *
 *
 *****************************************************************************/
#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent)
    : QObject{parent}
{}

bool AppWrapper::initialize(QGuiApplication &app)
{
    QObject::connect(
        &mEngine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    mEngine.loadFromModule("a07CatchQmlSignal", "Main");

    if (mEngine.rootObjects().isEmpty())
        return false;

    QObject *rootObject
        = mEngine.rootObjects()[0]; // The object that contains the signal on the QML side.
    connect(rootObject,
            SIGNAL(qmlSignal(QString, QVariant)),
            this,
            SLOT(respondToClick(QString, QVariant)));

    return true;
}

void AppWrapper::respondToClick(QString msg, const QVariant &object)
{
    qDebug() << "The message is : " << msg;

    QObject *mObject = object.value<QObject *>();

    qDebug() << "The property is : " << mObject->property("mProp").toString();
}
