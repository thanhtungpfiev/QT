/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/25/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename errorlevel.h
 *
 * class ErrorLevel
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef ERRORLEVEL_H
#define ERRORLEVEL_H

#include <QObject>

class ErrorLevel : public QObject
{
    Q_OBJECT
public:
    explicit ErrorLevel(QObject *parent = nullptr);

    enum ErrorValue { INFORMATION, WARNING, DEBUG, MESSAGE };
    Q_ENUM(ErrorValue)

signals:
};

#endif // ERRORLEVEL_H
