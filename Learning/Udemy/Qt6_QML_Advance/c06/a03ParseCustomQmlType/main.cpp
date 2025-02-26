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
#include <QCoreApplication>
#include <QQmlComponent>
#include <QQmlEngine>
#include "footballteam.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Register Types
    qmlRegisterType<Player>("com.blikoon.Football", 1, 0, "Player");
    qmlRegisterType<FootBallTeam>("com.blikoon.Football", 1, 0, "FootballTeam");

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/qml/main.qml"));

    FootBallTeam *team = qobject_cast<FootBallTeam *>(
        component.create()); // FootBallTeam is the root element in the QML file

    if (team && team->captain()) {
        qDebug() << "Team : " << team->title() << " , captain is : " << team->captain()->name();
        qDebug() << "The players are : ";

        for (int i = 0; i < team->playerCountCustom(); i++) {
            qDebug() << " " << team->playerCustom(i)->name();
        }
    }

    return a.exec();
}
