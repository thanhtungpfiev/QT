/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename cat.h
 *
 * class Cat
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef CAT_H
#define CAT_H

#include <QObject>

class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);
    void public_test(); //not called

signals:

public slots:

    void test(); //not called

private slots:
    void play();
    void meow();
    void sleep();
    void speak(QString value); //no param

private:
    void private_test(); //not called
};

#endif // CAT_H
