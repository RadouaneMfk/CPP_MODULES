#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(2.0f, 2.0f);
    Point outside(10.0f, 10.0f);
    Point on_edge(5.0f, 0.0f);

    // true
    std::cout << "Inside point: "
              << (bsp(a, b, c, inside) ? "TRUE" : "FALSE")
              << std::endl;

    // false
    std::cout << "Outside point: "
              << (bsp(a, b, c, outside) ? "TRUE" : "FALSE")
              << std::endl;

    // false
    std::cout << "On edge point: "
              << (bsp(a, b, c, on_edge) ? "TRUE" : "FALSE")
              << std::endl;

    return 0;
}
