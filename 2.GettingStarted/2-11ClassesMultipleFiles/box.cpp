#include "box.h"

Box::Box(int w, int l, int h):m_r(w,l),m_height(h) // Initializer list
{
    std::cout << "Para Constructor Called" << std::endl;
}
int Box::get_volume()
{
    return m_r.get_area() * m_height;
}
