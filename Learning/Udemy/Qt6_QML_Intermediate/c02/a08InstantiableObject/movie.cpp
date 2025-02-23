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
    : QObject(parent)
    , m_title("Movie Title")
    , m_mainCharacter("Main Character")
{
    qDebug() << "Creating Movie object...";
}

QString Movie::mainCharacter() const
{
    qDebug() << "Getting the main character";
    return m_mainCharacter;
}

void Movie::setMainCharacter(QString mainCharacter)
{
    qDebug() << "Setting the main character";
    if (m_mainCharacter == mainCharacter)
        return;

    m_mainCharacter = mainCharacter;
    emit mainCharacterChanged(m_mainCharacter);
}

QString Movie::title() const
{
    qDebug() << "Getting the title";
    return m_title;
}

void Movie::setTitle(QString title)
{
    qDebug() << "Setting the title";
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}
