#include "utils.hpp"

bool isInt(const std::string& str) {
    if (isdigit(str[0]) || str[0] == '-') {
        int start = 0;
        if (str[0] == '-')
            start = 1;
        for (size_t i = start; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
                return false;
        }
        return true;
    }
    return false;
}

bool isChar(const std::string& str) {
    if (str.length() == 1) {
        if (isalpha(str[0])) {
            return true;
        }
    }
    else if (str.length() == 3) {
        if (str[0] == '\'' && str[2] == '\'' && isprint(str[1])) {
            return true;
        }
    }
    return false;
}

bool isFloat(const std::string& str) {
    if (str.find('.') != str.npos && (isdigit(str[0]) || str[0] == '-')) {
        bool havePoint = false;
        int j = 0;
        if (str[0] == '-')
            j = 1;
        int len = str.length();
        for (int i = j; i < len - 1; i++)
        {
            if (str[j] == '.')
                return false;
            if (str[i] == '.' && !havePoint) {
                havePoint = true;
                i++;
            }
            if (!isdigit(str[i])) {
                return false;
            }
        }
        if (str[len - 1] == 'f')
            return true;
    }
	return false;
}

bool isDouble(const std::string& str) {
    if (str.find('.') != str.npos && (isdigit(str[0]) || str[0] == '-')) {
        bool havePoint = false;
        int j = 0;
        if (str[0] == '-')
            j = 1;
        int len = str.length();
        for (int i = j; i < len - 1; i++)
        {
            if (str[j] == '.')
                return false;
            if (str[i] == '.' && !havePoint) {
                havePoint = true;
                i++;
            }
            if (!isdigit(str[i])) {
                return false;
            }
        }
        if (isdigit(str[len - 1]))
            return true;
	}
    return false;
}
