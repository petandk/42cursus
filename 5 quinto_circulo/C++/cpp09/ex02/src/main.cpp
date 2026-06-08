#include "../inc/PmergeMe.hpp"

int main (int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "\033[0;31mError: no values provided" << std::endl
            << "\t\033[1;33mUsage example: ./PmergeMe 9 7 6 3 8 2\033[0m" << std::endl;
        return (1);
    }
    PmergeMe pm;
    if (!pm.readValues(argc, argv))
        return (1);
    #ifdef DEBUG
        pm.debugValues();
    #endif
    pm.FordJohnson();
    
    return (0);
}