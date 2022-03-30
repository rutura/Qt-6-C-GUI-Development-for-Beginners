#include "widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    //First Name
    QLabel * first_name_label = new QLabel("First Name",this);
    first_name_label->setMinimumSize(70,50);
    first_name_label->move(10,10);

    QLineEdit * first_name_line_edit = new QLineEdit(this);
    first_name_line_edit->setMinimumSize(200,50);
    first_name_line_edit->move(100,10);

    //last_name Name
    QLabel * last_name_label = new QLabel("Last Name",this);
    last_name_label->setMinimumSize(70,50);
    last_name_label->move(10,70);

    QLineEdit * last_name_line_edit = new QLineEdit(this);
    last_name_line_edit->setMinimumSize(200,50);
    last_name_line_edit->move(100,70);


    //City
    QLabel * city_label = new QLabel("City",this);
    city_label->setMinimumSize(70,50);
    city_label->move(10,130);

    QLineEdit * city_line_edit = new QLineEdit(this);
    city_line_edit->setMinimumSize(200,50);
    city_line_edit->move(100,130);

    QFont button_font("Times", 20, QFont::Bold);
    QPushButton * button = new QPushButton("Grab data",this);
    button->setFont(button_font);
    button->move(80,190);

    connect(button,&QPushButton::clicked,[=](){
        QString first_name = first_name_line_edit->text();
        QString last_name = last_name_line_edit->text();
        QString city = city_line_edit->text();

        if( !first_name.isEmpty() && !last_name.isEmpty() && !city.isEmpty())
        {
            //If neither field is empty we fall here
            qDebug() << " First name is : " << first_name;
            qDebug() << " Last name is : " << last_name;
            qDebug() << " City is : " << city;
        }else
        {
            qDebug() << "One the fields is empty ";
        }

    });


    //Respond to signals from QLineEdits
    /*
    //cursorPositionChanged
    connect(first_name_line_edit,&QLineEdit::cursorPositionChanged,[=](){
        qDebug() << "The current cursor position is : "
                    << first_name_line_edit->cursorPosition();
    });

    //editingFinished : emitted when user clicks enter or when line edit looses focus
    connect(first_name_line_edit,&QLineEdit::editingFinished,[=](){
        qDebug() << "Editing finished .";
    });

    //returnPressed
    connect(first_name_line_edit,&QLineEdit::returnPressed,[=](){
        qDebug() << "Return Pressed .";
    });

    //selectionChanged
    connect(first_name_line_edit,&QLineEdit::selectionChanged,[=](){
        qDebug() << "Selection Changed .";
    });
    */

    //textChanged
    /*
    connect(first_name_line_edit,&QLineEdit::textChanged,[=](){
        qDebug() << "Selection Changed to :"  <<  first_name_line_edit->text();
    });
    */

    //textEdited
    /*
    connect(first_name_line_edit,&QLineEdit::textEdited,[=](){
        qDebug() << "Selection edited and changed to :"  <<  first_name_line_edit->text();
    });
    */


    //Change text in QLineEdit programmaticaly
    //last_name_line_edit->setText("Say your last name");

    //Hint text
    first_name_line_edit->setPlaceholderText("First name");
    last_name_line_edit->setPlaceholderText("Last Name");
    city_line_edit->setPlaceholderText("City");

}

Widget::~Widget()
{
}

