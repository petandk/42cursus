#ifndef EASYFIND_TPP
# include "easyfind.hpp"
#endif

#include <algorithm>
#include <stdexcept>

template<typename T>
int easyfind(const T &container,const int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return std::distance(container.begin(), it);
    throw std::out_of_range("Cannot find the value inside the container.");
}