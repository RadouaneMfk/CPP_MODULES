#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Panther V");
    ClapTrap b("M4 Sherman");

    a.attack(b.getName());
    b.takeDamage(10);
    b.attack(a.getName());
    a.takeDamage(2);
    a.beRepaired(10);
    return 0;
}
