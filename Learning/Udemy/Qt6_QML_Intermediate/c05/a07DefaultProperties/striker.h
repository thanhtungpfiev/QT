/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename striker.h
 *
 * class Striker
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef STRIKER_H
#define STRIKER_H

#include <QObject>
#include "player.h"

class Striker : public Player
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Striker(QObject *parent = nullptr);

signals:

    // Player interface
public:
    void play() override;
    void strike();
};

#endif // STRIKER_H
