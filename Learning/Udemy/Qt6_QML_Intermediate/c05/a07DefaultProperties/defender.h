/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename defender.h
 *
 * class Defender
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef DEFENDER_H
#define DEFENDER_H

#include <QObject>
#include "player.h"

class Defender : public Player
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Defender(QObject *parent = nullptr);

signals:

    // Player interface
public:
    void play() override;
    void defend();
};

#endif // DEFENDER_H
