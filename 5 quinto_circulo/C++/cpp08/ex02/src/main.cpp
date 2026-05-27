#include "../inc/MutantStack.hpp"
#include <iostream>

int main (void)
{
    MutantStack<int> mut;

    mut.push(4);
    mut.push(2);
    mut.push(40);
    mut.push(20);
    
    std::cout << "Top: " << mut.top()  << " (expected 20)" << std::endl
                << "Size: " << mut.size() << " (expected 4)" << std::endl;
    
    std::cout << "Elements: " << std::endl;
    for (MutantStack<int>::iterator it = mut.begin(); it != mut.end(); it++)
        std::cout << "\t" << *it << " " << std::endl;
    
    MutantStack<int> cp(mut);
    cp.pop();
    std::cout << "Copy and pop:" << std::endl;
    std::cout << "Top: " << cp.top()  << " (expected 40)" << std::endl
                << "Size: " << cp.size() << " (expected 3)" << std::endl;
    
    MutantStack<int> ass;

    ass = mut;
    ass.push(42);
    std::cout << "Asignation and push:" << std::endl;
    std::cout << "Top: " << cp.top()  << " (expected 42)" << std::endl
                << "Size: " << cp.size() << " (expected 5)" << std::endl;
    
    return (0);
}