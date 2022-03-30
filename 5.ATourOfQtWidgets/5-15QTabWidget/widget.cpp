#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Declare the widget
    QWidget * widget = new QWidget(this);

    //Declare the layout for the widget
    QVBoxLayout * layout = new QVBoxLayout();

    layout->addWidget(new QPushButton("Button1",this));
    layout->addWidget(new QPushButton("Button2",this));
    layout->addWidget(new QPushButton("Button3",this));
    QPushButton * button4 = new QPushButton("Button4",this);
    connect(button4,&QPushButton::clicked,[=](){
        qDebug() << "Button4 from custom tab clicked";
    });
    layout->addWidget(button4);
    layout->addSpacerItem(new QSpacerItem(100,200));

    //Set the layout to the widget
    widget->setLayout(layout);

    ui->tabWidget->insertTab(0,widget,"My Custom Tab");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_3_clicked()
{
    qDebug() << "Clicked on the button in the tab";
}

