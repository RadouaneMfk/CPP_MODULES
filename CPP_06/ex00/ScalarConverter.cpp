#include "ScalarConverter.hpp"
#include "utils.hpp"

void ScalarConverter::convert(const std::string& str) {
    //char
    if (isChar(str)) {
        char c;
        if (str.length() == 3)
            c = str[1];
        else
            c = str[0];

        int i = static_cast<int>(c);
        double d = static_cast<double>(c);
        float f = static_cast<float>(c);
        if (!isprint(c))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << c << "'\n";
        
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
    }
    //float
	else if (isFloat(str) || (str == "nanf" || str == "+inff" || str == "-inff")) {
        float f = static_cast<float>(atof(str.c_str()));
        
        if (std::isinf(f) || std::isnan(f))
            std::cout << "char: impossible\n";
        else {
            char c = static_cast<char>(f);
            if (!isprint(c))
                std::cout << "char: Non displayable\n";
            else
                std::cout << "char: '" << c << "'\n";
        }
        if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN) || std::isinf(f) || std::isnan(f))
            std::cout << "int: impossible\n";
        else {
            int i = static_cast<int>(f);
            std::cout << "int: " << i << "\n";
        }
        double d = static_cast<double>(f);
        if (str == "nanf" || str == "+inff" || str == "-inff") {
            std::cout << "float: " << str << "\n";
            std::cout << "double: " << str.substr(0, str.length() - 1) << "\n";
        }
        else {
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
        }
	}
	//double
	else if (isDouble(str) || (str == "nan" || str == "+inf" || str == "-inf")) {
        double d = static_cast<double>(atof(str.c_str()));

        if (std::isinf(d) || std::isnan(d))
            std::cout << "char: impossible\n";
        else {
            char c = static_cast<char>(d);
            if (!isprint(c))
                std::cout << "char: Non displayable\n";
            else
                std::cout << "char: '" << c << "'\n";
        }
        if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN) || std::isinf(d) || std::isnan(d))
            std::cout << "int: impossible\n";
        else {
            int i = static_cast<int>(d);
            std::cout << "int: " << i << "\n";
        }
        if (str == "nan" || str == "+inf" || str == "-inf") {
            std::cout << "float: " << str << "f\n";
            std::cout << "double: " << str << "\n";
        }
        else if (d > static_cast<double>(FLT_MAX) || d < static_cast<double>(-FLT_MAX))
        {
            std::cout << "float: impossible\n";
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
        }
        else {
            float f = static_cast<float>(d);
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
        }
	}
    //int
    else if (isInt(str)) {
		long res = strtol(str.c_str(), NULL, 10);
		double res_d = strtod(str.c_str(), NULL);

        char c = static_cast<char>(res);
        if (isprint(c))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
        if (res > INT_MAX || res < INT_MIN)
            std::cout << "int: impossible\n";
        else {
			int i = static_cast<int>(res);
            std::cout << "int: " << i << "\n";
        }
        float f = static_cast<float>(res_d);
        double d = static_cast<double>(res_d);
        
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1)  << d << "\n";
    }
    else
        std::cerr << "Invalid input!\n";
}
