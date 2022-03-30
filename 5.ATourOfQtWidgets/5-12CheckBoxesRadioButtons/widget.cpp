#include "widget.h"
#include "./ui_widget.h"
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup * group = new QButtonGroup(this);
    group->addButton(ui->windowsCheckBox);
    group->addButton(ui->macCheckBox);
    group->addButton(ui->linuxCheckBox);
    group->setExclusive(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_windowsCheckBox_toggled(bool checked)
{
    if( checked)
    {
        qDebug() << "Windows Checkbox is checked";
    }else
    {
        qDebug() << "Windows Checkbox is unchecked";
    }
}


void Widget::on_beerCheckBox_toggled(bool checked)
{
    if( checked)
    {
        qDebug() << "Beer Checkbox is checked";
    }else
    {
        qDebug() << "Beer Checkbox is unchecked";
    }
}


void Widget::on_grabDataButton_clicked()
{
    if(ui->beerCheckBox->isChecked()){
         qDebug() << "Beer Checkbox is checked";
    }else{
       qDebug() << "Beer Checkbox is unchecked";
    }
}


void Widget::on_setDataButton_clicked()
{
    ui->beerCheckBox->setChecked(true);
}

