#ifndef EASYFIND_TPP
# include "easyfind.hpp"
#endif

#include <stdexcept>

template<typename T>
int easyfind(const T &container,const int value)
{
    int position = 0;

    for(typename T::const_iterator it = container.begin(); it != container.end(); it++, position++)
        if(*it == value)
            return (position);
    throw std::out_of_range("Cannot find the value inside the container.");
}