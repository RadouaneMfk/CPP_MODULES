#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& other) {
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    for (size_t i = 0; i < other.ideas->length(); i++)
        this->ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain destructor called\n";
}
