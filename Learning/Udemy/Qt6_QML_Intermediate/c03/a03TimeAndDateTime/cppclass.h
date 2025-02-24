/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cppclass.h
 *
 * class CppClass
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QDateTime>
#include <QObject>
#include <QTime>
#include <QtQml>

class CppClass : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit CppClass(QObject *parent = nullptr);

signals:
    void sendDateTime(QDateTime datetimeparam);
    void sendTime(QTime timeparam);

public slots:
    void cppSlot();
    void timeSlot(QTime time);
    void dateTimeSlot(QDateTime datetime);
};

#endif // CPPCLASS_H
