/*****************************************************************************
 * author dta3hc - thanhtungpfiev@gmail.com
 *
 * date 15 Dec 2024
 *
 * copyright 2024 - thanhtungpfiev@gmail.com. All rights reserved.
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

void Person::setWeight(double weight)
{
    if (m_weight != weight) {
        m_weight = weight;
        emit weightChanged();
    }
}
