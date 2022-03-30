#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new CustomTableModel(this);


    ui->listView->setModel(model);
    ui->tableView->setModel(model);
    ui->treeView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

