#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ghost") {
    std::cout << "ClapTrap " << this->getName() << " default constructor called!" << std::endl;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name) : name(name) {
    std::cout << "ClapTrap " << this->getName() << " parammeterized constructor called!" << std::endl;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap " << this->getName() << " copy constructor called!" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    name = other.name;
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    return (*this);
}

void ClapTrap::attack(const std::string& target) {
    if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0) {
        this->subEnergyPoint(1);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target
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

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoint() > 0 || this->getHitPoint() > 0) {
        this->subEnergyPoint(1);
        this->addHitPoint(amount);
        std::cout << this->getName()
        << " repair himself, losing 1 energy point, and gain "
        << amount << " hit points" << std::endl; 
        return;
    }
    if (this->getEnergyPoint() <= 0) {
        std::cout << this->getName() << ": i can't repair, i have no energy points :)" << std::endl;
    }
    if (this->getHitPoint() <= 0) {
        std::cout << this->getName() << ": i can't repair, i have no hit points :)" << std::endl;
    }
    return;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoint() == 0) {
        std::cout << this->getName() << ": why you damage me? i'm already destroyed :)" << std::endl;
        return;
    }
    if (amount >= this->getHitPoint()) {
        this->subHitPoint(this->getHitPoint());
        std::cout << this->getName() << " take damage, losing "
        << "all his hit points" << std::endl;
        return;
    }
    this->subHitPoint(amount);
    std::cout << this->getName() << " take damage, losing "
    << amount << " hit points" << std::endl;
    return;
}

std::string ClapTrap::getName() {
    return name;
};

unsigned int ClapTrap::getHitPoint() {
    return hit_points;
};

unsigned int ClapTrap::getEnergyPoint() {
    return energy_points;
};

unsigned int ClapTrap::getAttackDamage() {
    return attack_damage;
};

void ClapTrap::subHitPoint(int val) {
    this->hit_points -= val;
};

void ClapTrap::subEnergyPoint(int val) {
    this->energy_points -= val;
};

void ClapTrap::subAttackDamage(int val) {
    this->attack_damage -= val;
};

void ClapTrap::addHitPoint(int val) {
    this->hit_points += val;
};

void ClapTrap::addEnergyPoint(int val) {
    this->energy_points += val;
};

void ClapTrap::addAttackDamage(int val) {
    this->attack_damage += val;
};

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->getName() << " destructor called!" << std::endl;
};
