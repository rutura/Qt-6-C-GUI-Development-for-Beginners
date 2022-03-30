#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setAutoFillBackground(true);

    //Retrieve the palette for the label
    QPalette palette = ui->label->palette();

    //Modify the palette with our changes
    palette.setColor(QPalette::Window,Qt::blue);
    palette.setColor(QPalette::WindowText,Qt::red);

    //Reset the palette to the widget
    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_activeButton_clicked()
{
    QPalette::ColorGroup activeButtonColorGroup = ui->activeButton->palette().currentColorGroup();
    QPalette::ColorGroup disabledButtonColorGroup = ui->disabledButton->palette().currentColorGroup();

    qDebug() << " Active button color group  : " << activeButtonColorGroup;
    qDebug() << " Disabled button color group : " <<disabledButtonColorGroup;

}


void Widget::on_disabledButton_clicked()
{
    qDebug() << "Disabled button clicked";
}

