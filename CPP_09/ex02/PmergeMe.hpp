#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <climits>
#include <algorithm>
#include <deque>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        void process(int ac, char *av[]);
};
