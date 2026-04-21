#include "Bureaucrat.hpp"

int main () {
    try
    {
        Bureaucrat b("su-57", 10);
        Bureaucrat a("f-35", 5);
        a = b;
        std::cout << a;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...) {
        std::cerr << "Default catch!\n";
    }
}