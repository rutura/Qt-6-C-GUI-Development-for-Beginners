#ifndef HOUSE_H
#define HOUSE_H

#include <QObject>

class House : public QObject
{
    Q_OBJECT
public:
    explicit House(QObject *parent = nullptr,const QString &descr ="");
    ~House();//Destructor : Called when the object dies
    void print_info()const;

private :
    QString m_descr;
};

#endif // HOUSE_H
