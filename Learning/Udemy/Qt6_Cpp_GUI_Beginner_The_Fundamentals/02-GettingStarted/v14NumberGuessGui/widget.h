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
    void on_guessButton_clicked();
    void on_startOverButton_clicked();

private:
    Ui::Widget *ui;
    int secret_number;
    int guess_number;
};
#endif // WIDGET_HWIDGET_H
