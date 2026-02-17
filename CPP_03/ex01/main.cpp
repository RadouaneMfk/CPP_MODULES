#include "ScavTrap.hpp"

int main() {
    ScavTrap a("Panther V");
    ScavTrap b("M4 Sherman");

    a.attack(b.getName());
    b.takeDamage(10);
    b.attack(a.getName());
    a.takeDamage(2);
    a.beRepaired(10);
    a.guardGate();
    return 0;
}
