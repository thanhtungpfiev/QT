/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename datasource.h
 *
 * class DataSource
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include "person.h"

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QObject *parent = nullptr);

    QList<Person *> persons();
    void addPerson(Person *person);
    int personCount();
    void addPerson();
    void addPerson(const QString &names, const int &age);
    void removePerson(int index);
    void removeLastPerson();
    void test();

signals:
    void prePersonAdded();
    void postPersonAdded();
    void prePersonRemoved(int index);
    void postPersonRemoved();

private:
    QList<Person *> m_persons;
};

#endif // DATASOURCE_H
