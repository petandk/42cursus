#include "../inc/Base.hpp"
#include "../inc/B.hpp"
#include <iostream>

B::B()
{
    #ifdef DEBUG
        std::cout << "Constructor for B called" << std::endl;
    #endif
}

B::~B()
{
    #ifdef DEBUG
        std::cout << "Destructor for B called" << std::endl;
    #endif
}