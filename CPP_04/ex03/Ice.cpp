#include "Ice.hpp"

Ice::Ice() {
    if (DEBUG)
        std::cout << "Ice default constructor called\n";
    this->type = "ice";
}

Ice::Ice(const Ice& other) {
    if (DEBUG)
        std::cout << "Ice copy constructor called\n";
    *this = other;
}

Ice& Ice::operator=(const Ice& other) {
    if (DEBUG)
        std::cout << "Ice copy assignment operator called\n";
    (void)other;
    return *this;
}

AMateria* Ice::clone() const {
    AMateria* newIce = new Ice();
    return newIce;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::~Ice() {
    if (DEBUG)
        std::cout << "Ice destructor called\n";
}
