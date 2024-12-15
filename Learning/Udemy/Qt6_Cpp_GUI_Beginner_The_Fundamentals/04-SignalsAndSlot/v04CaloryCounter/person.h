/*****************************************************************************
 * author dta3hc - thanhtungpfiev@gmail.com
 *
 * date 15 Dec 2024
 *
 * copyright 2024 - thanhtungpfiev@gmail.com. All rights reserved.
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

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);

public:
    double weight() const { return m_weight; }
    void setWeight(double weight);

signals:
    void weightChanged();

private:
    double m_weight = 0.0;
};

#endif // PERSON_H
