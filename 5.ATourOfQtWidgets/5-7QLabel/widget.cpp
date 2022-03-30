#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->minionTextLabel->move(100,30);

    QPixmap my_image(":/images/minions.png");

    ui->imageLabel->move(0,70);
    ui->imageLabel->setPixmap(my_image.scaled(400,400));

}

Widget::~Widget()
{
    delete ui;
}

