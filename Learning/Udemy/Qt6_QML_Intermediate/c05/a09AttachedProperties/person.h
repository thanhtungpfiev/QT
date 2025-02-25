/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename person.h
 *
 * class Person
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QtQml>

class Person : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged FINAL)
public:
    explicit Person(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

    int age() const;
    void setAge(int newAge);

signals:
    void nameChanged();

    void ageChanged();

private:
    QString m_name;
    int m_age;
};

#endif // PERSON_H
