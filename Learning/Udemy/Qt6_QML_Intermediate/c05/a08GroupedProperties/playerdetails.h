/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename playerdetails.h
 *
 * class PlayerDetails
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PLAYERDETAILS_H
#define PLAYERDETAILS_H

#include <QObject>
#include <QtQml>

class PlayerDetails : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged FINAL)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged FINAL)
    Q_PROPERTY(qreal speed READ speed WRITE setSpeed NOTIFY speedChanged FINAL)
public:
    explicit PlayerDetails(QObject *parent = nullptr);

    qreal height() const;
    void setHeight(qreal newHeight);

    qreal weight() const;
    void setWeight(qreal newWeight);

    qreal speed() const;
    void setSpeed(qreal newSpeed);

signals:
    void heightChanged();

    void weightChanged();

    void speedChanged();

private:
    qreal m_height;
    qreal m_weight;
    qreal m_speed;
};

#endif // PLAYERDETAILS_H
