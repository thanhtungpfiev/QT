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
    void respond(int value);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
