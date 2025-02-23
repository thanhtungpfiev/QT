/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename propertywrapper.h
 *
 * class PropertyWrapper
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PROPERTYWRAPPER_H
#define PROPERTYWRAPPER_H

#include <QObject>
#include <QTimer>

class PropertyWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)
public:
    explicit PropertyWrapper(QObject *parent = nullptr);
    QString lastname() const;
    QString firstname() const;
    void setLastname(QString lastname);
    void setFirstname(QString firstname);

signals:
    void lastnameChanged(QString lastname);
    void firstnameChanged(QString firstname);

private:
    QString m_lastname;
    QString m_firstname;
    QTimer *m_timer;
    int m_random_number;
};

#endif // PROPERTYWRAPPER_H
