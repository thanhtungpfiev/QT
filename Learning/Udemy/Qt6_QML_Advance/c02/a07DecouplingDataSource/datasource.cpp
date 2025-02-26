/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename datasource.cpp
 *
 * class DataSource
 *
 * brief
 *
 *
 *****************************************************************************/
#include "datasource.h"
#include <QDebug>

DataSource::DataSource(QObject *parent)
    : QObject{parent}
{
    addPerson(new Person("Jamie Lannister", "red", 33));
    addPerson(new Person("Marry Lane", "cyan", 26));
    addPerson(new Person("Steve Moors", "yellow", 44));
    addPerson(new Person("Victor Trunk", "dodgerblue", 30));
    addPerson(new Person("Ariel Geeny", "blue", 33));
    addPerson(new Person("Knut Vikran", "lightblue", 26));
}

QList<Person *> DataSource::persons()
{
    return m_persons;
}

void DataSource::addPerson(Person *person)
{
    emit prePersonAdded();
    m_persons.append(person);
    emit postPersonAdded();
}

int DataSource::personCount()
{
    return m_persons.size();
}

void DataSource::addPerson()
{
    Person *person = new Person("Added Person", "yellowgreen", 45, this);
    addPerson(person);
}

void DataSource::addPerson(const QString &names, const int &age)
{
    Person *person = new Person(names, "yellowgreen", age);
    addPerson(person);
}

void DataSource::removePerson(int index)
{
    emit prePersonRemoved(index);
    m_persons.removeAt(index);
    emit postPersonRemoved();
}

void DataSource::removeLastPerson()
{
    removePerson(m_persons.size() - 1);
}

void DataSource::test()
{
    qDebug() << m_persons.size();
    foreach (Person *person, m_persons) {
        qDebug() << person->name() << " " << person->age() << " " << person->favoriteColor();
    }
}
