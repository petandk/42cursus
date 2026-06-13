#include "../inc/PmergeMe.hpp"
#include <algorithm> //for sort
PmergeMe::PmergeMe()
{
    #ifdef DEBUG
    this->_contV = 0;
    this->_contD = 0;
    this->_depthV = 0;
    this->_depthD = 0;
    #endif
}

PmergeMe::PmergeMe(const PmergeMe &other):_valuesV(other._valuesV), _valuesD(other._valuesD)
{
    #ifdef DEBUG
        this->_contV = other._contV;
        this->_contD = other._contD;
        this->_depthV = other._depthV;
        this->_depthD = other._depthD;
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
            this->_depthV = other._depthV;
            this->_depthD = other._depthD;
        #endif
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

double PmergeMe::getTimeInMicroseconds() const
{
    return(static_cast<double>(clock()) / CLOCKS_PER_SEC * 1000000.0);
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
    void PmergeMe::printStepV(const std::vector<std::vector<unsigned int> >&vec,
                                const std::string &label,
                                const std::vector<unsigned int> &oddElement,
                                bool &hasOdd)
    {
        std::string indent(_depthV * 2, ' ');
        if (label == "down")
            this->_depthV++;
        else if (label == "up")
            this->_depthV--;
        std::cout << indent << "Vector Going " << label << ": [";
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (i > 0) std::cout << "][";
            for (size_t j = 0; j < vec[i].size(); j++)
            {
                if (j > 0) std::cout << ",";
                std::cout << vec[i][j];
            }
        }
        std::cout << "]";
        if (hasOdd)
        {
            std::cout << ((label == "down")? " => [" : " <= [");
            for (size_t j = 0; j < oddElement.size(); j++)
            {
                if (j > 0) std::cout << ",";
                std::cout << oddElement[j];
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }

    void PmergeMe::printStepD(const std::deque<std::deque<unsigned int> >&dec,
                                const std::string &label,
                                const std::deque<unsigned int> &oddElement,
                                bool &hasOdd)
    {
        std::string indent(_depthD * 2, ' ');
        if (label == "down")
            this->_depthD++;
        else if (label == "up")
            this->_depthD--;
        std::cout << indent << "Deque Going " << label << ": [";
        for (size_t i = 0; i < dec.size(); i++)
        {
            if (i > 0) std::cout << "][";
            for (size_t j = 0; j < dec[i].size(); j++)
            {
                if (j > 0) std::cout << ",";
                std::cout << dec[i][j];
            }
        }
        std::cout << "]";
        if (hasOdd)
        {
            std::cout << ((label == "down")? " => [" : " <= [");
            for (size_t j = 0; j < oddElement.size(); j++)
            {
                if (j > 0) std::cout << ",";
                std::cout << oddElement[j];
            }
            std::cout << "]";
        }
        std::cout << std::endl;
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

void PmergeMe::printValues(bool ordered, std::vector<std::vector<unsigned int> > &vec, std::deque<std::deque<unsigned int> > &dec)
{
    if (!ordered)
    {
        std::cout << "Before:";
        for (std::vector<unsigned int>::iterator it = _checker.begin(); it != _checker.end(); it++)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
    else
    {
        //first let's check if the values are sorted correctly
        std::sort(_checker.begin(), _checker.end());

        bool correctV = true;
        bool correctD = true;
        std::vector<unsigned int>::iterator itC = _checker.begin();
        std::vector<std::vector<unsigned int> >::iterator itV = vec.begin();
        std::deque<std::deque<unsigned int> >::iterator itD = dec.begin();
        
        for (; itC != _checker.end();itC++, itV++, itD++)
        {
            if (*itC != (*itV).front())
            {
                correctV = false;
                break;
            }
            if (*itC != (*itD).front())
            {
                correctD = false;
                break;
            }
        }
        if (correctV && correctD)
        {
            std::cout << "\033[1;32mAfter: ";
            
            for (std::vector<unsigned int>::iterator it = _checker.begin(); it != _checker.end(); it++)
                std::cout << " " << *it;
            std::cout << "\033[0m" << std::endl;
        }
        else
            std::cout << "\033[31mError: sorting failed.\033[0m" << std::endl;
    }
}

bool PmergeMe::readValues(int argc, char *argv[])
{
    try
    {
        for (int i = 1; i < argc; i++)
        {
            unsigned int val = parseAndCast(argv[i]);
            std::vector<unsigned int> v;
            std::deque<unsigned int> d;
            v.push_back(val);
            d.push_back(val);
            this->_checker.push_back(val);
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
                            const std::vector<unsigned int> &target,
                            int winnerPosition)
{
    int left = 0;
    int right = winnerPosition;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        #ifdef DEBUG
            this->_contV++;
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
                        bool &hasOdd)
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
            this->_contV++;
        #endif

        if (winner.front() < loser.front())
            std::swap(winner, loser);
        
        winner.insert(winner.end(), loser.begin(), loser.end());
        retVec.push_back(winner);
    }
    return (retVec);
}

std::vector<std::vector<unsigned int> > PmergeMe::applyJacobsthalV(std::vector<std::vector<unsigned int> > &results, 
                                const std::vector<unsigned int> &oddElement, 
                                bool hasOdd)
{
    std::vector<std::vector<unsigned int> > winers;
    std::vector<std::vector<unsigned int> > losers;
    for (size_t i = 0; i < results.size(); i++)
    {
        size_t mid = results[i].size() / 2;
        std::vector<unsigned int>winPart(results[i].begin(), results[i].begin() + mid);
        std::vector<unsigned int>losPart(results[i].begin() + mid, results[i].end());
        winers.push_back(winPart);
        losers.push_back(losPart);
    }
    if (hasOdd)
        losers.push_back(oddElement);

    std::vector<int>orderSeq = jacobsthalVectorSeq(losers.size());
    std::vector<int>::iterator it = orderSeq.begin();

    //I need a copy of winers before anything
    std::vector<std::vector<unsigned int> > champions = winers;

    winers.insert(winers.begin(), losers[0]); //first always go on front.
    it++;

    while (it != orderSeq.end())
    {
        int index = *it - 1;
        int rightLimit = -1;
        if (index < (int)champions.size())
        {
            unsigned int winnerValue = champions[index].front();
            for (size_t i = 0; i < winers.size(); i++)
            {
                if (winers[i].front() == winnerValue)
                {
                    rightLimit = i;
                    break;
                }
            }
        }
        std::vector<std::vector<unsigned int> >::iterator pos = binarySearchV(winers, losers[index], ((rightLimit == -1) ? (winers.size() - 1) : (rightLimit - 1)));
        winers.insert(pos, losers[index]);
        it++;
    }
    return (winers);
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
    #ifdef DEBUG
        printStepV(results, "down", oddElement, hasOdd);
    #endif
    //2. recursive calls:
    results = sortVector(results);
    results = applyJacobsthalV(results, oddElement, hasOdd);
    #ifdef DEBUG
        printStepV(results, "up", oddElement, hasOdd);
    #endif
    //3. merge-insertion (coming back):
    return (results);
}

std::deque<std::deque<unsigned int> >::iterator PmergeMe::binarySearchD(
                            std::deque<std::deque<unsigned int> > &ordered, 
                            const std::deque<unsigned int> &target,
                            int winnerPosition)
{
    int left = 0;
    int right = winnerPosition;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        #ifdef DEBUG
            this->_contD++;
        #endif
        if (target.front() < ordered[mid].front())
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (ordered.begin() + left);
}

std::deque<int> PmergeMe::calcJacobsthalD(int size)
{
    std::deque<int> retSeq;

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

std::deque<int> PmergeMe::jacobsthalDequeSeq(int size)
{
    std::deque<int>    retSeq;
    std::deque<int>    jacobSeq;

    jacobSeq = calcJacobsthalD(size);
    if (jacobSeq.empty())
        return (jacobSeq);
    std::deque<int>::iterator it = jacobSeq.begin();
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

std::deque<std::deque<unsigned int> > PmergeMe::fightDeque(
                        const std::deque<std::deque<unsigned int> > &dec,
                        std::deque<unsigned int> &oddElement,
                        bool &hasOdd)
{
    std::deque<std::deque<unsigned int> > retDec;

    hasOdd = (dec.size() %2 != 0);
    if (hasOdd)
        oddElement = dec.back();

    size_t limit = hasOdd ? dec.size() - 1 : dec.size();

    // battles
    for (size_t i = 0; i < limit; i += 2)
    {
        std::deque<unsigned int> winner = dec[i];
        std::deque<unsigned int> loser = dec[i + 1];

        #ifdef DEBUG
            this->_contD++;
        #endif

        if (winner.front() < loser.front())
            std::swap(winner, loser);
        
        winner.insert(winner.end(), loser.begin(), loser.end());
        retDec.push_back(winner);
    }
    return (retDec);
}

std::deque<std::deque<unsigned int> > PmergeMe::applyJacobsthalD(std::deque<std::deque<unsigned int> > &results, 
                                const std::deque<unsigned int> &oddElement, 
                                bool hasOdd)
{
    std::deque<std::deque<unsigned int> > winers;
    std::deque<std::deque<unsigned int> > losers;
    for (size_t i = 0; i < results.size(); i++)
    {
        size_t mid = results[i].size() / 2;
        std::deque<unsigned int>winPart(results[i].begin(), results[i].begin() + mid);
        std::deque<unsigned int>losPart(results[i].begin() + mid, results[i].end());
        winers.push_back(winPart);
        losers.push_back(losPart);
    }
    if (hasOdd)
        losers.push_back(oddElement);

    std::deque<int>orderSeq = jacobsthalDequeSeq(losers.size());
    std::deque<int>::iterator it = orderSeq.begin();

    //I need a copy of winers before anything
    std::deque<std::deque<unsigned int> > champions = winers;

    winers.push_front(losers[0]); //first always go on front.
    it++;

    while (it != orderSeq.end())
    {
        int index = *it - 1;
        int rightLimit = -1;
        if (index < (int)champions.size())
        {
            unsigned int winnerValue = champions[index].front();
            for (size_t i = 0; i < winers.size(); i++)
            {
                if (winers[i].front() == winnerValue)
                {
                    rightLimit = i;
                    break;
                }
            }
        }
        std::deque<std::deque<unsigned int> >::iterator pos = binarySearchD(winers, losers[index], ((rightLimit == -1) ? (winers.size() - 1) : (rightLimit - 1)));
        winers.insert(pos, losers[index]);
        it++;
    }
    return (winers);
}

std::deque<std::deque<unsigned int> > PmergeMe::sortDeque(std::deque<std::deque<unsigned int> > &dec)
{

    // special case for when dec.size == 1 from beginning
    if(dec.size() <= 1)
        return (dec);

    std::deque<unsigned int>  oddElement;
    bool hasOdd = false;
    //1. Batte phase (going down):
    std::deque<std::deque<unsigned int> > results = fightDeque(dec, oddElement, hasOdd);
    #ifdef DEBUG
        printStepD(results, "down", oddElement, hasOdd);
    #endif
    //2. recursive calls:
    results = sortDeque(results);
    results = applyJacobsthalD(results, oddElement, hasOdd);
    #ifdef DEBUG
        printStepD(results, "up", oddElement, hasOdd);
    #endif
    //3. merge-insertion (coming back):
    return (results);
}

void PmergeMe::FordJohnson(void)
{
    printValues(false, this->_valuesV, this->_valuesD);
    double startV = getTimeInMicroseconds();
    std::vector<std::vector<unsigned int> > orderedV = this->sortVector(this->_valuesV);
    double endV = getTimeInMicroseconds();
    double startD = getTimeInMicroseconds();
    std::deque<std::deque<unsigned int> > orderedD = this->sortDeque(this->_valuesD);
    double endD = getTimeInMicroseconds();

    printValues(true, orderedV, orderedD);

    std::cout << "Time to process a range of " << _checker.size()
                << " elements with std::vector: " 
                << std::fixed << (endV - startV) 
                << " us" << std::endl;
    std::cout << "Time to process a range of " << _checker.size()
                << " elements with std::deque: " 
                << std::fixed << (endD - startD) 
                << " us" << std::endl;

    #ifdef DEBUG
        size_t theoricalMax = FordJohnsonTheoricalMax(_checker.size());
        std::cout << "Theorical max: " << theoricalMax << std::endl;
        
        std::cout << ((theoricalMax >= this->_contV)? "\033[1;32m" : "\033[0;31m") << "Vector Comparisons: " << this->_contV << "\033[0m" << std::endl;
        std::cout << ((theoricalMax >= this->_contD)? "\033[1;32m" : "\033[0;31m") << "Deque Comparisons: " << this->_contD << "\033[0m" << std::endl;

    #endif
}