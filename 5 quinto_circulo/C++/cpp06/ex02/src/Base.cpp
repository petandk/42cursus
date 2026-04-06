#include "../inc/Base.hpp"
#include <iostream>

Base::~Base()
{
    #ifdef DEBUG
        std::cout << "Base destructor called" << std::endl;
    #endif
};