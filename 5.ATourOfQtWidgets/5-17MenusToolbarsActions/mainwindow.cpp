#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    statusBar()->showMessage("App will be killed in 5 seconds...");
    QTimer::singleShot(5000, this, &MainWindow::quitApp);
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"Message",
         "This is demo app to show how to use menus, toolbars and actions in Qt");
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::quitApp()
{
    QApplication::quit();
}

