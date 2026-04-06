#include "../inc/Serialize.hpp"
#include "../inc/Data.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main (void)
{
    Data dat;
    uintptr_t ptr;
    Data *res;

    dat.num = 42;
    dat.text = "Up To You";
    std::cout   << std::endl
                << ":::Before:::" << std::endl
                << "dat num: " << dat.num 
                << std::endl
                << "dat text: " << dat.text
                << std::endl
                << "dat address: " << &dat
                << std::endl << std::endl;

    ptr = Serialize::serialize(&dat);
    res = Serialize::deserialize(ptr);

    std::cout   << ":::After:::" << std::endl
                << "res num: " << res->num 
                << std::endl
                << "res text: " << res->text
                << std::endl
                << "res address: " << res
                << std::endl << std::endl;
    
    if (&dat == res)
        std::cout << GREEN << "dat address == res address" << RESET << std::endl << std::endl;
    else
        std::cout << RED << "dat address != res address" << RESET << std::endl << std::endl;
    
       return (0);
}