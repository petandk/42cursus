#include <iostream>
#include <exception>
#include "../inc/BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    try{
        if (argc == 2)
        {
            //argv[] are char *, so I just cast it
            std::string file = std::string("files/") + argv[1];
            return (btcExchange(file));
        }
        std::cout << "Error: could not open file." << std::endl;
        #ifdef DEBUG
            std::cout << "\033[1;33m[DEBUG] Do you have the database & input files inside the files folder??\033[0m" << std::endl;
        #endif
        return (1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return(0);
}