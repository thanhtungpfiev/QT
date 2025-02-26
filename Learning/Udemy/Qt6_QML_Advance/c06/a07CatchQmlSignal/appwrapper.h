/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/26/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename appwrapper.h
 *
 * class AppWrapper
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);
    bool initialize(QGuiApplication &app);

signals:

private slots:
    void respondToClick(QString msg, const QVariant &object);

private:
    QQmlApplicationEngine mEngine;
};

#endif // APPWRAPPER_H
