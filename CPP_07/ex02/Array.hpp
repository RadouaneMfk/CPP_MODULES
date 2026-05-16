#pragma once

#include <iostream>
#include <exception>

template<typename T>
class Array {
    private:
        T *arr;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        unsigned int size() const;
        ~Array();
        T& operator[](int index);
        const T& operator[](int index) const;
};

#include "Array.tpp"