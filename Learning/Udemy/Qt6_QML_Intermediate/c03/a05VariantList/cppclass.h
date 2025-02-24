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

#include <QObject>
#include <QVariantList>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

    Q_INVOKABLE void passFromQmlToCpp(QVariantList list, QVariantMap map);
    Q_INVOKABLE QVariantList getVariantListFromCpp();
    Q_INVOKABLE QVariantMap getVariantMapFromCpp();

    void setQmlRootObject(QObject *value);

signals:

public slots:
    void triggerJSCall();

private:
    QObject *qmlRootObject;
};

#endif // CPPCLASS_H
