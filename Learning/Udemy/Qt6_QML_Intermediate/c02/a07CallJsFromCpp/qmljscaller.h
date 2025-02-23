/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename qmljscaller.h
 *
 * class QmlJSCaller
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef QMLJSCALLER_H
#define QMLJSCALLER_H

#include <QObject>

class QmlJSCaller : public QObject
{
    Q_OBJECT
public:
    explicit QmlJSCaller(QObject *parent = nullptr);

    Q_INVOKABLE void cppMethod(QString parameter);

    void setQmlRootObject(QObject *value);

signals:

private:
    void callJSMethod(QString param);
    QObject *qmlRootObject;
};

#endif // QMLJSCALLER_H
