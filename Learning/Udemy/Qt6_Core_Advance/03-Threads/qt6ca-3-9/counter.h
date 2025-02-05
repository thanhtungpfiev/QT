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

#include <QRunnable>

class Counter : public QRunnable
{
public:
    Counter();

    // QRunnable interface
public:
    void run();
};

#endif // COUNTER_H
