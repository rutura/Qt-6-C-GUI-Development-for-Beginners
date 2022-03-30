#include "widget.h"
#include "./ui_widget.h"
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Initialization
    net_manager =  new QNetworkAccessManager(this);
    net_reply = nullptr;
    m_data_buffer = new QByteArray();

    //Send out the request
    QNetworkRequest request;
    //request.setUrl(QUrl("https://www.qt.io"));
    request.setUrl(QUrl("https://www.github.com"));

    net_reply = net_manager->get(request);

    connect(net_reply,&QIODevice::readyRead,this,&Widget::dataReadyToRead);
    connect(net_reply,&QNetworkReply::finished,this,&Widget::dataReadFinished);
}

Widget::~Widget()
{
    delete m_data_buffer;
    delete ui;
}

void Widget::dataReadyToRead()
{
    qDebug()<< "Some data available";
    m_data_buffer->append(net_reply->readAll());
}

void Widget::dataReadFinished()
{
    if( net_reply->error())
    {
        qDebug() << " Error : " << QString(*m_data_buffer) ;
    }else
    {
        ui->textEdit->setPlainText(QString(*m_data_buffer));
    }
}

