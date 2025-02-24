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

#include <QColor>
#include <QDate>
#include <QFont>
#include <QObject>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QSize>
#include <QSizeF>
#include <QUrl>
#include <QtQml>

class CppClass : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit CppClass(QObject *parent = nullptr);

signals:
    void sentInt(int param);
    void sendDouble(double param);
    void sendBoolRealFloat(bool boolparam, qreal realparam, float floatparam);
    void sendStringUrl(QString stringparam, QUrl urlparam);
    void sendColorFont(QColor colorparam, QFont fontparam);
    void sendDate(QDate dateparam);
    void sendPoint(QPoint pointparam, QPointF pointfparam);
    void sendSize(QSize sizeparam, QSizeF sizefparam);
    void sendRect(QRect rectparam, QRectF rectfparam);

public slots:
    void cppSlot();

    //Recieve data from QML
    void receivePoint(QPoint point);
    void receiveRect(QRect rect);
};

#endif // CPPCLASS_H
