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
#include "mysingleton.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MySingleton *singleton = new MySingleton(&app);
    qmlRegisterSingletonInstance("guide.learnqt.Singletons", 1, 0, "MySingleton", singleton);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("a10SingletonObject", "Main");

    return app.exec();
}
