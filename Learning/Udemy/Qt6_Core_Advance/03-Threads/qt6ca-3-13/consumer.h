/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename customer.h
 *
 * class Consumer
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef CONSUMER_H
#define CONSUMER_H

#include <QMutex>
#include <QObject>
#include <QWaitCondition>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QMutex *mutex,
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

#endif // CONSUMER_H
