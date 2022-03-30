#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>

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


void Widget::on_chooseDirButton_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this,"Choose Folder");
    if( filename.isEmpty())
        return;
    ui->lineEdit->setText(filename);
}


void Widget::on_createDirButton_clicked()
{
    //Create a dir if it doesn't exist already
    QString dirPath = ui->lineEdit->text();
    if( dirPath.isEmpty())
        return;
    QDir dir(dirPath);
    if( !dir.exists())
    {
        //Create it
        if(dir.mkpath(dirPath))
        {
            QMessageBox::information(this,"Message","Directory created");
        }
    }else
    {
        QMessageBox::information(this,"Message","Directory already exists");
    }
}


void Widget::on_dirExistsButton_clicked()
{
    //Check if a directory exists
    QString dirPath = ui->lineEdit->text();
    if( dirPath.isEmpty())
        return;

    QDir dir(dirPath);
    if( dir.exists())
    {
        QMessageBox::information(this,"Message","Directory exists");
    }else
    {
        QMessageBox::information(this,"Message","Directory doesn't exist");
    }

}


void Widget::on_dirOrFileButton_clicked()
{
    QFileInfo fileInfo(ui->listWidget->currentItem()->text());
     if( fileInfo.isDir())
     {
         QMessageBox::information(this,"Message","This a Dir");
     }
     else if( fileInfo.isFile())
     {
         QMessageBox::information(this,"Message","This a File");
     }else
     {
        QMessageBox::information(this,"Message","Something else");
     }
}


void Widget::on_folderContent_clicked()
{
    ui->listWidget->clear();

    QString dirPath = ui->lineEdit->text();
    if( dirPath.isEmpty())
        return;
    QDir dir(dirPath);

    //Get the list of files and directories in the folder
    QList<QFileInfo> fileList = dir.entryInfoList();

    for( int i = 0 ; i < fileList.size() ; i++)
    {
        ui->listWidget->addItem(fileList.at(i).absoluteFilePath());
    }
}

