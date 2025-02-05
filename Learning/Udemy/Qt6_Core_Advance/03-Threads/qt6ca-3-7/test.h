/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/3/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename test.h
 *
 * class Test
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QThread>
#include <QTimer>

class Test : public QThread
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

    // QThread interface
protected:
    void run();

private:
    void test();
    QTimer m_timer;
};

#endif // TEST_H
