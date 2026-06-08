#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    #ifdef DEBUG
    this->_contV = 0;
    this->_contD = 0;
    #endif
}

PmergeMe::PmergeMe(const PmergeMe &other):_valuesV(other._valuesV), _valuesD(other._valuesD)
{
    #ifdef DEBUG
        this->_contV = other._contV;
        this->_contD = other._contD;
    #endif
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_valuesV = other._valuesV;
        this->_valuesD = other._valuesD;
        #ifdef DEBUG
            this->_contV = other._contV;
            this->_contD = other._contD;
        #endif
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

// Max comparisons allowed by Merge-Insertion Sort.
// sum(ceil(log2(3/4 * i))). Had to hack log2 with std::log() / std::log(2) for c++98.
#ifdef DEBUG
    #include <cmath>

    size_t PmergeMe::FordJohnsonTheoricalMax(size_t n)
    {
        size_t limit = 0;
        for (size_t i = 1; i <= n; ++i)
        {
            limit += std::ceil(std::log(3.0 * i / 4.0) / std::log(2.0));
        }
        return limit;
    }
#endif

unsigned int PmergeMe::parseAndCast(const std::string  &value)
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
            std::vector<unsigned int> v;
            std::deque<unsigned int> d;
            v.push_back(parseAndCast(argv[i]));
            d.push_back(parseAndCast(argv[i]));
            this->_valuesV.push_back(v);
            this->_valuesD.push_back(d);
        }
        return (true);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return (false);
    }
}

// I'm using left + (right - left) / 2 to prevent overflow when left + right.
// 
// because 3 + (4 - 3) / 2 is 3 + (1 / 2); so 1/2 = 0.5 wich becomes 0, then 3 + 0 = 3.
std::vector<std::vector<unsigned int> >::iterator PmergeMe::binarySearchV(
                            std::vector<std::vector<unsigned int> > &ordered, 
                            const std::vector<unsigned int> &target)
{
    int left = 0;
    int right = ordered.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        #ifdef DEBUG
            this->_compV++;
        #endif

        if (target.front() < ordered[mid].front())
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (ordered.begin() + left);
}

std::vector<int> PmergeMe::calcJacobsthalV(int size)
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
std::vector<int> PmergeMe::jacobsthalVectorSeq(int size)
{
    std::vector<int>    retSeq;
    std::vector<int>    jacobSeq;

    jacobSeq = calcJacobsthalV(size);
    if (jacobSeq.empty())
        return (jacobSeq);
    std::vector<int>::iterator it = jacobSeq.begin();
    int last = 1;
    for (size_t i = 0; i < jacobSeq.size(); i++)
    {
        if (*it == 1)
        {
            retSeq.push_back(*it);
            it++;
            continue;
        }
        int jac = *it;
        while(last < jac)
            retSeq.push_back(jac--);
        last = *it;
        it++;
    }
    if(last < size)
    {
        int aux = size;
        while(last < aux)
            retSeq.push_back(aux--);
    }
    return (retSeq);
}

std::vector<std::vector<unsigned int> > PmergeMe::fightVector(
                        const std::vector<std::vector<unsigned int> > &vec,
                        std::vector<unsigned int> &oddElement,
                        bool hasOdd)
{
    // getting ready
    std::vector<std::vector<unsigned int> > retVec;

    hasOdd = (vec.size() %2 != 0);
    if (hasOdd)
        oddElement = vec.back();

    size_t limit = hasOdd ? vec.size() - 1 : vec.size();

    // battles
    for (size_t i = 0; i < limit; i += 2)
    {
        std::vector<unsigned int> winner = vec[i];
        std::vector<unsigned int> loser = vec[i + 1];

        #ifdef DEBUG
            this->_compV++;
        #endif
        if (winner.front() > loser.front())
            std::swap(winner, loser);
        
        winner.insert(winner.end(), loser.begin(), loser.end());
        retVec.push_back(winner);
    }
    return (retVec);
}

std::vector<std::vector<unsigned int> >    PmergeMe::applyJacobsthalV(std::vector<std::vector<unsigned int> > &results, 
                                const std::vector<unsigned int> &oddElement, 
                                bool hasOdd)
{
    
}

std::vector<std::vector<unsigned int> > PmergeMe::sortVector(std::vector<std::vector<unsigned int> > &vec)
{
    // special case for when vec.size == 1 from beginning
    if(vec.size() <= 1)
        return (vec);

    std::vector<unsigned int>  oddElement;
    bool hasOdd = false;
    //1. Batte phase (going down):
    std::vector<std::vector<unsigned int> > results = fightVector(vec, oddElement, hasOdd);
    //2. recursive calls:
    results = sortVector(results);
    //3. merge-insertion (coming back):
    return (applyJacobsthalV(results, oddElement, hasOdd));
}

void PmergeMe::FordJohnson(void)
{
    std::vector<std::vector<unsigned int> > orderedV = this->sortVector(this->_valuesV);
}