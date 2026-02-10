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
        ~Fixed();
       int getRawBits( void ) const;
       void setRawBits( int const raw );
       float toFloat( void ) const;
       int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);