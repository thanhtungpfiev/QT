/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename personmodel.h
 *
 * class PersonModel
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>
#include <QQmlEngine>
#include "person.h"

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    enum PersonRoles { NameRole = Qt::UserRole + 1, FavoriteColorRole, AgeRole };

public:
    PersonModel();

    //Helper function
    Q_INVOKABLE void addPerson(Person *person);
    Q_INVOKABLE void addPerson();
    Q_INVOKABLE void addPerson(const QString &names, const int &age);
    Q_INVOKABLE void removePerson(int index);
    Q_INVOKABLE void removeLastPerson();
    Q_INVOKABLE void test();

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QList<Person *> m_persons;
};

#endif // PERSONMODEL_H
