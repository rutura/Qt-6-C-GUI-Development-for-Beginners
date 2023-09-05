#ifndef WIDGET_H
#define WIDGET_H

#pragma once
#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_saveButton_clicked();
    void on_loadButton_clicked();

private:
    Ui::Widget *ui;
    QList<QColor> m_color_list;
    QString m_css;

    void save_color( QString key, QColor color);
    QColor load_color(QString key);
    void set_loaded_color( QString key, int index, QPushButton * button);
};
#endif // WIDGET_H
