#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/minions.png");
    ui->label->setPixmap(pix.scaled(300,300));
}

MainWindow::~MainWindow()
{
    delete ui;
}

