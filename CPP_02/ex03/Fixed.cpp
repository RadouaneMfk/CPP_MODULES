#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed(const int val) {
    raw_value = val * 256;
};

Fixed::Fixed(const float val) {
    raw_value = roundf(val * 256);
};

Fixed::Fixed() {
    setRawBits(0);
};

Fixed::Fixed(const Fixed& f) {
    *this = f;
}

Fixed& Fixed::operator=(const Fixed& other) {
    raw_value = other.getRawBits();
    return (*this);
}

bool Fixed::operator==(const Fixed& other) const {
    if (this->raw_value == other.raw_value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& other) const {
    if (this->raw_value != other.raw_value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& other) const {
    if (this->raw_value >= other.raw_value)
        return true;
    return false;
}

bool Fixed::operator>(const Fixed& other) const {
    if (this->raw_value > other.raw_value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& other) const {
    if (this->raw_value <= other.raw_value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& other) const {
    if (this->raw_value < other.raw_value)
        return true;
    return false;
}

Fixed& Fixed::operator++() {
    ++this->raw_value;
    return (*this);
}

Fixed& Fixed::operator--() {
    --this->raw_value;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp;
    tmp.raw_value = this->raw_value;
    this->raw_value++;
    return (tmp);
}

Fixed Fixed::operator--(int) {
    Fixed tmp;
    tmp.raw_value = this->raw_value;
    this->raw_value--;
    return (tmp);
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed f;
    f.raw_value = this->raw_value + other.raw_value;
    return (f);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed f;
    f.raw_value = this->raw_value - other.raw_value;
    return (f);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed f;
    f.raw_value = (this->raw_value * other.raw_value) / 256;
    return (f);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed f;
    f.raw_value = (this->raw_value  * 256 / other.raw_value);
    return (f);
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
    return raw_value;
}

void Fixed::setRawBits( int const raw ) {
    raw_value = raw;
}

float Fixed::toFloat( void ) const {
    float res = (float)raw_value / 256;
    return res;
};

int Fixed::toInt( void ) const {
    int res = raw_value / 256;
    return res;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.raw_value < b.raw_value)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.raw_value > b.raw_value)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.raw_value < b.raw_value)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.raw_value > b.raw_value)
        return a;
    return b;
}
