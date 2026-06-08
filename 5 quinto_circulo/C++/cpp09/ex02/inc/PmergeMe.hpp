#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <utility>
# include <sstream>
# include <stdexcept>

class PmergeMe{
    private:
        std::vector<std::vector<unsigned int> > _valuesV;
        std::deque<std::deque<unsigned int> > _valuesD;

        #ifdef DEBUG
            size_t _contV;
            size_t _contD:
            size_t FordJohnsonTheoricalMax(size_t n);
        #endif

        unsigned int parseAndCast(const std::string  &value);

        //vector
        std::vector<std::vector<unsigned int> >::iterator binarySearchV(
                                std::vector<std::vector<unsigned int> > &ordered, 
                                const std::vector<unsigned int> &target);
        std::vector<int> calcJacobsthalV(int prev);
        std::vector<int> jacobsthalVectorSeq(int size);
        std::vector<std::vector<unsigned int> > fightVector(
                                const std::vector<std::vector<unsigned int> > &vec,
                                std::vector<unsigned int> &oddElement,
                                bool hasOdd);
        std::vector<std::vector<unsigned int> >    applyJacobsthalV(std::vector<std::vector<unsigned int> > &results, 
                                const std::vector<unsigned int> &oddElement, 
                                bool hasOdd);
        std::vector<std::vector<unsigned int> > sortVector(std::vector<std::vector<unsigned int> > &vec);

        //deque
        //std::deque<std::pair<unsigned int, int> > sortDeque(std::deque<std::pair<unsigned int, int> > &dec);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool readValues(int argc, char *argv[]);
                
        void FordJohnson(void);
};

#endif