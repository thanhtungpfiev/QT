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
#include "datasource.h"

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(
        DataSource *dataSource READ dataSource WRITE setDataSource NOTIFY dataSourceChanged FINAL)
    enum PersonRoles { NameRole = Qt::UserRole + 1, FavoriteColorRole, AgeRole };

public:
    explicit PersonModel(QObject *parent = nullptr);
    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    DataSource *dataSource() const;
    void setDataSource(DataSource *newDataSource);

    Q_INVOKABLE void addPerson(const QString &name, const int &age);
    Q_INVOKABLE void removeLastPerson();

signals:
    void dataSourceChanged();

private:
    DataSource *m_dataSource = nullptr;
    bool m_signalConnected;
};

#endif // PERSONMODEL_H
