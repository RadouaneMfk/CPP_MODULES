#include "Harl.hpp"

void Harl::debug() {
	std::cout << "I love having extra bacon for my" <<
	"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money." <<
	" You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
	<< "years, whereas you started working here just last month.\n";
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level ) {
	int levelIndex;
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			levelIndex = i;
	}
	switch(levelIndex) {
		case 0:
			std::cout << "[ DEBUG ]\n";
			debug();
			break;
		case 1:
			std::cout << "[ INFO ]\n";
			info();
			break;
		case 2:
			std::cout << "[ WARNING ]\n";
			warning();
			break;
		case 3:
			std::cout << "[ ERROR ]\n";
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}
