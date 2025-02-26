/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
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

Person::Person(const QString &name, const QString &favoriteColor, const int &age, QObject *parent)
    : QObject(parent)
    , m_name(name)
    , m_favoriteColor(favoriteColor)
    , m_age(age)
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

QString Person::favoriteColor() const
{
    return m_favoriteColor;
}

void Person::setFavoriteColor(const QString &newFavoriteColor)
{
    if (m_favoriteColor == newFavoriteColor)
        return;
    m_favoriteColor = newFavoriteColor;
    emit favoriteColorChanged();
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
