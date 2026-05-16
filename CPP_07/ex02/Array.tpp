#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(NULL), _size(0) {
};

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    arr = new T[n];
};

template<typename T>
Array<T>::Array(const Array& other) {
    _size = other._size;
    arr = new T[other._size];
    for (size_t i = 0; i < _size; i++)
        arr[i] = other.arr[i];
};

template<typename T>
Array<T>::~Array() {
    delete [] arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other)
        return *this;
    delete [] this->arr;
    _size = other._size;
    this->arr = new T[other._size];
    for (size_t i = 0; i < _size; i++)
        this->arr[i] = other.arr[i];
    return *this;
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template<typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || (unsigned int)index >= _size)
        throw std::out_of_range("index out of bounds!");
    return arr[index];
};

template<typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || (unsigned int)index >= _size)
        throw std::out_of_range("index out of bounds!");
    return arr[index];
};
