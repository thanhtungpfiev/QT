/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename defender.cpp
 *
 * class Defender
 *
 * brief
 *
 *
 *****************************************************************************/
#include "defender.h"

Defender::Defender(QObject *parent)
    : Player{parent}
{}

void Defender::play()
{
    qDebug() << name() << " is playing";
}

void Defender::defend()
{
    qDebug() << name() << " is defending";
}
