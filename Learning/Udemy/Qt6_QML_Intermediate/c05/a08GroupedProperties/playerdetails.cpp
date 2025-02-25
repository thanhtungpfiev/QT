/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename playerdetails.cpp
 *
 * class PlayerDetails
 *
 * brief
 *
 *
 *****************************************************************************/
#include "playerdetails.h"

PlayerDetails::PlayerDetails(QObject *parent)
    : QObject{parent}
{}

qreal PlayerDetails::height() const
{
    return m_height;
}

void PlayerDetails::setHeight(qreal newHeight)
{
    if (qFuzzyCompare(m_height, newHeight))
        return;
    m_height = newHeight;
    emit heightChanged();
}

qreal PlayerDetails::weight() const
{
    return m_weight;
}

void PlayerDetails::setWeight(qreal newWeight)
{
    if (qFuzzyCompare(m_weight, newWeight))
        return;
    m_weight = newWeight;
    emit weightChanged();
}

qreal PlayerDetails::speed() const
{
    return m_speed;
}

void PlayerDetails::setSpeed(qreal newSpeed)
{
    if (qFuzzyCompare(m_speed, newSpeed))
        return;
    m_speed = newSpeed;
    emit speedChanged();
}
