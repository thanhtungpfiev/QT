/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
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

class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
    QML_ELEMENT

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;
    void setCount(int newCount);

    bool up() const;
    void setUp(bool newUp);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void countChanged();

    void upChanged();

private:
    int m_count;
    bool m_up;
    QTimer *m_timer;
};

#endif // COUNTER_H
