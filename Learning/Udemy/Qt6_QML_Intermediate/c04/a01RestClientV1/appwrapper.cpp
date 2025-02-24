/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename appwrapper.cpp
 *
 * class AppWrapper
 *
 * brief
 *
 *
 *****************************************************************************/
#include "appwrapper.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QQmlContext>

AppWrapper::AppWrapper(QObject *parent)
    : QObject{parent}
    , mNetManager(std::make_unique<QNetworkAccessManager>())
{}

AppWrapper::~AppWrapper() {}

void AppWrapper::fetchPosts()
{
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply, &QIODevice::readyRead, this, &AppWrapper::dataReadyRead);
    connect(mNetReply, &QNetworkReply::finished, this, &AppWrapper::dataFinshedRead);
}

void AppWrapper::removeLast()
{
    if (!mPosts.empty()) {
        mPosts.removeLast();
        resetModel();
    }
}

bool AppWrapper::initialize(QGuiApplication *app)
{
    mEngine.rootContext()->setContextProperty("Wrapper", this);
    resetModel();

    QObject::connect(
        &mEngine,
        &QQmlApplicationEngine::objectCreationFailed,
        app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    mEngine.loadFromModule("a01RestClientV1", "Main");

    if (mEngine.rootObjects().isEmpty()) {
        return false;
    } else {
        return true;
    }
}

void AppWrapper::dataReadyRead()
{
    mDataBuffer.append(mNetReply->readAll());
}

void AppWrapper::dataFinshedRead()
{
    if (mNetReply->error()) {
        qDebug() << "Error: " << mNetReply->errorString();
    } else {
        QJsonDocument doc = QJsonDocument::fromJson(mDataBuffer);

        QJsonArray array = doc.array();

        for (int i = 0; i < array.size(); ++i) {
            QJsonObject object = array.at(i).toObject();
            QVariantMap map = object.toVariantMap();
            QString title = map["title"].toString();
            mPosts.append(title);
        }

        if (mPosts.size()) {
            resetModel();
        }
        mDataBuffer.clear();
    }
}

void AppWrapper::resetModel()
{
    mEngine.rootContext()->setContextProperty("myModel", QVariant::fromValue(mPosts));
}
