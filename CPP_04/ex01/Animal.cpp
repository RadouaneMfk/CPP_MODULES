#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called!\n";
    this->type = "Animal";
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal copy constructor called\n";
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called\n";
    this->type = other.type;
    return (*this);
}

void Animal::makeSound() const {
    std::cout << "Animal make a sound\n";
}

std::string Animal::getType() const {
    return this->type;
}

Animal::~Animal() {
    std::cout << "Animal destructor called!\n";
}
