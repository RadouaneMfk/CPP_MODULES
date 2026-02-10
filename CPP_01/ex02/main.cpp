#include <string>
#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";

	std::cout << str << std::endl;
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	// adresses:
	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	//values:
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
