/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename randomnumber.h
 *
 * class RandomNumber
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <QObject>
#include <QQmlPropertyValueSource>
#include <QTimer>
#include <QtQml>

class RandomNumber : public QObject, public QQmlPropertyValueSource
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged FINAL)
    Q_INTERFACES(QQmlPropertyValueSource)
public:
    explicit RandomNumber(QObject *parent = nullptr);

    int maxValue() const;
    void setMaxValue(int newMaxValue);

    // QQmlPropertyValueSource interface
public:
    virtual void setTarget(const QQmlProperty &) override;

signals:
    void maxValueChanged();

private slots:
    void updateProperty();

private:
    int m_maxValue;
    QQmlProperty m_targetProperty;
    QTimer *m_timer;
};

#endif // RANDOMNUMBER_H
