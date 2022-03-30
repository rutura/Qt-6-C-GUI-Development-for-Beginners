#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //String notation
    /*
    connect(ui->myButton,SIGNAL(clicked()),this,SLOT(change_text()));
    */

    //Functor Notation : Regular Slots
    /*
    connect(ui->myButton,&QPushButton::clicked,this,&Widget::change_text);
    */

    //Functor Notation : Lambdas
    connect(ui->myButton,&QPushButton::clicked,[=](){
        ui->label->setText("Some other text from lambda");
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_text()
{
    ui->label->setText("Some other text");
}




