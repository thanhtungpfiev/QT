/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename counter.h
 *
 * class Counter
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef COUNTER_H
#define COUNTER_H

#include <QMutex>
#include <QRunnable>

class Counter : public QRunnable
{
public:
    Counter(QMutex *mutex, int *value);

    // QRunnable interface
public:
    void run();

private:
    int *m_value;
    QMutex *m_mutex;
};

#endif // COUNTER_H
