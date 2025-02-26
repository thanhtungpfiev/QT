/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename personlistwrapper.cpp
 *
 * class PersonListWrapper
 *
 * brief
 *
 *
 *****************************************************************************/
#include "personlistwrapper.h"
#include <QQmlContext>
#include "person.h"

PersonListWrapper::PersonListWrapper(QObject *parent)
    : QObject{parent}
{
    populateModelWithData();
}

bool PersonListWrapper::initialize(QGuiApplication &app)
{
    resetModel();
    QObject::connect(
        &m_engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    m_engine.loadFromModule("a05QPropertyEdits", "Main");

    if (m_engine.rootObjects().isEmpty())
        return false;

    return true;
}

void PersonListWrapper::setName(int index, const QString &name)
{
    qDebug() << "Changing name to" << name;
    if (index < 0 || index >= m_persons.size()) {
        return;
    }
    Person *person = qobject_cast<Person *>(m_persons.at(index));
    if (!person) {
        return;
    }
    person->setName(name);
    printPerson();
}

void PersonListWrapper::setFavoriteColor(int index, const QString &favoriteColor)
{
    qDebug() << "Changing favoriteColor to" << favoriteColor;
    if (index < 0 || index >= m_persons.size()) {
        return;
    }
    Person *person = qobject_cast<Person *>(m_persons.at(index));
    if (!person) {
        return;
    }
    person->setFavoriteColor(favoriteColor);
    printPerson();
}

void PersonListWrapper::setAge(int index, int age)
{
    qDebug() << "Changing age to" << age;
    if (index < 0 || index >= m_persons.size()) {
        return;
    }
    Person *person = qobject_cast<Person *>(m_persons.at(index));
    if (!person) {
        return;
    }
    person->setAge(age);
    printPerson();
}

QList<QObject *> PersonListWrapper::persons() const
{
    return m_persons;
}

void PersonListWrapper::setPersons(const QList<QObject *> &newPersons)
{
    if (m_persons == newPersons)
        return;
    m_persons = newPersons;
    emit personsChanged();
}

void PersonListWrapper::addPerson()
{
    m_persons.append(new Person{"New Person", "green", 32, this});
    emit personsChanged();
    printPerson();
}

void PersonListWrapper::populateModelWithData()
{
    m_persons.append(new Person{"John Doe", "green", 32, this});
    m_persons.append(new Person{"Mary Green", "blue", 23, this});
    m_persons.append(new Person{"Mitch Nathson", "dodgerblue", 30, this});
}

void PersonListWrapper::resetModel()
{
    m_engine.rootContext()->setContextProperty("Wrapper", this);
}

void PersonListWrapper::printPerson()
{
    qDebug() << "-------------Persons--------------------";
    foreach (QObject *obj, m_persons) {
        Person *person = qobject_cast<Person *>(obj);
        qDebug() << person->name() << " " << person->age() << " " << person->favoriteColor();
    }
}
