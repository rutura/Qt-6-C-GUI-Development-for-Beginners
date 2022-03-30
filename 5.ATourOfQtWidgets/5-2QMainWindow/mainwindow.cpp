#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    //Add central widget
    QPushButton * button = new QPushButton("Hello",this);
    setCentralWidget(button);


    //Declare Quit Action
    quitAction = new QAction("Quit"); // This memory is not managed by the window
                                      // You have to release it yourself
    connect(quitAction,&QAction::triggered,[=](){
        QApplication::quit();
    });

    //Add menus
    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    //Add status bar message
    statusBar()->showMessage("Uploading file ...",0);
    statusBar()->clearMessage();

}


QSize MainWindow::sizeHint() const
{
    return QSize(800,500);
}
