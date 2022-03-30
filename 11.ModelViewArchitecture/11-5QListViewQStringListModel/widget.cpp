#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QStringListModel(this);

    QStringList list;
    list << "Cow" << "Rooster" << "Lion" << "Hyena" << "Buffalo";

    model->setStringList(list);

    ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_showData_clicked()
{
    //Reading data with high level API
    /*
    QStringList list = model->stringList();
    qDebug() << "The current data is :" << list;
    */

    //Reading data with low level QAbstractItemModel API
    for(size_t i{}; i < model->rowCount(QModelIndex());++i){
        auto index = model->index(i,0,QModelIndex());
        auto data = index.data(Qt::DisplayRole);
        //auto data = model->data(index);
        qDebug() << data.toString();
    }

}

