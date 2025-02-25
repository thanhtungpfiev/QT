/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename timer.h
 *
 * class Timer
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QtQml>
#include "timerattached.h"

class Timer : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Timer(QObject *parent = nullptr);
    static TimerAttached *qmlAttachedProperties(QObject *object);

signals:
};
QML_DECLARE_TYPEINFO(Timer, QML_HAS_ATTACHED_PROPERTIES)

#endif // TIMER_H
