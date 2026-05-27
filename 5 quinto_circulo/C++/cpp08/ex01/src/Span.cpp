#include "../inc/Span.hpp"

#include <stdexcept>
#include <algorithm>

Span::Span():_max(0){}

Span::Span(unsigned int max):_max(max){}

Span::Span(const Span &other):_max(other._max), _vec(other._vec){}

Span &Span::operator=(const Span &other)
{
    if(this != &other)
    {
        this->_max = other._max;
        this->_vec = other._vec;
    }
    return (*this);
}

Span::~Span(void){}

void Span::addNumber(int toAdd)
{
    if (this->_max <= this->_vec.size())
        throw std::out_of_range("Vector is full!");
    this->_vec.push_back(toAdd);
}

unsigned int Span::shortestSpan(void)
{
    if (this->_vec.size() < 2)
        throw std::out_of_range("Not enough elements!");

    std::vector<int> ordered(this->_vec);
    std::sort(ordered.begin(), ordered.end());

    unsigned int ss = ordered[1] - ordered[0];
    for (size_t i = 1; i < ordered.size() - 1; i++)
    {
        unsigned int diff = ordered[i + 1] - ordered[i];
        if ( diff < ss)
            ss = diff;
    }
    return (ss);
}

unsigned int Span::longestSpan(void)
{
    if (this->_vec.size() < 2)
        throw std::out_of_range("Not enough elements!");

    std::vector<int> ordered(this->_vec);
    std::sort(ordered.begin(), ordered.end());

    return (ordered[ordered.size() - 1] - ordered[0]);
}