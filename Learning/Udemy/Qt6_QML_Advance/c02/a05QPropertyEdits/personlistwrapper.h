/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename personlistwrapper.h
 *
 * class PersonListWrapper
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PERSONLISTWRAPPER_H
#define PERSONLISTWRAPPER_H

#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>

class PersonListWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> persons READ persons WRITE setPersons NOTIFY personsChanged)
public:
    explicit PersonListWrapper(QObject *parent = nullptr);
    bool initialize(QGuiApplication &app);

    Q_INVOKABLE void setName(int index, const QString &name);
    Q_INVOKABLE void setFavoriteColor(int index, const QString &favoriteColor);
    Q_INVOKABLE void setAge(int index, int age);
    Q_INVOKABLE void addPerson();

    QList<QObject *> persons() const;
    void setPersons(const QList<QObject *> &newPersons);

signals:

    void personsChanged();

private:
    void populateModelWithData();
    void resetModel();
    void printPerson();

    QList<QObject *> m_persons;
    QQmlApplicationEngine m_engine;
};

#endif // PERSONLISTWRAPPER_H
