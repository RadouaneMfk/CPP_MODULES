#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    setType("Dog");
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called\n";
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    this->type = other.type;
    return (*this);
}

void Dog::setType(std::string type) {
    this->type = type;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::makeSound() const {
    std::cout << this->getType() << " barks\n";
}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
    delete this->brain;
}
