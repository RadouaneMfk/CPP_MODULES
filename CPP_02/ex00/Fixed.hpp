#pragma once

#include <iostream>

class Fixed {
    private:
        int raw_value;
        static const int frac_bits;
    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
       int getRawBits( void ) const;
       void setRawBits( int const raw );
};
