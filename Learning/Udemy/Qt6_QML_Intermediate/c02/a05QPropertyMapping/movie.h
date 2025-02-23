/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename movie.h
 *
 * class Movie
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>

class Movie : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(
        QString mainCharacter READ mainCharacter WRITE setMainCharacter NOTIFY mainCharacterChanged)
public:
    explicit Movie(QObject *parent = nullptr);

    QString title() const;
    void setTitle(const QString &newTitle);

    QString mainCharacter() const;
    void setMainCharacter(const QString &newMainCharacter);

signals:
    void titleChanged();

    void mainCharacterChanged();

private:
    QString m_title;
    QString m_mainCharacter;
};

#endif // MOVIE_H
