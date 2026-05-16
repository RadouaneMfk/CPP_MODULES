#include "Span.hpp"

Span::Span() : _capacity(0) {};

Span::Span(unsigned int N) : _capacity(N) {};

Span::Span(const Span& other) : _capacity(other._capacity), _nums(other._nums) {};

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    this->_capacity = other._capacity;
    this->_nums = other._nums;
    return *this;
};

void Span::addNumber(int n) {
    if (_nums.size() == _capacity)
        throw std::out_of_range("span is full!");
    _nums.push_back(n);
};

int Span::shortestSpan() {
    if (_nums.size() < 2)
        throw std::logic_error("conatainer size not enought!");
    std::sort(_nums.begin(), _nums.end());
    int min = _nums[1] - _nums[0];
    for (size_t i = 0; i < _nums.size() - 1; i++)
    {
        if (_nums[i + 1] - _nums[i] < min)
            min = _nums[i + 1] - _nums[i];
    }
    return min;
};

int Span::longestSpan() {
    if (_nums.size() < 2)
        throw std::logic_error("conatainer size not enought!");
    int min = *std::min_element(_nums.begin(), _nums.end());
    int max = *std::max_element(_nums.begin(), _nums.end());
    return (max - min);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_nums.size() + std::distance(begin, end) > _capacity)
        throw std::logic_error("conatainer capacity not enought!");
    _nums.insert(_nums.end(), begin, end);
};

Span::~Span() {};