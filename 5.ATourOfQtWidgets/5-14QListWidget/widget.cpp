#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

    ui->listWidget->addItem("Item1");
    ui->listWidget->addItem("Item2");
    QStringList listData;
    listData << "Item3" << "Item4" << "Item5";
    ui->listWidget->addItems(listData);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemButton_clicked()
{
    ui->listWidget->addItem("Another item");
}


void Widget::on_removeItemButton_clicked()
{
    //Delete item : use takeItem
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}


void Widget::on_selectedItemsButton_clicked()
{
    // Get the list of selected items
    QList<QListWidgetItem *> list =  ui->listWidget->selectedItems();

    for( int i = 0;  i < list.count(); i++)
    {
        qDebug() << "Selected item : " << list.at(i)->text() << " , row number id : "<<
                    ui->listWidget->row(list.at(i));
    }

}

