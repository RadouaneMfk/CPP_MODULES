#include "RPN.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cerr << "invalid input: ./RPN \"expression\"\n";
        return 1;
    }
    try
    {
        RPN rpn;
        rpn.process(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
