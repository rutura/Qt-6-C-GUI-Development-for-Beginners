#include <iostream>

int main()
{
    //Declaring variables
    std::string hello = "Hello World";
    int count = 7;

    std::cout << "The message is :"<<hello << std::endl;
    std::cout << "The count is : "<< count << std::endl;
    std::cout << "----------" << std::endl;
    //data type sizes
    std::cout << "Size of int : " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of char :"<< sizeof(char) << "bytes" << std::endl;
    std::cout << "Size of bool :"<< sizeof(bool) << "bytes" << std::endl;
    std::cout << "Size of float :"<< sizeof(float) << "bytes" << std::endl;
    std::cout << "Size of double :"<< sizeof(double) << "bytes" << std::endl;
    std::cout << "Size of wchar_t :"<< sizeof(wchar_t) << "bytes" << std::endl;
    std::cout << "----------" << std::endl;

    //Modifiers
    std::cout << "Size of short int : " << sizeof(short int) << " bytes" <<std::endl;
    std::cout << "Size of unsigned short int : " << sizeof(unsigned short int) << " bytes" << std::endl;
    std::cout << "Size of unsigned int : " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "Size of int : " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of signed int : " << sizeof(signed int) << " bytes" << std::endl;
    std::cout << "Size of long int : " << sizeof(long int) << " bytes" << std::endl;
    std::cout << "Size of unsigned long long int : " << sizeof(unsigned long long int) << " bytes" << std::endl;
    std::cout << "Size of signed char : " << sizeof(signed char) << " bytes" << std::endl;
    std::cout << "Size of unsigned char : " << sizeof(unsigned char) << " bytes" << std::endl;
    std::cout << "Size of char : " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of float : " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double : " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of long double : " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << "----------" << std::endl;

    //Unsigned (positive numbers)
    unsigned int var1 = -200;
    std::cout << "var1 is :" << var1 <<std::endl;


    return 0;
}
