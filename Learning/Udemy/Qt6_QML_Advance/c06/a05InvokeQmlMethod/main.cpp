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

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("a05InvokeQmlMethod", "Main");

    QObject *rootObject = engine.rootObjects()[0];

    QObject *funcContext = rootObject->findChild<QObject *>("deep2");

    if (funcContext) {
        qDebug() << "Found the object";
        QVariant returnValue;
        QVariant parameter = "C++ Parameter";

        QMetaObject::invokeMethod(funcContext,
                                  "qmlFunction",
                                  Q_RETURN_ARG(QVariant, returnValue),
                                  Q_ARG(QVariant, parameter));
        qDebug() << "This is C++, return value is : " << returnValue.toString();
    }

    return app.exec();
}
