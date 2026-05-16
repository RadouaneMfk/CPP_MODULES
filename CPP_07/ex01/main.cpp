#include "iter.hpp"

template<typename T>void print(T& a) {
    std::cout << a << "\n";
}

void increment(int& a) {
    a++;
}

int main () {
    int intArr[] = {1, 2};
    iter(intArr, 2, increment);
    iter(intArr, 2, print<int>);

    char charArr[] = {'a', 'b'};
    iter(charArr, 2, print<char>);

    std::string str[] = {"hello", "world"};
    iter(str, 2, print<std::string>);
}
