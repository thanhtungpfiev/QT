/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename %{Cpp:License:FileName}
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 *****************************************************************************/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qmljscaller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlJSCaller caller;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("QmlJsCaller", &caller);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("a07CallJsFromCpp", "Main");

    auto rootObjects = engine.rootObjects();
    if (engine.rootObjects().isEmpty()) {
        return -1;
    } else {
        caller.setQmlRootObject(rootObjects[0]);
    }

    return app.exec();
}
