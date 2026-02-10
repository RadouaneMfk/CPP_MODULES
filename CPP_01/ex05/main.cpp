#include "Harl.hpp"
#include <string>
#include <iostream>

int main() {
	Harl x;
	x.complain("DEBUG");
	x.complain("INFO");
	x.complain("WARNING");
	x.complain("ERROR");
}
