#include "Weapon.hpp"

Weapon::Weapon(std::string t) {
	this->type = t;
}

void Weapon::setType(std::string str) {
	type = str;
}

const std::string& Weapon::getType() {
	return type;
}
