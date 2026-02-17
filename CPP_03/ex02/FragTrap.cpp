#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("ghost") {
    std::cout << "FragTrap " << this->getName() << " default contructor called\n";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << this->getName() << " parammeterized contructor called\n";
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "FragTrap " << this->getName() << " copy contructor called\n";
    *this = other;
}

void FragTrap::attack(const std::string& target) {
    if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0) {
        this->subEnergyPoint(1);
		std::cout << "FragTrap " << this->getName() << " attacks " << target
		<< " ,causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        return;
    }
    if (this->getEnergyPoint() <= 0) {
        std::cout << this->getName() << ": i can't attack, i have no energy points :)" << std::endl;
    }
    if (this->getHitPoint() <= 0) {
        std::cout << this->getName() << ": i can't attack, i have no hit points :)" << std::endl;
    }
    return;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " request a high five.\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->getName() << " destructor called\n";
}
