#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span{
    private:
        unsigned int _max;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int max);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int toAdd);

        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);
        
        template <typename Iterator>
        void onePunchSpan(Iterator begin, Iterator end);
};
# include "Span.tpp"
#endif