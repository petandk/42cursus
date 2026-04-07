#ifndef ARRAY_HPP
# include "Array.hpp"
#endif

#include <iostream>

template<typename T>
Array<T>::Array():_data(0), _size(0)
{
    #ifdef DEBUG
        std::cout << "Default constructor called" << std::endl;
    #endif
}

template<typename T>
Array<T>::Array(unsigned int n):_data(new T[n]()), _size(n)
{
    #ifdef DEBUG
        std::cout << "Constructor with size called" << std::endl;
    #endif
}

template<typename T>
Array<T>::Array(const Array &other):_data(0), _size(0)
{
    *this = other;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{

    if (this != &other)
    {
        delete[] this->_data;
        if (other._size <= 0)
        {
            this->_data = 0;
            this->_size = other._size;
        }
        else
        {
            this->_data = new T[other._size];
            this->_size = other._size;
        }
        for(unsigned int i=0; i < other._size; i++)
            this->_data[i] = other._data[i];
    }
    return (*this);        
}

template<typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
    if(index >= this->_size)
        throw (std::out_of_range("Index out of range"));
    return (this->_data[index]);
}

template<typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if(index >= this->_size)
        throw (std::out_of_range("Index out of range"));
    return (this->_data[index]);
}

template<typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}