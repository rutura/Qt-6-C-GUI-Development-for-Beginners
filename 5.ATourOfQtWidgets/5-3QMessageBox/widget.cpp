#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton * button = new QPushButton(this);//Heap
    button->setText("Click Me");
    button->move(200,200);

    connect(button,&QPushButton::clicked,[=](){

        //The hard way
        /*
        QMessageBox message;
        message.setMinimumSize(700,200);
        message.setWindowTitle("Message Title");
        message.setText("Something happened");
        message.setInformativeText("Do you want to do something about it ?");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        int ret = message.exec();
        */

        //Critical Message
        /*
        int ret = QMessageBox::critical(this,"Message Title",
                                        "Something happened. Do you want to do something about it ?",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        */

        //Information Message
        /*
        int ret = QMessageBox::information(this,"Message Title",
                                        "Something happened. Do you want to do something about it ?",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        */


        //Question
        /*
        int ret = QMessageBox::question(this,"Message Title",
                                       "Something happened. Do you want to do something about it ?",
                                       QMessageBox::Ok | QMessageBox::Cancel);
        */

        //Warning message : Handling the user action
        int ret = QMessageBox::warning(this,"Message Title",
                                       "Something happened. Do you want to do something about it ?",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        if ( ret == QMessageBox::Ok)
        {
            qDebug() << "User clicked on OK";
        }

        if ( ret == QMessageBox::Cancel)
        {
            qDebug() << "User clicked on Cancel";
        }
    });
}

Widget::~Widget()
{
}

