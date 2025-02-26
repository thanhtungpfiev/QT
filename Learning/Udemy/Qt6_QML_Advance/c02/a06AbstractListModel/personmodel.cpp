/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename personmodel.cpp
 *
 * class PersonModel
 *
 * brief
 *
 *
 *****************************************************************************/
#include "personmodel.h"

PersonModel::PersonModel()
{
    addPerson(new Person("Jamie Lannister", "red", 33));
    addPerson(new Person("Marry Lane", "cyan", 26));
    addPerson(new Person("Steve Moors", "yellow", 44));
    addPerson(new Person("Victor Trunk", "dodgerblue", 30));
    addPerson(new Person("Ariel Geeny", "blue", 33));
    addPerson(new Person("Knut Vikran", "lightblue", 26));
}

void PersonModel::addPerson(Person *person)
{
    const int index = m_persons.size();
    beginInsertRows(QModelIndex(), index, index); //Tell the model that you are about to add data
    m_persons.append(person);
    endInsertRows();
}

void PersonModel::addPerson()
{
    Person *person = new Person("Added Person", "yellowgreen", 45, this);
    addPerson(person);
}

void PersonModel::addPerson(const QString &names, const int &age)
{
    Person *person = new Person(names, "yellowgreen", age);
    addPerson(person);
}

void PersonModel::removePerson(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_persons.removeAt(index);
    endRemoveRows();
}

void PersonModel::removeLastPerson()
{
    removePerson(m_persons.size() - 1);
}

void PersonModel::test()
{
    qDebug() << m_persons.size();
    foreach (Person *person, m_persons) {
        qDebug() << person->name() << " " << person->age() << " " << person->favoriteColor();
    }
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_persons.size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_persons.count())
        return QVariant();
    //The index is valid
    Person *person = m_persons[index.row()];
    switch (role) {
    case NameRole:
        return person->name();
    case FavoriteColorRole:
        return person->favoriteColor();
    case AgeRole:
        return person->age();
    default:
        break;
    }
    return QVariant();
}

bool PersonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Person *person = m_persons.at(index.row());
    switch (role) {
    case NameRole:
        person->setName(value.toString());
        return true;
    case FavoriteColorRole:
        person->setFavoriteColor(value.toString());
        return true;
    case AgeRole:
        person->setAge(value.toInt());
        return true;
    default:
        break;
    }
    return false;
}

Qt::ItemFlags PersonModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[FavoriteColorRole] = "favoriteColor";
    roles[AgeRole] = "age";
    return roles;
}
