/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename counting.h
 *
 * class Counting
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef COUNTING_H
#define COUNTING_H

#include <QObject>
#include <QtQml>

class Counting : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Can't do this")
public:
    explicit Counting(QObject *parent = nullptr);
    enum CountDirection { UP, DOWN };
    Q_ENUM(CountDirection)

signals:
};

#endif // COUNTING_H
