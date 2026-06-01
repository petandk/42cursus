#include "../inc/RPN.hpp"

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: usage example: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
        return (1);
    }
    std::string operations = argv[1];
    if (!RPN(operations))
        std::cerr << "Error" << std::endl;
    return (0);
}