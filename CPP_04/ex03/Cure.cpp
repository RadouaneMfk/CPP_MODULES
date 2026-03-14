#include "Cure.hpp"

Cure::Cure() {
    if (DEBUG)
        std::cout << "Cure default constructor called\n";
    this->type = "cure";
}

Cure::Cure(const Cure& other) {
    if (DEBUG)
        std::cout << "Cure copy constructor called\n";
    *this = other;
}

Cure& Cure::operator=(const Cure& other) {
    if (DEBUG)
        std::cout << "Cure copy assignment operator called\n";
    (void)other;
    return *this;
}

AMateria* Cure::clone() const {
    AMateria* newCure = new Cure();
    return newCure;
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

Cure::~Cure() {
    if (DEBUG)
        std::cout << "Cure destructor called\n";
}
