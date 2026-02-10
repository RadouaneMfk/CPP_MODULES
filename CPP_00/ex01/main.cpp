#include "PhoneBook.hpp"

int main (int ac, char *av[])
{
	if (ac > 1)
		return (1);
	(void)av;
	Contact contact;
	PhoneBook phonebook;
	std::string input;
	welcome_msg();

	while (true)
	{
		std::cout << "Enter a command: ";
		getline(std::cin, input);
		if (std::cin.fail())
			exit(0);
		if (input != "ADD" && input != "EXIT" && input != "SEARCH")
			std::cout << "Ohoya Oho, Enter one of the following: ADD, SEARCH and EXIT" << std::endl;
		if (input == "ADD")
		{
			check_field_input("First name: ", input);
			contact.setFirst(input);
			check_field_input("Last name: ", input);
			contact.setLast(input);
			check_field_input("Nickname: ", input);
			contact.setNick(input);
			check_field_input("Phone number: ", input);
			contact.setNum(input);
			check_field_input("Darkest Secret: ", input);
			contact.setSec(input);
			phonebook.addContact(contact);
		}
		if (input == "SEARCH")
		{
			show_table(phonebook);
			search_contact(phonebook, input);
		}
		if (input == "EXIT")
		{
			std::cout << "LA 3AFAK MATMCHICH :)" << std::endl;
			exit(0);
		}
	}
	return (0);
}
