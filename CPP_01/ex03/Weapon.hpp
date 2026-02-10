#pragma once

#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string t);
		void setType(std::string str);
		const std::string& getType();
};
