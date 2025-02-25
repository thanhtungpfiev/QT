/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename timer.cpp
 *
 * class Timer
 *
 * brief
 *
 *
 *****************************************************************************/
#include "timer.h"

Timer::Timer(QObject *parent)
    : QObject{parent}
{}

TimerAttached *Timer::qmlAttachedProperties(QObject *object)
{
    return new TimerAttached(object);
}
