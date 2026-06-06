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

        std::vector<int> jacobsthal(int prev);
        //vector
        std::vector<std::pair<unsigned int, int> > sortVector(std::vector<std::pair<unsigned int, int> > &vec);
        void fightVector(std::vector<std::pair<unsigned int, int> > &fighters, 
                        std::vector<std::pair<unsigned int, int> > &winers,
                        std::vector<std::pair<unsigned int, int> > &losers);
        void    jacobsthalVector(std::vector<std::pair<unsigned int, int> > &winers,
                                std::vector<std::pair<unsigned int, int> > &losers);
        std::vector<int> jacobsthalVectorSeq(int n);
        
        //deque
        std::deque<std::pair<unsigned int, int> > sortDeque(std::deque<std::pair<unsigned int, int> > &dec);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool readValues(int argc, char *argv[]);

        #ifdef DEBUG
            void debugValues(void);
        #endif
                
        void FordJohnson(void);
};

#endif