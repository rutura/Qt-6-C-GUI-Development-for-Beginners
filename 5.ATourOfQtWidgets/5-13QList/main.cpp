#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Declare the list
    QList<QString> stringList;

    //Put data in the list
    stringList << " I am " << " lovin " << " Qt";// [ "I am", " loving ", " Qt"]
    stringList.append(" a ");
    stringList.append( " lot !");

    //Get the data from the list
    qDebug() << "The first element is " << stringList[0];
    qDebug() << "The second element is " << stringList[1];
    qDebug() << "The third element is " << stringList[2];
    //Get the number of elements
    qDebug() <<  "The number of elements in my list is : " << stringList.count();

    //Loop through the elements
    for( int i = 0 ; i < stringList.count() ; i++)
    {
        qDebug() << "The element at index "<< QString::number(i)
                        << " is " << stringList.at(i);
    }


    return a.exec();
}
