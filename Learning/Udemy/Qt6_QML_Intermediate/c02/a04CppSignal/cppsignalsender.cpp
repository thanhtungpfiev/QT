/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/23/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cppsignalsender.cpp
 *
 * class CppSignalSender
 *
 * brief
 *
 *
 *****************************************************************************/
#include "cppsignalsender.h"

CppSignalSender::CppSignalSender(QObject *parent)
    : QObject{parent}
    , m_timer(new QTimer(this))
    , m_value(0)
{
    connect(&m_timer, &QTimer::timeout, [=]() { emit cppTimer(QString::number(m_value++)); });
    m_timer.start(1000);
}

void CppSignalSender::cppSlot()
{
    emit callQml("Information from C++");
}
