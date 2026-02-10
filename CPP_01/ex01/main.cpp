#include "Zombie.hpp"

int main() {
	Zombie *z;
	int N = 5;
	z = zombieHorde(N, "Foo");
	int i = 0;
	while (i < N)
	{
		z[i].announce();
		i++;
	}
	delete [] z;
	return 0;
}
