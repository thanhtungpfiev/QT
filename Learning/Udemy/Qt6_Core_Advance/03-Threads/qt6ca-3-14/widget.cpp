/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/4/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename widget.cpp
 *
 * class Widget
 *
 * brief
 *
 *
 *****************************************************************************/
#include "widget.h"
#include <QDebug>
#include <QThread>

Widget::Widget(QObject *parent)
    : QObject{parent}
{
    m_isSender = false;
    m_isActive = true;
}

void Widget::workStarted()
{
    qInfo() << this << "Started" << sender();
}

void Widget::workFinished()
{
    qInfo() << this << "Finished" << sender();
    m_isActive = false;
}

void Widget::workReady(int i)
{
    qInfo() << this << "Work" << i << sender();
}

void Widget::run()
{
    if (m_isSender) {
        qInfo() << this << "Starting work ...";
        emit started();

        for (int i = 0; i < 10; i++) {
            qInfo() << this << "Update ...";
            emit update(i);
            QThread::currentThread()->msleep(500);
        }

        qInfo() << this << "Finished ...";
        emit finished();
    } else {
        qInfo() << this << "Waiting for signals...";
        m_isActive = true;
        while (m_isActive) {
            QThread::currentThread()->msleep(100);
        }
    }

    qInfo() << this << "Done";
}

bool Widget::isSender() const
{
    return m_isSender;
}

void Widget::setIsSender(bool newIsSender)
{
    m_isSender = newIsSender;
}

bool Widget::isActive() const
{
    return m_isActive;
}

void Widget::setIsActive(bool newIsActive)
{
    m_isActive = newIsActive;
}
