/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename person.cpp
 *
 * class Person
 *
 * brief
 *
 *
 *****************************************************************************/
#include "person.h"

Person::Person(QObject *parent)
    : QObject{parent}
{}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

int Person::age() const
{
    return m_age;
}

void Person::setAge(int newAge)
{
    if (m_age == newAge)
        return;
    m_age = newAge;
    emit ageChanged();
}
