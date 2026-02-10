#include "HumanB.hpp"

HumanB::HumanB(std::string n): weapon(NULL) {
	this->name = n;
}

void HumanB::setWeapon(Weapon &w) {
	weapon = &w;
}

void HumanB::attack() {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
