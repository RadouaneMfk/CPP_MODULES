#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called\n";
    setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "WrongCat copy constructor called\n";
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    this->type = other.type;
    return (*this);
}

void WrongCat::setType(std::string type) {
    this->type = type;
}

std::string WrongCat::getType() const {
    return this->type;
}

void WrongCat::makeSound() const {
    std::cout << this->getType() << " meoww\n";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called\n";
}
