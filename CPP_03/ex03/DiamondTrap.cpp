#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("ghost_clap_name"), FragTrap("ghost"), ScavTrap("ghost"), name("ghost") {
    std::cout << "DiamondTrap " << this->name << " default contructor called\n";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    std::cout << "DiamondTrap " << this->name << " parammeterized contructor called\n";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other.name + "_clap_name") {
    std::cout << "DiamondTrap " << this->name << " copy contructor called\n";
    *this = other;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name is " << this->name << ", ClapTrap name is " 
    << ClapTrap::getName() << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destructor called\n";
}
