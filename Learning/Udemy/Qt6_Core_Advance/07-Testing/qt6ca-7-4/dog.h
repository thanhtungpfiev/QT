/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename dog.h
 *
 * class Dog
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef DOG_H
#define DOG_H

#include <QObject>

class Dog : public QObject
{
    Q_OBJECT
public:
    explicit Dog(QObject *parent = nullptr);

signals:

public slots:

private slots:
    //Called before the first test
    void initTestCase();

    //Called before each test
    void init();

    //Called after each test
    void cleanup();

    //Called after the last test
    void cleanupTestCase();

    //Our custom slot to be tested
    void bark();

    //Another custom slot to test
    void rollover();
};

#endif // DOG_H
