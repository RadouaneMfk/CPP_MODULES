#include "ft_replace.hpp"

void replace_str(std::string line, std::string s1, std::string s2, std::string& res) {
	int i = 0;
	int j = line.length();
	
	while (i < j) {
		std::string str = line.substr(i, s1.length());
		if (str == s1) {
			res.append(s2);
			i += s1.length();
		} else {
			res = res + line[i];
			i++;
		}
	}
}
