#include "widget.h"
#include "./ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

     /*
     QHBoxLayout *layout = new QHBoxLayout();

     layout->addWidget(ui->oneButton);
     layout->addWidget(ui->twoButton);
     layout->addWidget(ui->threeButton);
     layout->addWidget(ui->fourButton);
     layout->addWidget(ui->fiveButton);

     setLayout(layout);//This widget will take over the memory management
                        //responsibilities for the layout object
     */
}

Widget::~Widget()
{
    delete ui;
}

