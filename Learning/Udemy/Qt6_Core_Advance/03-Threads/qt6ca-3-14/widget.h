/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename widget.h
 *
 * class Widget
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QRunnable>

class Widget : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);

signals:
    void started();
    void finished();
    void update(int i);

public slots:
    void workStarted();
    void workFinished();
    void workReady(int i);

    // QRunnable interface
public:
    void run();

    bool isSender() const;
    void setIsSender(bool newIsSender);
    bool isActive() const;
    void setIsActive(bool newIsActive);

private:
    bool m_isSender;
    bool m_isActive;
};

#endif // WIDGET_H
