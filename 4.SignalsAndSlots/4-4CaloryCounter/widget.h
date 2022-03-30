#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"

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
       void calculate_calories();
       void weight_changed(double weight);
       void time_changed(double time);
       void speed_changed(double speed);

signals :
       void calory_count_changed();

private:
    Ui::Widget *ui;
    Person m_person;
    double m_time;
    double m_speed;
    double m_calory_count;
};
#endif // WIDGET_H
