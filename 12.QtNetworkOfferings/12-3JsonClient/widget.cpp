#include "widget.h"
#include "./ui_widget.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , net_manager(new QNetworkAccessManager(this))
    ,  net_reply(nullptr)
    , m_data_buffer(new QByteArray)


{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete m_data_buffer;
    delete ui;
}


void Widget::on_fetchButton_clicked()
{
    //Initialize our API data
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    net_reply = net_manager->get(request);
    connect(net_reply,&QIODevice::readyRead,this,&Widget::dataReadyRead);
    connect(net_reply,&QNetworkReply::finished,this,&Widget::dataReadFinished);

}

void Widget::dataReadyRead()
{
     m_data_buffer->append(net_reply->readAll());
}

void Widget::dataReadFinished()
{
    if( net_reply->error())
     {
         qDebug() << "Error : " << net_reply->errorString();
     }else
     {
        qDebug() << "Data fetch finished : " << QString(*m_data_buffer);

        //Turn the data into a json document
        QJsonDocument doc = QJsonDocument::fromJson(*m_data_buffer);

        /*
        //What if you get an object from the server
        QJsonDocument objectDoc = QJsonDocument::fromJson(*mDataBuffer);
        QJsonObject obObject = objectDoc.toVariant().toJsonObject();
        */

        //Turn document into json array
        QJsonArray array = doc.array();

        for ( int i = 0; i < array.size(); i++)
        {
            QJsonObject object = array.at(i).toObject();
            QVariantMap map = object.toVariantMap();
            QString title = map["title"].toString();
            ui->listWidget->addItem("["+ QString::number(i+1) + "] " + title);

        }
     }
}

