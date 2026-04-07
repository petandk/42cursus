#include "../inc/Array.hpp"
#include <iostream>

int main(void)
{
    std::cout << std::endl << "------Default constructor------" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << std::endl << "------Constructor with size------" << std::endl;
    Array<int> b(5);
    for(unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;
    for(unsigned int i = 0; i < b.size(); i++)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    std::cout << std::endl << "------Copy constructor------" << std::endl;
    Array<int> c(b);
    c[0] = 999;
    std::cout << "b[0] (should stay 0) = " << b[0] << std::endl;
    std::cout << "c[0] (should be 999) = " << c[0] << std::endl;
    return (0);
}