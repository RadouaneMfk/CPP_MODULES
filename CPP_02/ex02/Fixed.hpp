#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int raw_value;
        static const int frac_bits;
    public:
        Fixed();
        Fixed(const int val);
        Fixed(const float val);
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& other);
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed operator-(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        ~Fixed();
       int getRawBits( void ) const;
       void setRawBits( int const raw );
	   float toFloat( void ) const;
       int toInt( void ) const;
       static Fixed& min(Fixed& a, Fixed& b);
       static const Fixed& min(const Fixed& a, const Fixed& b);
       static Fixed& max(Fixed& a, Fixed& b);
       static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);
