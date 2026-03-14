#include "AMateria.hpp"

AMateria::AMateria() : type("unknown") {
    if (DEBUG)
        std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const AMateria& other) {
    if (DEBUG)
        std::cout << "AMateria copy constructor called\n";
    *this = other;
}

AMateria::AMateria(std::string const & type) : type(type) {
    if (DEBUG)
        std::cout << "AMateria parammetrized constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (DEBUG)
        std::cout << "AMateria copy assignement operator called\n";
    (void)other;
    return *this;
}

std::string const& AMateria::getType() const {
    return type;
}

AMateria::~AMateria() {
    if (DEBUG)
        std::cout << "AMateria destructor called\n";
}

void AMateria::use(ICharacter& target) {
    (void)target;
}
