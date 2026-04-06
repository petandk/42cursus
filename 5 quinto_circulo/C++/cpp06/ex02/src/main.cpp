#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <cstdlib> 
#include <ctime>
#include <iostream>

Base *generate(void)
{
    switch(std::rand() % 3)
    {
        case 0:    
                #ifdef DEBUG
                    std::cout << "Generated A" << std::endl;
                 #endif
                return (new A());
        case 1:
                #ifdef DEBUG
                    std::cout << "Generated B" << std::endl;
                 #endif
                return (new B());
        case 2:
        default:
                #ifdef DEBUG
                    std::cout << "Generated C" << std::endl;
                #endif
                return (new C());
    }
}

void identify(Base *p)
{
    std::cout << "Pointer identified as: " << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "class C" << std::endl;
    else
        std::cout << "NULL or error" << std::endl;
}

void identify(Base &p)
{
    std::cout << "Reference identified as: " << std::endl;
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "class A" << std::endl;
        return ;
    }
    catch(...){}
        try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "class B" << std::endl;
        return ;
    }
    catch(...){}
        try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "class C" << std::endl;
        return ;
    }
    catch(...){}
    std::cout << "NULL or error" << std::endl;
}

int main(void)
{
    std::srand(std::time(0));

    Base *guineaPig = generate();

    identify(guineaPig);
    identify(*guineaPig);

    delete guineaPig;

    return (0);
}