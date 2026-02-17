#include "FragTrap.hpp"

int main() {
    FragTrap a("Panther V");
    FragTrap b("M4 Sherman");

    a.attack(b.getName());
    b.takeDamage(10);
    b.attack(a.getName());
    a.takeDamage(2);
    a.beRepaired(10);
    a.highFivesGuys();
    return 0;
}
