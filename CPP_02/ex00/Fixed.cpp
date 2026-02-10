#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed() {
    setRawBits(0);
    std::cout << "Default constructor called\n";
};

Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called\n";
    *this = f;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called\n";
    raw_value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return raw_value;
}

void Fixed::setRawBits( int const raw ) {
    raw_value = raw;
}
