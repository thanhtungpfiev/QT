/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename randomnumber.cpp
 *
 * class RandomNumber
 *
 * brief
 *
 *
 *****************************************************************************/
#include "randomnumber.h"

RandomNumber::RandomNumber(QObject *parent)
    : QObject{parent}
    , m_maxValue(100)
    , m_timer(new QTimer(this))
{
    connect(m_timer, &QTimer::timeout, this, &RandomNumber::updateProperty);
    m_timer->start(500);
}

int RandomNumber::maxValue() const
{
    return m_maxValue;
}

void RandomNumber::setMaxValue(int newMaxValue)
{
    if (m_maxValue == newMaxValue)
        return;
    m_maxValue = newMaxValue;
    emit maxValueChanged();
}

void RandomNumber::setTarget(const QQmlProperty &prop)
{
    m_targetProperty = prop;
}

void RandomNumber::updateProperty()
{
    m_targetProperty.write(QRandomGenerator::global()->bounded(m_maxValue));
}
