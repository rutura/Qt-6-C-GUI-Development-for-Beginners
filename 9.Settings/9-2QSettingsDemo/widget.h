#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColor>
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
    void on_buttonOne_clicked();

    void on_buttonTwo_clicked();

    void on_buttonThree_clicked();

    void on_buttonFour_clicked();

    void on_buttonFive_clicked();

    void on_buttonSix_clicked();

    void on_buttonSeven_clicked();

    void on_buttonEight_clicked();

    void on_buttonNine_clicked();

    void on_saveButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::Widget *ui;
    QList<QColor> m_color_list;

    void save_color( QString key, QColor color);
    QColor load_color(QString key);

    void set_loaded_color( QString key, int index, QPushButton * button);
};
#endif // WIDGET_H
