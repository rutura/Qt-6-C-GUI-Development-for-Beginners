#include "house.h"
#include <QDebug>

House::House(QObject *parent, const QString &descr)
    : QObject(parent), m_descr((descr))
{
    qDebug() << "House object constructed";
}

House::~House()
{
    qDebug() << "House object : " << m_descr << " is dying...";
}

void House::print_info() const
{
   qDebug() << "House : " << m_descr;
}
