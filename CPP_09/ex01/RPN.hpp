#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <stdlib.h>
#include <exception>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void process(const std::string& expression);
};
