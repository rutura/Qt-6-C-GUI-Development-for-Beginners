#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QChar>
#include <QRect>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello world!";
    qDebug() << "Date:" << QDate::currentDate();
    qDebug() << "Types:" << QString("String") << QChar('x') << QRect(0, 10, 50, 40);

    return a.exec();
}
