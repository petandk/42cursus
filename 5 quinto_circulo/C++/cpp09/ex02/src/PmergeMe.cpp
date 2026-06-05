#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other):_valuesV(other._valuesV), _valuesD(other._valuesD)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_valuesV = other._valuesV;
        this->_valuesD = other._valuesD;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

static unsigned int parseAndCast(const std::string  &value)
{
    const std::string RED = "\033[31m";
    const std::string RESET = "\033[0m";
    std::stringstream ss(value);
    unsigned int ret;
    std::string other;
    if (value.empty())
        throw std::invalid_argument(RED + "Error: empty value in parameters" + RESET);
    if (value.find('-') != std::string::npos)
        throw std::invalid_argument(RED + "Error: negative parameter found: " + value + RESET);
    if (!(ss >> ret) || ss >> other)
        throw std::invalid_argument(RED + "Error:invalid characters in parameter: " + value + RESET);
    return (ret);
}

bool PmergeMe::readValues(int argc, char *argv[])
{
    try
    {
        for (int i = 1; i < argc; i++)
        {
            std::pair <unsigned int, int> p = std::make_pair(parseAndCast(argv[i]), i - 1);
            this->_valuesV.push_back(p);
            this->_valuesD.push_back(p);
        }
        return (true);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return (false);
    }
}

static bool tournament()
{

}

bool PmergeMe::sort(void)
{
    
}

#ifdef DEBUG
    void PmergeMe::debugValues(void)
    {
        std::cout <<  "\033[1;33m\t----- debug message: containters after readValues -----" << std::endl;
        
        std::vector<std::pair<unsigned int, int> >::iterator itV = this->_valuesV.begin();
        std::deque<std::pair<unsigned int, int> >::iterator itD = this->_valuesD.begin();
        while (itV != this->_valuesV.end() && itD != this->_valuesD.end())
        {
            std::cout << "\t\tVector value: " << itV->first << " | Index: " << itV->second << std::endl;
            std::cout << "\t\t Deque value: " << itD->first << " | Index: " << itD->second << std::endl;
            itV++;
            itD++;
        }
        std::cout << "\033[0m";
    }   
#endif