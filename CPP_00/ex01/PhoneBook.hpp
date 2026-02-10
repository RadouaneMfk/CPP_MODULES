#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
	private:
		Contact arr[8];
		int index;
		int count;
	public:
		PhoneBook();
		void addContact(Contact contact);
		Contact showContactByIndex(int i);
		int getCount();
};

void search_contact(PhoneBook phonebook, std::string &input);
void check_field_input(std::string field, std::string &input);
void show_table(PhoneBook phonebook);
void welcome_msg();

#endif