#ifndef BOX_H
#define BOX_H

#include <iostream>
#include "rectangle.h"

//Box class
class Box
{
public:
    Box(int w, int l, int h);
    int get_volume();

private:
    Rectangle m_r;
    int m_height;
};





#endif // BOX_H
