#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN& other) {
    this->_stack = other._stack;
};

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
		this->_stack = other._stack;
	return *this;
};

RPN::~RPN() {};

bool isOperator(const std::string& token) {
	if (token == "/" || token == "*" || token == "+" || token == "-")
		return true;
	return false;
}

void RPN::process(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;
	int result;
    while (ss >> token) {
		if (isOperator(token)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error: not enought numbers!");
			int secondNum = _stack.top();
			_stack.pop();
			int firstNum = _stack.top();
			_stack.pop();
			if (token[0] == '+')
				result = firstNum + secondNum;
			else if (token[0] == '-')
				result = firstNum - secondNum;
			else if (token[0] == '*')
				result = firstNum * secondNum;
			else if (token[0] == '/') {
				if (secondNum == 0)
					throw std::runtime_error("Error: division by 0!");
				result = firstNum / secondNum;
			}
			_stack.push(result);
		}
		else if (token.length() == 1 && isdigit(token[0])) {
			_stack.push(atoi(token.c_str()));
		}
		else {
			std::cerr << "Error\n";
			return;
		}
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << "\n";
	else
		std::cerr << "Error\n";
};
