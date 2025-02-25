/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename player.cpp
 *
 * class Player
 *
 * brief
 *
 *
 *****************************************************************************/
#include "player.h"

Player::Player(QObject *parent)
    : QObject{parent}
{}

QString Player::name() const
{
    return m_name;
}

void Player::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

bool Player::playing() const
{
    return m_playing;
}

void Player::setPlaying(bool newPlaying)
{
    if (m_playing == newPlaying)
        return;
    m_playing = newPlaying;
    emit playingChanged();
}

QString Player::position() const
{
    return m_position;
}

void Player::setPosition(const QString &newPosition)
{
    if (m_position == newPosition)
        return;
    m_position = newPosition;
    emit positionChanged();
}

PlayerDetails *Player::details()
{
    return &m_details;
}
