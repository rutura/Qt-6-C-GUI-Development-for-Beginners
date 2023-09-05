#include "widget.h"
#include "ui_widget.h"
#include <QSettings>
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_css = "background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
            "stop: 0 %1, stop: 1 #FFFFFF);";
    QPushButton* button;
    QGridLayout* layout = ui->gridLayout;
    for (int i = 0, buttonsn = 9; i < buttonsn; i++){
        m_color_list.append(QColor::fromRgb(0xe3e3e3));  // Initial color of buttons in Windows
        button = qobject_cast<QPushButton*>(layout->itemAt(i)->widget());
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QString last_letter = button->objectName().right(1);
        button->setText("Button " +  (last_letter == "n" ? "1" : last_letter));
        connect(button, &QPushButton::clicked, [=](){
            QColor color = QColorDialog::getColor(m_color_list[i], this, "Choose Background Color");
            if(color.isValid()){
                m_color_list[i] = color;  // Save the color in the list in memory
                button->setStyleSheet(m_css.arg(color.name()));
            }
        });
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_saveButton_clicked()
{
    for (int i = 0, buttonsn = 9; i < buttonsn; i++){
        save_color("button" + QString::number(i+1), m_color_list[i]);
    }
}

void Widget::on_loadButton_clicked()
{
    QGridLayout* layout = ui->gridLayout;
    for (int i = 0, buttonsn = 9; i < buttonsn; i++){
        QPushButton* button = qobject_cast<QPushButton*>(layout->itemAt(i)->widget());
        set_loaded_color("button" + QString::number(i+1), i, button);
        // Actually, here we use not a real button number, but the one used in GridLayout->itemAt()
    }
}

void Widget::save_color(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("Blikoon","SettingsDemo");

    settings.beginGroup("ButtonColor");
    settings.setValue(key + "r",red);
    settings.setValue(key + "g",green);
    settings.setValue(key + "b",blue);
    settings.endGroup();
}

QColor Widget::load_color(QString key)
{
    int red;
    int green;
    int blue;
    QSettings settings("Blikoon","SettingsDemo");

    settings.beginGroup("ButtonColor");

    red = settings.value(key+"r",QVariant(0)).toInt();
    green = settings.value(key+"g",QVariant(0)).toInt();
    blue = settings.value(key+"b",QVariant(0)).toInt();
    settings.endGroup();

    return QColor(red,green,blue);
}

void Widget::set_loaded_color(QString key, int index, QPushButton *button)
{
    QColor color = load_color(key);
    button->setStyleSheet(m_css.arg(color.name()));
}
