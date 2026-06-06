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
/*
    For a vector like [1, 2, 3]
    The loop checks elements in pairs:
    first loop  -> (1, 2)
    second loop -> (3, end)

    If next == fighters.end(), it means there is one element left
    (odd amount of numbers), so we put that last one in losers.

    Iterator basics:
    ++it      moves to the next element
    *it       gets the element
    it->first gets the first value in the pair
    it->second gets the second value in the pair
*/
void PmergeMe::fightVector(std::vector<std::pair<unsigned int, int> > &fighters, 
                            std::vector<std::pair<unsigned int, int> > &winers,
                            std::vector<std::pair<unsigned int, int> > &losers)
{   
    winers.clear();
    losers.clear();
    std::vector<std::pair<unsigned int, int> >::iterator fg = fighters.begin();
    while (fg != fighters.end())
    {
        std::vector<std::pair<unsigned int, int> >::iterator next = fg;
        ++next;
        if (next == fighters.end())
        {
            losers.push_back(*fg);
            break;
        }

        if (fg->first > next->first)
        {
            winers.push_back(*fg);
            losers.push_back(*next);
        }
        else
        {
            winers.push_back(*next);
            losers.push_back(*fg);
        }
        fg = next;
        ++fg;
    }
}

std::vector<int> PmergeMe::jacobsthal(int size)
{
    std::vector<int> retSeq;

    if (size <= 0)
        return (retSeq);

    retSeq.push_back(1);
    if (size == 1)
        return (retSeq);

    int prev1 = 1;
    int prev2 = 1;
    int next = 3;

    while (next <= size)
    {
        retSeq.push_back(next);
        prev2 = prev1;
        prev1 = next;
        next = prev1 + 2 * prev2;
    }
    return (retSeq);
}

std::vector<int> PmergeMe::jacobsthalVectorSeq(int n)
{
    std::vector<int> retSeq;
    int jacob = 1;
    if (n <= 0)
        return (retSeq);
    retSeq.push_back(jacob);
    if (n == 1)
        return (retSeq);
    while (jacob <= n && retSeq.size() <= n)
    {
         //jacob = nextJacobsthal(retSeq.size() + 1);
    }

}

void PmergeMe::jacobsthalVector(std::vector<std::pair<unsigned int, int> > &winers,
                        std::vector<std::pair<unsigned int, int> > &losers)
{

}

std::vector<std::pair<unsigned int, int> > PmergeMe::sortVector(std::vector<std::pair<unsigned int, int> > &vec)
{
    // special case for when vec.size == 1 from beginning
    if(vec.size() <= 1)
        return (vec);

    std::vector<std::pair<unsigned int, int> > winers;
    std::vector<std::pair<unsigned int, int> > losers;
    //sort winers (going down):
    fightVector(vec, winers, losers);
    //recursive calls:
    winers = sortVector(winers);
    //sort losers (coming back):
    jacobsthalVector(winers, losers);
    return (winers);
}

void PmergeMe::FordJohnson(void)
{
    this->sortVector(this->_valuesV);
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