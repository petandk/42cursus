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
        std::vector<std::pair<unsigned int, int> > _valuesV;
        std::deque<std::pair<unsigned int, int> > _valuesD;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool readValues(int argc, char *argv[]);

        #ifdef DEBUG
            void debugValues(void);
        #endif
        bool sortVector(std::vector<std::pair<unsigned int, int> > &vec);
        bool sortDeque(std::deque<std::pair<unsigned int, int> > &dec);
        
        void FordJohnson(void);
};

#endif