#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string n);
		void setWeapon(Weapon &w);
		void attack();
};
