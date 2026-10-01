#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "ivalid arguments: ./btc inputFile.txt\n";
		return 1;
	}
	try
	{
		BitcoinExchange a("data.csv");
		a.handleInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
