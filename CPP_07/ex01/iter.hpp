#pragma once

#include <iostream>

template<typename T, typename F> void iter(T *arr, const int l, F func) {
    for (int i = 0; i < l; i++)
        func(arr[i]);
}
