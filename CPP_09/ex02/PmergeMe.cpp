#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->_deq = other._deq;
    this->_vec = other._vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_deq = other._deq;
        this->_vec = other._vec;
    }
    return *this;
}

PmergeMe::~PmergeMe() {};

bool isValidInt(const std::string& str) {
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

// ------- vector ----------

std::vector<int> generateJacobsthalVec(int pendSize) {
    std::vector<int> seq;

    seq.push_back(0);
    seq.push_back(1);
    while (seq.back() < pendSize) {
        int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
        seq.push_back(next);
    }
    return seq;
}

std::vector<int> makeInsertionOrderVec(std::vector<int>& jacobSeq, int pendSize) {
    std::vector<int> InsertionOrder;
    int prev = 0;
    int current;

    for (size_t i = 1; i < jacobSeq.size(); i++)
    {
        current = jacobSeq[i] - 1;
        if (current == 0)
            continue;
        if (current >= pendSize)
            current = pendSize - 1;
        std::vector<int>::iterator it = std::find(InsertionOrder.begin(), InsertionOrder.end(), current);
        if (it != InsertionOrder.end())
            continue;
        InsertionOrder.push_back(current);
        if (jacobSeq[i] - 1 != 0) {
            for (int c = current - 1; c > prev; c--)
                InsertionOrder.push_back(c);
        }
        prev = current;
    }
    return InsertionOrder;
}

void mergeSortVec(std::vector<int>& _vec) {
    std::vector<int> main;
    std::vector<int> pend;
    int leftover = -1;

    if (_vec.size() <= 1)
        return;
    if (_vec.size() % 2 != 0) {
        leftover = _vec.back();
        _vec.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vec.size(); i += 2)
        pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    main.insert(main.begin(), pend[0]);
    std::vector<int> jacobSeq = generateJacobsthalVec(pend.size());
    std::vector<int> order = makeInsertionOrderVec(jacobSeq, pend.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        int pendVal = pend[order[i]];
        int pairedPend = pairs[order[i]].first;

        std::vector<int>::iterator bound = std::lower_bound(main.begin(), main.end(), pairedPend);
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), bound, pendVal);
        main.insert(pos, pendVal);
    }
    if (leftover != -1) {
        std::vector<int>::iterator leftPos = std::lower_bound(main.begin(), main.end(), leftover);
        main.insert(leftPos, leftover);
    }
    _vec = main;
}

//------- deque -----------

std::deque<int> generateJacobsthalDeq(int pendSize) {
    std::deque<int> seq;

    seq.push_back(0);
    seq.push_back(1);
    while (seq.back() < pendSize) {
        int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
        seq.push_back(next);
    }
    return seq;
}

std::deque<int> makeInsertionOrderDeq(std::deque<int>& jacobSeq, int pendSize) {
    std::deque<int> InsertionOrder;
    int prev = 0;
    int current;

    for (size_t i = 1; i < jacobSeq.size(); i++)
    {
        current = jacobSeq[i] - 1;
        if (current == 0)
            continue;
        if (current >= pendSize)
            current = pendSize - 1;
        std::deque<int>::iterator it = std::find(InsertionOrder.begin(), InsertionOrder.end(), current);
        if (it != InsertionOrder.end())
            continue;
        InsertionOrder.push_back(current);
        if (jacobSeq[i] - 1 != 0) {
            for (int c = current - 1; c > prev; c--)
                InsertionOrder.push_back(c);
        }
        prev = current;
    }
    return InsertionOrder;
}

void mergeSortDeque(std::deque<int>& _deq) {
    std::deque<int> main;
    std::deque<int> pend;
    int leftover = -1;

    if (_deq.size() <= 1)
        return;
    if (_deq.size() % 2 != 0) {
        leftover = _deq.back();
        _deq.pop_back();
    }
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _deq.size(); i += 2)
        pairs.push_back(std::make_pair(_deq[i], _deq[i + 1]));
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    main.insert(main.begin(), pend[0]);
    std::deque<int> jacobSeq = generateJacobsthalDeq(pend.size());
    std::deque<int> order = makeInsertionOrderDeq(jacobSeq, pend.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        int pendVal = pend[order[i]];
        int pairedPend = pairs[order[i]].first;

        std::deque<int>::iterator bound = std::lower_bound(main.begin(), main.end(), pairedPend);
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), bound, pendVal);
        main.insert(pos, pendVal);
    }
    if (leftover != -1) {
        std::deque<int>::iterator leftPos = std::lower_bound(main.begin(), main.end(), leftover);
        main.insert(leftPos, leftover);
    }
    _deq = main;
}

void PmergeMe::process(int ac, char *av[]) {
    for (int i = 1; i < ac; i++)
    {
        if (!isValidInt(av[i])) {
            std::cerr << "Error: invalid number\n";
            return;
        }
        long n = strtol(av[i], NULL, 10);
        if (n > INT_MAX || n <= 0) {
            std::cerr << "Error: number too large or number <= 0\n";
            return;
        }
        _vec.push_back(atoi(av[i]));
        _deq.push_back(atoi(av[i]));
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << "\n";
    struct timeval startVec, endVec;
    struct timeval startDeq, endDeq;
    gettimeofday(&startVec, NULL);
    mergeSortVec(_vec);
    gettimeofday(&endVec, NULL);
    gettimeofday(&startDeq, NULL);
    mergeSortDeque(_deq);
    gettimeofday(&endDeq, NULL);
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << "\n";
    double vecTime = (endVec.tv_sec - startVec.tv_sec) * 1000000.0
                    + (endVec.tv_usec - startVec.tv_usec);
    double deqTime = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0
                    + (endDeq.tv_usec - startDeq.tv_usec);
    std::cout << "Time to process a range of " << _vec.size()
    << " elements with std::vector : " << std::fixed
    << std::setprecision(5) << vecTime << " us\n";
    std::cout << "Time to process a range of " << _vec.size()
    << " elements with std::deque : " << std::fixed 
    << std::setprecision(5) << deqTime << " us\n";
}
