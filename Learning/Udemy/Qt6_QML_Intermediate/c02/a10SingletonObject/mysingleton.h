/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename mysingleton.h
 *
 * class MySingleton
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <QDebug>
#include <QObject>
#include <QtQml>

class MySingleton : public QObject
{
    Q_OBJECT
    // QML_SINGLETON
    // QML_ELEMENT
public:
    explicit MySingleton(QObject *parent = nullptr);

    // Invokable methods
    Q_INVOKABLE void doSomething() const { qDebug() << "Doing something..."; }

signals:
};

#endif // MYSINGLETON_H
