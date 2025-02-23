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
#include "movie.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Movie movie;
    movie.setTitle("Titanic");
    movie.setMainCharacter("Leonardo D");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Movie", &movie);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("a05QPropertyMapping", "Main");

    return app.exec();
}
