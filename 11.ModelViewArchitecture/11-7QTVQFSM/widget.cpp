#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Using QFileSystemModel
    /*
    QString path = "E:/";// /home/username/Downloads
    //Dir Model
    dir_model = new QFileSystemModel(this);
    dir_model->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
    dir_model->setRootPath(path);


     // The same "tree" model can be fed to both QListView and QTreeView. Even QTableView
     // The view will pick as much as it can handle from the model and display the data

    ui->treeView->setModel(dir_model);
    ui->listView->setModel(dir_model);
    */





    //QStrandardItemModel in tree model
    standard_item_tree_model = new QStandardItemModel();
    QStandardItem *parentItem = standard_item_tree_model->invisibleRootItem();
    for (int i = 0; i < 4; ++i) {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }
    ui->treeView->setModel(standard_item_tree_model);
    ui->listView->setModel(standard_item_tree_model);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_readDataButton_clicked()
{
    //Read from the file system model
    /*
    qDebug() <<"Row count : "  << dir_model->rowCount(QModelIndex());
    qDebug() << "Column count : " << dir_model->columnCount(QModelIndex());
    auto index = dir_model->index(0,0,QModelIndex());
    auto data = index.data();
    qDebug() << "data : " << data.toString() ;
    */

    //Read from standard item model
    qDebug() <<"Row count : "  << standard_item_tree_model->rowCount(QModelIndex());
    qDebug() << "Column count : " << standard_item_tree_model->columnCount(QModelIndex());
    auto index = standard_item_tree_model->index(0,0,QModelIndex());
    auto data = index.data();
    qDebug() << "data : " << data.toString() ;


}

