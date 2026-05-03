#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <climits>
#include <cfloat>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(const std::string& str);
};
