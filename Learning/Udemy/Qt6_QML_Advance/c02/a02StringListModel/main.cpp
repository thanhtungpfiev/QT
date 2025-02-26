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

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QStringList continentList;
    continentList.append("Africa");
    continentList.append("Europe");
    continentList.append("America");
    continentList.append("Asia");
    continentList.append("Oceania");
    continentList.append("Antarctica");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("continentModel", continentList);

    engine.rootContext()->setContextProperties(
        QList<QQmlContext::PropertyPair>{{"itemList1",
                                          QStringList{"List1Item1", "List1Item2", "List1Item3"}},
                                         {"itemList2",
                                          QStringList{"List2Item1", "List2Item2", "List2Item3"}}});
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("a02StringListModel", "Main");

    return app.exec();
}
