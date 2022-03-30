#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:


    // QWidget interface
private:
    QSize sizeHint() const;
    QAction * quitAction;
};

#endif // MAINWINDOW_H
