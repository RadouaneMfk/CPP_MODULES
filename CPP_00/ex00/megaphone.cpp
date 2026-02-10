#include <iostream>

int main(int ac, char *av[])
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (isalpha(av[i][j]) && islower(av[i][j]))
				av[i][j] -= 32;
		}
		std::cout << av[i];
		if (av[i + 1] == NULL)
			std::cout << "\n";
	}
	return (0);
}
