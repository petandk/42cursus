#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include <iostream>

A::A()
{
    #ifdef DEBUG
        std::cout << "Constructor for A called" << std::endl;
    #endif
}

A::~A()
{
    #ifdef DEBUG
        std::cout << "Destructor for A called" << std::endl;
    #endif
}