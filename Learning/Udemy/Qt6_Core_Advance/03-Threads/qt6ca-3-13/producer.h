/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename producer.h
 *
 * class Producer
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PRODUCER_H
#define PRODUCER_H

#include <QMutex>
#include <QObject>
#include <QWaitCondition>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QMutex *mutex,
                      QWaitCondition *valueReady,
                      int *value,
                      QObject *parent = nullptr);

signals:

public slots:
    void run();

private:
    QMutex *m_mutex;
    QWaitCondition *m_valueReady;
    int *m_value;
};

#endif // PRODUCER_H
