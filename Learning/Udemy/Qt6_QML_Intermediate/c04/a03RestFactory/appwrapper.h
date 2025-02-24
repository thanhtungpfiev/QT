/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
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
#include <QNetworkAccessManager>
#include <QNetworkRequestFactory>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QRestAccessManager>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);
    ~AppWrapper();
    Q_INVOKABLE void fetchPosts();
    Q_INVOKABLE void removeLast();
    bool initialize(QGuiApplication *app);

private:
    void resetModel();
    QNetworkAccessManager net_manager;
    std::unique_ptr<QNetworkRequestFactory> m_factory;
    std::unique_ptr<QRestAccessManager> m_rest_access_manager;
    QStringList mPosts;
    QQmlApplicationEngine mEngine;
};

#endif // APPWRAPPER_H
