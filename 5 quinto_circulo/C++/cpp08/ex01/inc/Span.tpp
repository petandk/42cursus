#ifndef SPAN_HPP
# include "Span.hpp"
#endif

#include <vector>
#include <stdexcept>

template <typename Iterator>
void Span::onePunchSpan(Iterator begin, Iterator end)
{
    std::vector<int>tmp;
    for(Iterator it = begin; it != end; it++)
        tmp.push_back(*it);
    if (this->_vec.size() + tmp.size() > this->_max)
        throw std::out_of_range("Not enough space for range!");

    for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end(); it++)
        this->_vec.push_back(*it);
}