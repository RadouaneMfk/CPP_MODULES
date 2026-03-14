#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called!\n";
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor called\n";
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    this->type = other.type;
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal make a sound\n";
}

std::string WrongAnimal::getType() const {
    return this->type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called!\n";
}
