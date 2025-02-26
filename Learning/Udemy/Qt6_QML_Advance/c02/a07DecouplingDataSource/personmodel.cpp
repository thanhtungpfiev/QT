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

PersonModel::PersonModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_dataSource(nullptr)
    , m_signalConnected(false)
{
    setDataSource(new DataSource(this));
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_dataSource->personCount();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_dataSource->personCount())
        return QVariant();
    //The index is valid
    Person *person = m_dataSource->persons()[index.row()];
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
    Person *person = m_dataSource->persons().at(index.row());
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

DataSource *PersonModel::dataSource() const
{
    return m_dataSource;
}

void PersonModel::setDataSource(DataSource *newDataSource)
{
    beginResetModel();

    if (m_dataSource && m_signalConnected)
        m_dataSource->disconnect(this);

    m_dataSource = newDataSource;

    connect(m_dataSource, &DataSource::prePersonAdded, this, [=]() {
        const int index = m_dataSource->personCount();
        beginInsertRows(QModelIndex(), index, index);
    });

    connect(m_dataSource, &DataSource::postPersonAdded, this, [=]() { endInsertRows(); });

    connect(m_dataSource, &DataSource::prePersonRemoved, this, [=](int index) {
        beginRemoveRows(QModelIndex(), index, index);
    });

    connect(m_dataSource, &DataSource::postPersonRemoved, this, [=]() { endRemoveRows(); });

    m_signalConnected = true;

    endResetModel();
}

void PersonModel::addPerson(const QString &name, const int &age)
{
    m_dataSource->addPerson(name, age);
}

void PersonModel::removeLastPerson()
{
    m_dataSource->removeLastPerson();
}
