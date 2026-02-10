#include "ft_replace.hpp"

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Arguments error: ./replace filename s1 s2\n";
		exit(1);
	}
	std::string line;
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string resultStr;
	std::ifstream ini_file(filename);
	if (ini_file.fail())
		exit(1);
	std::ofstream out_file(filename.append(".replace"));
	if (ini_file && out_file)
	{
		while (std::getline(ini_file, line)) {
			if (!s1.empty())
				replace_str(line, s1, s2, resultStr);
			if (!ini_file.eof())
				resultStr.append("\n");
		}
	}
	out_file << resultStr;
}
