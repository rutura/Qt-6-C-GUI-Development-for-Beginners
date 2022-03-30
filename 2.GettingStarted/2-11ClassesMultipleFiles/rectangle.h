#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
public:
    //Constructors
    Rectangle();
    Rectangle(int w,int l);

    void setWidth( int width);
    void setLength( int length);
    int get_area()const;

private:
    int m_width;
    int m_length;
};



#endif // RECTANGLE_H
