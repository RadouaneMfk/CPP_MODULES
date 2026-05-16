#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    int arr[] = {6, 3, 17, 0, 11};
    std::vector<int> v(arr, arr + 5);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    sp.addNumbers(v.begin(), v.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
