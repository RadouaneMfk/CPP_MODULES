#pragma once

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void announce( void );
		void setName(std::string str) {
			name = str;
		};
};

Zombie* zombieHorde( int N, std::string name );
