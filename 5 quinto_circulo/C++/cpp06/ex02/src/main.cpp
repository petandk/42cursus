#include "../inc/Base.hpp"
#include "../inc/Utils.hpp"

#include <cstdlib> 
#include <ctime>

int main(void)
{
    std::srand(std::time(0));

    Base *guineaPig = generate();

    identify(guineaPig);
    identify(*guineaPig);

    delete guineaPig;

    return (0);
}