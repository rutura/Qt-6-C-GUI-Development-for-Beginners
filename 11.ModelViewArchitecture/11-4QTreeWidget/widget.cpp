#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);

    //Set header data
    ui->treeWidget->setHeaderLabels(QStringList() << "ID" << "Name");

    //Add data
    QTreeWidgetItem *treeItem1 = new QTreeWidgetItem(ui->treeWidget);
    treeItem1->setText(0, "11");
    treeItem1->setText(1, "Snow");

    QTreeWidgetItem *treeItem2 = new QTreeWidgetItem(ui->treeWidget);
    treeItem2->setText(0, "22");
    treeItem2->setText(1, "David");

    QTreeWidgetItem *treeItem3 = new QTreeWidgetItem(); // We don't give it an affiliation
    treeItem3->setText(0, "33");
    treeItem3->setText(1, "Steve");

    //Add item3 as a child of item2
    treeItem2->addChild(treeItem3);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_listItemsButton_clicked()
{
    for(size_t i{}; i < ui->treeWidget->topLevelItemCount();++i){
         auto item = ui->treeWidget->topLevelItem(i);
         if(item){
             qDebug() << item->data(0,Qt::DisplayRole).toString() << ","
                             << item->data(1,Qt::DisplayRole).toString();
             //Look for children
             if(item->childCount()!=0){
                 for(size_t j{}; j < ui->treeWidget->topLevelItemCount();++j){
                     auto child = item->child(j);
                     if(child){
                         qDebug() <<"---"<< child->data(0,Qt::DisplayRole).toString() << ","
                                         << child->data(1,Qt::DisplayRole).toString();
                     }
                 }
             }
         }
     }
}

