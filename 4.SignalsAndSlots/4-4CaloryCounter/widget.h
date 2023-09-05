#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void ChangeValue(double *ptr, double value);
    const double & calculate_calories();
private:
    Ui::Widget *ui;
    double m_weight;
    double m_time;
    double m_speed;
    double m_calory_count;
};
#endif // WIDGET_H
