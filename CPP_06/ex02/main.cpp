#include "utils.hpp"

int main() {
    Base* b = generate();
    // std::cout << p;
    identify(b);
    identify(*b);

    delete b;
}
