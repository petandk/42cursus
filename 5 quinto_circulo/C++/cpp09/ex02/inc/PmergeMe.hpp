#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <utility>
# include <sstream>
# include <stdexcept>
# include <ctime>

class PmergeMe{
    private:
        std::vector<std::vector<unsigned int> > _valuesV;
        std::deque<std::deque<unsigned int> > _valuesD;
        std::vector<unsigned int> _checker;

        double getTimeInMicroseconds() const;
        
        #ifdef DEBUG
            size_t _contV;
            size_t _contD;
            size_t FordJohnsonTheoricalMax(size_t n);
            
            int _depthV;
            int _depthD;
            void printStepV(const std::vector<std::vector<unsigned int> >&vec,
                                const std::string &label,
                                const std::vector<unsigned int> &oddElement,
                                bool &hasOdd);
            void printStepD(const std::deque<std::deque<unsigned int> >&dec,
                                const std::string &label,
                                const std::deque<unsigned int> &oddElement,
                                bool &hasOdd);
        #endif

        //both
        unsigned int parseAndCast(const std::string  &value);

        //vector
        std::vector<std::vector<unsigned int> >::iterator binarySearchV(
                                std::vector<std::vector<unsigned int> > &ordered, 
                                const std::vector<unsigned int> &target,
                                int winnerPosition);
        std::vector<int> calcJacobsthalV(int prev);
        std::vector<int> jacobsthalVectorSeq(int size);
        std::vector<std::vector<unsigned int> > fightVector(
                                const std::vector<std::vector<unsigned int> > &vec,
                                std::vector<unsigned int> &oddElement,
                                bool &hasOdd);
        std::vector<std::vector<unsigned int> > applyJacobsthalV(std::vector<std::vector<unsigned int> > &results, 
                                const std::vector<unsigned int> &oddElement, 
                                bool hasOdd);
        std::vector<std::vector<unsigned int> > sortVector(std::vector<std::vector<unsigned int> > &vec);

        //deque
        std::deque<std::deque<unsigned int> >::iterator binarySearchD(
                                std::deque<std::deque<unsigned int> > &ordered, 
                                const std::deque<unsigned int> &target,
                                int winnerPosition);
        std::deque<int> calcJacobsthalD(int prev);
        std::deque<int> jacobsthalDequeSeq(int size);
        std::deque<std::deque<unsigned int> > fightDeque(
                                const std::deque<std::deque<unsigned int> > &dec,
                                std::deque<unsigned int> &oddElement,
                                bool &hasOdd);
        std::deque<std::deque<unsigned int> > applyJacobsthalD(std::deque<std::deque<unsigned int> > &results, 
                                const std::deque<unsigned int> &oddElement, 
                                bool hasOdd);
        std::deque<std::deque<unsigned int> > sortDeque(std::deque<std::deque<unsigned int> > &dec);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void printValues(bool ordered, std::vector<std::vector<unsigned int> > &vec, std::deque<std::deque<unsigned int> > &dec);
        bool    readValues(int argc, char *argv[]);
                
        void    FordJohnson(void);
};

#endif