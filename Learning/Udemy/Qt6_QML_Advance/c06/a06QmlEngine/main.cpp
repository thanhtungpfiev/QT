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
#include <QQmlProperty>
#include <QQuickItem>

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
    engine.loadFromModule("a06QmlEngine", "Main");

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QObject *rootObject = engine.rootObjects().first();

    //Show item count
    qDebug() << "Item count : " << rootObject->children().count();
    qDebug() << "Object name : " << rootObject->objectName();

    //Find the rectangles
    QList<QQuickItem *> list = rootObject->findChildren<QQuickItem *>("rect");
    if (list.count() > 0) {
        qDebug() << "Rectangle count " << list.count();
        foreach (QQuickItem *item, list) {
            qDebug() << "-----------ITEM-------------";
            qDebug() << "The color is : " << item->property("color").toString();

            QVariant varColor = item->property("color");

            QColor color = varColor.value<QColor>();

            qDebug() << "The color components : " << color.red() << " " << color.green() << " "
                     << color.blue();

            if (color.green() > 0) {
                item->setProperty("radius", 30);
            }
            if (color.blue() > 0) {
                item->setProperty("height", 200);
            }
        }
    }

    //Find Text Area
    QQuickItem *quickItem = rootObject->findChild<QQuickItem *>("myTextArea");
    quickItem->setProperty("text", "Text from C++");

    return app.exec();
}
