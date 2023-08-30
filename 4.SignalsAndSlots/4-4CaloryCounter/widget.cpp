#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initializer the members with values from the ui
    m_weight = ui->weightSpinBox->value();
    m_time = ui->timeSpinBox->value();
    m_speed = ui->speedSpinBox->value();
    ui->caloryCountLabel->setText(QString::number(calculate_calories()));

    //Connect ui components to respective slots
    connect(ui->weightSpinBox, &QDoubleSpinBox::valueChanged,
            [&](){ChangeValue(&m_weight, ui->weightSpinBox->value() );});
    connect(ui->timeSpinBox, &QDoubleSpinBox::valueChanged,
            [&](){ChangeValue(&m_time, ui->timeSpinBox->value() );});
    connect(ui->speedSpinBox, &QDoubleSpinBox::valueChanged,
            [&](){ChangeValue(&m_speed, ui->speedSpinBox->value() );});

}
Widget::~Widget(){
    delete ui;
}


inline const double & Widget::calculate_calories(){
    //CB = [0.0215 x KPH^3 - 0.1765 x KPH^2 + 0.8710 x KPH + 1.4577] x WKG x T
    m_calory_count = ( (0.0215 * (m_speed * m_speed * m_speed)) - (0.1765 * (m_speed * m_speed))
                            +(0.8710 * m_speed) + 1.4577) * m_weight * m_time;
    return m_calory_count;
}
inline void Widget::ChangeValue(double *ptr, double value){
    *ptr = value;
    ui->caloryCountLabel->setText(QString::number(calculate_calories()));
}
