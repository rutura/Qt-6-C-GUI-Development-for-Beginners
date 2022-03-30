#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

        /*
    QVBoxLayout * layout = new QVBoxLayout();

    layout->addWidget(ui->oneButton);
    layout->addWidget(ui->twoButton);
    layout->addWidget(ui->threeButton);
    layout->addWidget(ui->fourButton);
    layout->addWidget(ui->fiveButton);

    setLayout(layout);
    */

}

Widget::~Widget()
{
    delete ui;
}

