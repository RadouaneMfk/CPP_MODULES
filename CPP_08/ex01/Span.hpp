#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span {
    private:
        unsigned int _capacity;
        std::vector<int> _nums;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        ~Span();
};
