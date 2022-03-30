#include <iostream>


class Rectangle{
public :
    void set_width(int width);
    void set_height(int height);
    double get_area()const;

private:
    double m_width;
    double m_height;
};

//Implementations
void Rectangle::set_width(int width){
    m_width = width;
}
void Rectangle::set_height(int height){
    m_height = height;
}
double Rectangle::get_area()const{
    return m_width * m_height;
}

int main()
{
    Rectangle r;
    r.set_width(10.0);
    r.set_height(30.0);
    std::cout << "area : " << r.get_area() << std::endl;

    //Can't access private data of the class from the outside
    //std::cout << "width : " << r.m_width << std::endl;

    return 0;
}
