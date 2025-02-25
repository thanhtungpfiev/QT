/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename footballteam.cpp
 *
 * class FootballTeam
 *
 * brief
 *
 *
 *****************************************************************************/
#include "footballteam.h"

FootballTeam::FootballTeam(QObject *parent)
    : QObject{parent}
{}

QString FootballTeam::title() const
{
    return m_title;
}

void FootballTeam::setTitle(const QString &newTitle)
{
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}

QString FootballTeam::coach() const
{
    return m_coach;
}

void FootballTeam::setCoach(const QString &newCoach)
{
    if (m_coach == newCoach)
        return;
    m_coach = newCoach;
    emit coachChanged();
}

Player *FootballTeam::captain() const
{
    return m_captain;
}

void FootballTeam::setCaptain(Player *newCaptain)
{
    if (m_captain == newCaptain)
        return;
    m_captain = newCaptain;
    emit captainChanged();
}

QQmlListProperty<Player> FootballTeam::players()
{
    return QQmlListProperty<Player>(this,
                                    this,
                                    &FootballTeam::appendPlayer,
                                    &FootballTeam::playerCount,
                                    &FootballTeam::player,
                                    &FootballTeam::clearPlayers);
}

void FootballTeam::appendPlayerCustom(Player *player)
{
    qDebug() << "Adding player to vector" << player->name();
    m_players.append(player);
}

int FootballTeam::playerCountCustom() const
{
    return m_players.count();
}

Player *FootballTeam::playerCustom(int index) const
{
    return m_players.at(index);
}

void FootballTeam::clearPlayersCustom()
{
    m_players.clear();
}

void FootballTeam::appendPlayer(QQmlListProperty<Player> *list, Player *player)
{
    reinterpret_cast<FootballTeam *>(list->data)->appendPlayerCustom(player);
}

qsizetype FootballTeam::playerCount(QQmlListProperty<Player> *list)
{
    return reinterpret_cast<FootballTeam *>(list->data)->playerCountCustom();
}

Player *FootballTeam::player(QQmlListProperty<Player> *list, qsizetype index)
{
    return reinterpret_cast<FootballTeam *>(list->data)->playerCustom(index);
}

void FootballTeam::clearPlayers(QQmlListProperty<Player> *list)
{
    reinterpret_cast<FootballTeam *>(list->data)->clearPlayersCustom();
}
