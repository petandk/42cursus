#include "../inc/Base.hpp"
#include "../inc/C.hpp"
#include <iostream>

C::C()
{
    #ifdef DEBUG
        std::cout << "Constructor for C called" << std::endl;
    #endif
}

C::~C()
{
    #ifdef DEBUG
        std::cout << "Destructor for C called" << std::endl;
    #endif
}