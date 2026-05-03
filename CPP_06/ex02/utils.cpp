#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    std::srand(time(NULL));
    int rand = std::rand() % 3;
    if (rand == 0)
        return new A();
    else if (rand == 1)
        return new B();
    return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    return;
}

void identify(Base& p) {
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch(...) {}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch(...) {}
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch(...) {}
}