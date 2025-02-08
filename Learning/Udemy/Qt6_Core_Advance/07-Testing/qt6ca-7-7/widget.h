/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename widget.h
 *
 * class Widget
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>

class Widget : public QObject
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void testFor();
    void testForEach();
    void testString();
    void testComp();
};

#endif // WIDGET_H
