/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename movie.cpp
 *
 * class Movie
 *
 * brief
 *
 *
 *****************************************************************************/
#include "movie.h"

Movie::Movie(QObject *parent)
    : QObject{parent}
{}

QString Movie::title() const
{
    return m_title;
}

void Movie::setTitle(const QString &newTitle)
{
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}

QString Movie::mainCharacter() const
{
    return m_mainCharacter;
}

void Movie::setMainCharacter(const QString &newMainCharacter)
{
    if (m_mainCharacter == newMainCharacter)
        return;
    m_mainCharacter = newMainCharacter;
    emit mainCharacterChanged();
}
