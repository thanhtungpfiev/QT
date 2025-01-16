/*****************************************************************************
 * author dta3hc - thanhtungpfiev@gmail.com
 *
 * date 15 Dec 2024
 *
 * copyright 2024 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename %{Cpp:License:FileName}
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void calculate_calories();
    void weight_changed(double weight);
    void time_changed(double time);
    void speed_changed(double speed);

signals:
    void calory_count_changed();

private:
    Ui::Widget *ui;
    Person m_person;
    double m_time;
    double m_speed;
    double m_calory_count;
};
#endif // WIDGET_H
