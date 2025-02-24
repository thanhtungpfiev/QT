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
#include <QNetworkReply>
#include <QObject>
#include <QQmlApplicationEngine>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);
    virtual ~AppWrapper();
    Q_INVOKABLE void fetchPosts();
    Q_INVOKABLE void removeLast();
    bool initialize(QGuiApplication *app);

signals:

private slots:
    void dataReadyRead();
    void dataFinshedRead();

private:
    void resetModel();

    std::unique_ptr<QNetworkAccessManager> mNetManager;
    QNetworkReply *mNetReply;
    QByteArray mDataBuffer;
    QStringList mPosts;
    QQmlApplicationEngine mEngine;
};

#endif // APPWRAPPER_H
