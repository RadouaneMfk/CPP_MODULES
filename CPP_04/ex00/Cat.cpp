#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called\n";
    setType("Cat");
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat copy constructor called\n";
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    this->type = other.type;
    return (*this);
}

void Cat::setType(std::string type) {
    this->type = type;
}

std::string Cat::getType() const {
    return this->type;
}

void Cat::makeSound() const {
    std::cout << this->getType() << " meoww\n";
}

Cat::~Cat() {
    std::cout << "Cat destructor called\n";
}
