#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac < 2) {
        std::cout << "Error: not enought args!\n";
        return 1;
    }
    PmergeMe m;
    m.process(ac, av);
    return 0;
}
