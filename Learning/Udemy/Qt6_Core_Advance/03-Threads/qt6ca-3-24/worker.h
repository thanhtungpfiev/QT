/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/5/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename worker.h
 *
 * class Worker
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef WORKER_H
#define WORKER_H

#include <QEventLoop>
#include <QObject>
#include <QTimer>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();
signals:

public slots:
    void start();
    void stop();
    void timeout();

private:
    QTimer timer;
    QEventLoop loop;
};

#endif // WORKER_H
