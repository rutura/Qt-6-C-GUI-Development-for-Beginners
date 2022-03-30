#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStandardItemModel(4, 4);
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
            model->setItem(row, column, item);
        }
    }

    ui->tableView->setModel(model);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_readData_clicked()
{
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
           auto index = model->index(row,column,QModelIndex());
           //auto data = index.data(Qt::DisplayRole);
           auto data = model->data(index,Qt::DisplayRole);
           qDebug() << data.toString();
        }
        qDebug() << "------";

    }

}

