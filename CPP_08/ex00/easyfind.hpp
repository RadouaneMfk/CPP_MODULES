#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator easyfind(T& c, int v) {
    typename T::iterator it = std::find(c.begin(), c.end(), v);
    if (it != c.end())
        return it;
    throw std::runtime_error("value not found!");
}
