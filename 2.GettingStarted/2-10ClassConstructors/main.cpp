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

//Box class
class Box
{
public:
    Box(int w, int l, int h):m_r(w,l),m_height(h) // Initializer list
    {
        std::cout << "Para Constructor Called" << std::endl;
    }

    int get_volume()
    {
        return m_r.get_area() * m_height;
    }

private:
    Rectangle m_r;
    int m_height;
};



int main()
{
    Rectangle r(10,20);
    std::cout << "area : " << r.get_area() << std::endl;

    Box b(10,20,30);
    std::cout << "volume : " << b.get_volume() << std::endl;
    return 0;
}
