#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_chooseButton_clicked()
{

    //getExistingDirectory
    /*
    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory",
                                                      QString(),
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    if(!dir.isEmpty()){
        qDebug() << "Your chosed dir is : " << dir;
    }else{
        qDebug() << "You didn't choose anything...";
    }
    */

    //getOpenFileName
    /*
    QString fileName = QFileDialog::getOpenFileName(this, "Open File",
                                                      QString(),
                                                      tr("Images (*.png *.xpm *.jpg)"));
    qDebug() << "Your chosed file is : " << fileName;
    */

    //getOpenFileNames
    /*
    QStringList files = QFileDialog::getOpenFileNames(
                              this,
                              "Select one or more files to open",
                              QString(),
                              "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");
    //qDebug() << "Your chosen files are : " << files;
    for( auto f : files){
        qDebug() <<  f ;
    }
    */

    //getSaveFileName
    QString fileName = QFileDialog::getSaveFileName(this, "Save File",
                                 QString(),
                                 tr("Images (*.png *.xpm *.jpg)"));
    qDebug() << "Your chosen filename is  : " << fileName;

}

