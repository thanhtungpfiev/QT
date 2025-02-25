/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename footballteam.h
 *
 * class FootballTeam
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef FOOTBALLTEAM_H
#define FOOTBALLTEAM_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include "player.h"

class FootballTeam : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString coach READ coach WRITE setCoach NOTIFY coachChanged)
    Q_PROPERTY(Player *captain READ captain WRITE setCaptain NOTIFY captainChanged)
    Q_PROPERTY(QQmlListProperty<Player> players READ players NOTIFY playersChanged)
public:
    explicit FootballTeam(QObject *parent = nullptr);

    QString title() const;
    void setTitle(const QString &newTitle);

    QString coach() const;
    void setCoach(const QString &newCoach);

    Player *captain() const;
    void setCaptain(Player *newCaptain);

    QQmlListProperty<Player> players();

    //Helper methods
    void appendPlayerCustom(Player *);
    int playerCountCustom() const;
    Player *playerCustom(int) const;
    void clearPlayersCustom();

signals:
    void titleChanged();

    void coachChanged();

    void captainChanged();

    void playersChanged();

private:
    QString m_title;
    QString m_coach;
    Player *m_captain = nullptr;
    QVector<Player *> m_players;

    //Callback methods
    static void appendPlayer(QQmlListProperty<Player> *, Player *);
    static qsizetype playerCount(QQmlListProperty<Player> *);
    static Player *player(QQmlListProperty<Player> *, qsizetype);
    static void clearPlayers(QQmlListProperty<Player> *);
};

#endif // FOOTBALLTEAM_H
