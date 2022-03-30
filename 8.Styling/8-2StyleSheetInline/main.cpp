#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Set stylesheet to entire application
    //a.setStyleSheet("QPushButton{background-color : yellow; color : red;}");
    Widget w;
    w.show();
    return a.exec();
}
