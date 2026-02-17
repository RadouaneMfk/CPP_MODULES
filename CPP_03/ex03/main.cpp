#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d("Panther V");

    d.attack("M4 sherman");
    d.takeDamage(20);
    d.beRepaired(10);
    d.guardGate();
    d.highFivesGuys();
    d.whoAmI();
}
