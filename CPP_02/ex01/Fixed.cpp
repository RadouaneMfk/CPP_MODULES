#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed(const int val) {
    raw_value = val * (1 << frac_bits);
    std::cout << "Int constructor called\n";
};

Fixed::Fixed(const float val) {
    raw_value = roundf(val * (1 << frac_bits));
    std::cout << "Float constructor called\n";
};

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
    raw_value = other.raw_value;
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

float Fixed::toFloat( void ) const {
    float res = (float)raw_value / (1 << frac_bits);
    return res;
};

int Fixed::toInt( void ) const {
    int res = raw_value / (1 << frac_bits);
    return res;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}