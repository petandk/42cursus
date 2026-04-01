#include "../inc/Serialize.hpp"
#include "../inc/Data.hpp"

#include <iostream>

Serialize::Serialize()
{
    #ifdef DEBUG
        std::cout << "Constructor called" << std::endl;
    #endif
}

Serialize::Serialize(const Serialize &other)
{
    (void) other;
}

Serialize &Serialize::operator=(const Serialize &other)
{
    (void) other;
    return (*this);
}

Serialize::~Serialize()
{
    #ifdef DEBUG
        std::cout << "Destructor called" << std::endl;
    #endif
}

uintptr_t Serialize::serialize(Data *ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}

