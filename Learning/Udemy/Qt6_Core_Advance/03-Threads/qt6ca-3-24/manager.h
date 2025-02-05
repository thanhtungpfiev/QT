/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/5/2025
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
    ~Manager();

signals:
    void start();
    void stop();

public slots:
    void process();
    void quit();

private:
    static void createWorker(Manager *manager);
};

#endif // MANAGER_H
