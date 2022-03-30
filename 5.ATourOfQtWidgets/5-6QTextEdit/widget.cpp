#include "widget.h"
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
    setFixedSize(400,400);
}

Widget::~Widget()
{
}

void Widget::setupUi()
{

    QFont labelFont("Times", 10, QFont::Bold);
    QLabel * mLabel = new QLabel("This is my text",this);
    mLabel->setFont(labelFont);
    mLabel->move(100,25);

    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->move(70,55);

    //textChanged
    connect(textEdit,&QTextEdit::textChanged,[=](){
        qDebug() << "Text Changed";
    });

    /*
             * Copy
             * paste
             * undo
             * redu
             * setHtml
             * setPlainText
             * */

        //Copy , Cut and Paste
        QPushButton * copyButton = new QPushButton("Copy",this);
        copyButton->setMinimumSize(50,25);
        copyButton->move(10,250);
        connect(copyButton,&QPushButton::clicked,[=](){
            textEdit->copy();
        });

        QPushButton * cutButton = new QPushButton("Cut",this);
        cutButton->setMinimumSize(50,25);
        cutButton->move(110,250);
        connect(cutButton,&QPushButton::clicked,[=](){
            textEdit->cut();
        });

        QPushButton * pasteButton = new QPushButton("Paste",this);
        pasteButton->setMinimumSize(50,25);
        pasteButton->move(210,250);
        connect(pasteButton,&QPushButton::clicked,[=](){
            textEdit->paste();
        });

        //Undo Redo
        QPushButton * undoButton = new QPushButton("Undo",this);
        undoButton->setMinimumSize(50,25);
        undoButton->move(10,280);
        connect(undoButton,&QPushButton::clicked,[=](){
            textEdit->undo();
        });

        QPushButton * redoButton = new QPushButton("Redo",this);
        redoButton->setMinimumSize(50,25);
        redoButton->move(110,280);
        connect(redoButton,&QPushButton::clicked,[=](){
            textEdit->redo();
        });


        //Set text and html to the text edit
        QPushButton * plainTextButton = new QPushButton("Plain Text",this);
        plainTextButton->setMinimumSize(100,25);
        plainTextButton->move(10,310);
        connect(plainTextButton,&QPushButton::clicked,[=](){
            textEdit->setPlainText("Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?");
        });

        QPushButton * htmlButton = new QPushButton("Html",this);
        htmlButton->setMinimumSize(100,25);
        htmlButton->move(120,310);
        connect(htmlButton,&QPushButton::clicked,[=](){
            textEdit->setHtml("<h1>Kigali Districts</h1><p>The city of Kigali has three districts : </br> <ul> <li>Gasabo</li> <li>Nyarugenge</li><li>Kicukiro</li></ul></p>");
        });


        //Grab text and html
        QPushButton * grabTextButton = new QPushButton("Grab Text",this);
        grabTextButton->setMinimumSize(100,24);
        grabTextButton->move(10,340);
        connect(grabTextButton,&QPushButton::clicked,[=](){
            qDebug() << "The plain text inside the text edit is : " << textEdit->toPlainText();
        });

        QPushButton * grabHtmlButton = new QPushButton("GrabHtml",this);
        grabHtmlButton->setMinimumSize(100,25);
        grabHtmlButton->move(120,340);
        connect(grabHtmlButton,&QPushButton::clicked,[=](){
            qDebug() << "The html inside the text edit is : " << textEdit->toHtml();
        });



}

