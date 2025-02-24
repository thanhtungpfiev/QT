/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename fetchposts.h
 *
 * class FetchPosts
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef FETCHPOSTS_H
#define FETCHPOSTS_H

#include <QObject>
#include <QStringList>
#include <QtQml>

class FetchPosts : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList posts READ posts WRITE setPosts NOTIFY postsChanged)
    QML_ELEMENT
public:
    explicit FetchPosts(QObject *parent = nullptr);

    QStringList posts() const;
    void setPosts(const QStringList &newPosts);

signals:
    void postsChanged();

public slots:
    void fetchPosts();
    void removeLast();

private:
    QStringList m_posts;

private:
    QNetworkAccessManager net_manager;
    std::unique_ptr<QNetworkRequestFactory> m_factory;
    std::unique_ptr<QRestAccessManager> m_rest_manager;
};

#endif // FETCHPOSTS_H
