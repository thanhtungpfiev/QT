/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/21/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cppworker.h
 *
 * class CppWorker
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef CPPWORKER_H
#define CPPWORKER_H

#include <QObject>

class CppWorker : public QObject
{
    Q_OBJECT
public:
    explicit CppWorker(QObject *parent = nullptr);

    Q_INVOKABLE void regularMethod();
    Q_INVOKABLE QString regularMethodWithReturn(QString name, int age);

signals:

public slots:
    void cppSlot();
};

#endif // CPPWORKER_H
