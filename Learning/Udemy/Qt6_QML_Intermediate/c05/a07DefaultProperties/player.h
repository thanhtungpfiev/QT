/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename player.h
 *
 * class Player
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QtQml>

class Player : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool playing READ playing WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString position READ position WRITE setPosition NOTIFY positionChanged)
public:
    explicit Player(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

    bool playing() const;
    void setPlaying(bool newPlaying);

    QString position() const;
    void setPosition(const QString &newPosition);

    Q_INVOKABLE virtual void play() = 0;

signals:
    void nameChanged();

    void playingChanged();

    void positionChanged();

private:
    QString m_name;
    bool m_playing;
    QString m_position;
};

#endif // PLAYER_H
