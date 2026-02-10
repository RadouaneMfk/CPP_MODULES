#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;
	public:
		void setFirst(std::string a);
		void setLast(std::string a);
		void setNick(std::string a);
		void setNum(std::string a);
		void setSec(std::string a);
		std::string getFirst();
		std::string getLast();
		std::string getNick();
		std::string getNum();
		std::string getSec();
};

#endif
