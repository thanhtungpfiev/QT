/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename manager.h
 *
 * class Manager
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void start();

signals:

public slots:
    void started();
    void finished();

private:
    QList<QThread *> threads;
};

#endif // MANAGER_H
