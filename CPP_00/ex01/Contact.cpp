#include "Contact.hpp"

void Contact::setFirst(std::string a) {
	first_name = a;
}

void Contact::setLast(std::string a) {
	last_name = a;
}

void Contact::setNick(std::string a) {
	nickname = a;
}

void Contact::setNum(std::string a) {
	phone_number = a;
}

void Contact::setSec(std::string a) {
	darkest_secret = a;
}

std::string Contact::getFirst() {
	return first_name;
}

std::string Contact::getLast() {
	return last_name;
}

std::string Contact::getNick() {
	return nickname;
}

std::string Contact::getNum() {
	return phone_number;
}

std::string Contact::getSec() {
	return darkest_secret;
}
