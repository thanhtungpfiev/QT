/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
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

#include <QObject>
#include <QTimer>
#include <QtQml>
#include "counting.h"

class Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(
        Counting::CountDirection counting READ counting WRITE setCounting NOTIFY countingChanged)
public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;
    void setCount(int newCount);

    Counting::CountDirection counting() const;
    void setCounting(const Counting::CountDirection &newCounting);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void countChanged();

    void countingChanged();

private:
    int m_count;
    Counting::CountDirection m_counting;
    QTimer *m_timer;
};

#endif // COUNTER_H
