#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ghost") {
    std::cout << "ScavTrap " << this->name << " default constructor called\n";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap " << this->name << " parammeterized constructor called\n";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    std::cout << "ScavTrap " << this->name << " copy constructor called\n";
    *this = other;
}

void ScavTrap::attack(const std::string& target) {
    if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0) {
        this->subEnergyPoint(1);
		std::cout << "ScavTrap " << this->name << " attacks " << target
		<< " ,causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        return;
    }
    if (this->getEnergyPoint() <= 0) {
        std::cout << this->name << ": i can't attack, i have no energy points :)" << std::endl;
    }
    if (this->getHitPoint() <= 0) {
        std::cout << this->name << ": i can't attack, i have no hit points :)" << std::endl;
    }
    return;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode.\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destructor called\n";
}
