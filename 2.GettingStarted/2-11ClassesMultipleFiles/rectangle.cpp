#include "rectangle.h"

//Constructor Impementations
Rectangle::Rectangle(){
    std::cout << "No param constructor called" << std::endl;
}
Rectangle::Rectangle(int w,int l){
    std::cout << "Two param constructor called" << std::endl;
    m_width = w;
    m_length = l;
}

//Other methods
void Rectangle::setWidth( int width){
    m_width = width;
}
void Rectangle::setLength( int length){
    m_length = length;
}

int Rectangle::get_area() const
{
    return m_width * m_length;
}
