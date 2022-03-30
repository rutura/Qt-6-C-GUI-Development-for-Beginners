#include "widget.h"
#include "./ui_widget.h"
#include <somedialog.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Set stylesheet to a leaf independent component
    //ui->clickButton->setStyleSheet("QPushButton{background-color : yellow; color : red;}");
    ui->clickButton->setStyleSheet("background-color : yellow; color : red;");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_clickButton_clicked()
{
    SomeDialog * dialog = new SomeDialog(this);

    //Set the stylesheet to the parent widget
    //dialog->setStyleSheet("QPushButton{background-color : yellow; color : red;}");

    dialog->exec();

}

