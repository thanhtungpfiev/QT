/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cppsignalsender.h
 *
 * class CppSignalSender
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef CPPSIGNALSENDER_H
#define CPPSIGNALSENDER_H

#include <QObject>
#include <QTimer>

class CppSignalSender : public QObject
{
    Q_OBJECT
public:
    explicit CppSignalSender(QObject *parent = nullptr);

signals:
    void callQml(QString parameter);
    void cppTimer(QString value);

public slots:
    void cppSlot();

private:
    QTimer m_timer;
    int m_value;
};

#endif // CPPSIGNALSENDER_H
