#include <QCoreApplication>
#include <QDebug>
#include <memory>
#include "house.h"

void do_stuff(){

    //Qt Parent Child relationship
    //House* p_parent = new House(nullptr,"Parent");

    //Can even manage the parent through smart pointers if necessary
    std::unique_ptr<House> p_parent  {new House(nullptr,"Parent")};

    House* p_house1 = new House(p_parent.get(),"House1");

    House* p_house2 = new House(p_parent.get(),"House2");

    //delete p_parent;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Starting...";
    do_stuff();
    qDebug() << "Ending...";

    return a.exec();
}
