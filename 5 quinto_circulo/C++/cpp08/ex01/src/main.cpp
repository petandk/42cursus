#include "../inc/Span.hpp"
#include <iostream>
#include <vector>

#define INT_MAX 2147483647

int main(void)
{
    Span sp(10);
    try
    {
        sp.addNumber(INT_MAX);
        sp.addNumber((-INT_MAX) - 1);
        sp.addNumber(0);
        sp.addNumber(-1);
        sp.addNumber(1);
        sp.addNumber(1000000);
        sp.addNumber(-1000000);
        sp.addNumber(42);
        sp.addNumber(-42);
        sp.addNumber(INT_MAX - 1);

        std::cout << "Shortest: " << sp.shortestSpan() << " (expected 1)" << std::endl;
        std::cout << "Longest: " << sp.longestSpan()  << " (expected 4294967295)" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    Span sp2(5);
    std::vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i - 2);
    try
    {
        sp2.onePunchSpan(v.begin(), v.end());
        std::cout << "onePunch shortest: " << sp2.shortestSpan() << " (expected 1)"  << std::endl
                    << "onePunch longest: " << sp2.longestSpan() << " (expected 4)"  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "sp2 Error: " << e.what() << std::endl;
    }

    Span sp3(3);
    try
    {
        sp3.onePunchSpan(v.begin(), v.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << "Expected sp3 range exception: " << e.what() << std::endl;
    }
}
