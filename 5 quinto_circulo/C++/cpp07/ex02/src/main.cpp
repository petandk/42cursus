#include "../inc/Array.hpp"
#include <iostream>

int main(void)
{
    std::cout << std::endl << "------Default constructor------" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << std::endl << "------Constructor with size(5)------" << std::endl;
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
    std::cout << std::endl << "------Assignment operator------" << std::endl;
    Array<int> d;
    d = b;
    d[0] = 42;
    std::cout << "b[0] (should stay 0) = " << b[0] << std::endl;
    std::cout << "d[0] (should be 42) = " << d[0] << std::endl;
    std::cout << std::endl << "------Const access------" << std::endl;
    const Array<int> e(b);
    std::cout << "e[2] (should be 20) = " << e[2] << std::endl;
    std::cout << std::endl << "------Out of range exception------" << std::endl;
    try
    {
        std::cout << b[5] << std::endl;
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    std::cout << std::endl << "------Out of range on empty array------" << std::endl;
    try
    {
        std::cout << a[0] << std::endl;
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return (0);
}