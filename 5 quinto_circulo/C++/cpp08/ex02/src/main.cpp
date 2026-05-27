#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "----------------------------------------------------" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it2 = lst.begin();
    std::list<int>::iterator ite2 = lst.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    return 0;
}

/*
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
*/