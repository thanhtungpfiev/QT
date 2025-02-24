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
#include <QVector>
#include <QtQml>

class CppClass : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit CppClass(QObject *parent = nullptr);

    Q_INVOKABLE void qmlArrayToCpp(QVector<QString> vector);

    Q_INVOKABLE QVector<QString> retrieveStrings();

signals:

public slots:

private:
    QVector<QString> mVector;
};

#endif // CPPCLASS_H
