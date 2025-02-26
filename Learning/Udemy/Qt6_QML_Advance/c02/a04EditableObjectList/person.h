/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
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
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString favoriteColor READ favoriteColor WRITE setFavoriteColor NOTIFY
                   favoriteColorChanged FINAL)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged FINAL)

public:
    explicit Person(QObject *parent = nullptr);
    Person(const QString &name,
           const QString &favoriteColor,
           const int &age,
           QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

    QString favoriteColor() const;
    void setFavoriteColor(const QString &newFavoriteColor);

    int age() const;
    void setAge(int newAge);

signals:
    void nameChanged();

    void favoriteColorChanged();

    void ageChanged();

private:
    QString m_name;
    QString m_favoriteColor;
    int m_age;
};

#endif // PERSON_H
