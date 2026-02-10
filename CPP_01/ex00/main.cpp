#include "Zombie.hpp"

int main() {
	randomChump("Foo");
	Zombie *z;
	z = newZombie("Loo");
	z->announce();
	delete z;

	return 0;
}
