/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename timerattached.h
 *
 * class TimerAttached
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef TIMERATTACHED_H
#define TIMERATTACHED_H

#include <QObject>
#include <QTimer>
#include <QtQml>

class TimerAttached : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Can't create an object of TimerAttached")
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged FINAL)
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged FINAL)
public:
    explicit TimerAttached(QObject *parent = nullptr);

    int interval() const;
    void setInterval(int newInterval);

    bool running() const;
    void setRunning(bool newRunning);

signals:
    void intervalChanged();

    void runningChanged();

    void timeout();

private:
    int m_interval;
    bool m_running;
    QTimer *m_timer;
};

#endif // TIMERATTACHED_H
