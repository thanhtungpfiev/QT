/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
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
#include <QQuickStyle>
#include "person.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QList<QObject *> personList;
    personList.append(new Person("John Doe C++", "green", 32, &engine));
    personList.append(new Person("Mary Green", "blue", 23, &engine));
    personList.append(new Person("Mitch Nathson", "dodgerblue", 30, &engine));
    personList.append(new Person("Daniel Sten", "red", 67, &engine));
    personList.append(new Person("John Doe C++", "green", 32, &engine));
    personList.append(new Person("Mary Green", "blue", 23, &engine));
    personList.append(new Person("Mitch Nathson", "dodgerblue", 30, &engine));
    personList.append(new Person("Daniel Sten", "red", 67, &engine));
    personList.append(new Person("John Doe C++", "green", 32, &engine));
    personList.append(new Person("Mary Green", "blue", 23, &engine));
    personList.append(new Person("Mitch Nathson", "dodgerblue", 30, &engine));
    personList.append(new Person("Daniel Sten", "red", 67, &engine));
    personList.append(new Person("John Doe C++", "green", 32, &engine));
    personList.append(new Person("Mary Green", "blue", 23, &engine));
    personList.append(new Person("Mitch Nathson", "dodgerblue", 30, &engine));
    personList.append(new Person("Daniel Sten", "red", 67, &engine));

    //Expose the list as a context property
    engine.rootContext()->setContextProperty("personModel", QVariant::fromValue(personList));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("a03ObjectListModel", "Main");

    return app.exec();
}
