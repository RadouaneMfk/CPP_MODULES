#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	index = 0;
	count = 0;
}

void PhoneBook::addContact(Contact contact) {
	index = index % 8;
	arr[index] = contact;
	index++;
	if (count < 8)
		count++;
}

Contact PhoneBook::showContactByIndex(int i) {
	return arr[i];
}

int PhoneBook::getCount() {
	return count;
}

void search_contact(PhoneBook phonebook, std::string &input) {
	while (true)
	{
		std::cout << "Enter Index to display: ";
		getline(std::cin, input);
		if (std::cin.fail())
			exit(0);
		if (input >= "0" && input <= "7" && input[1] == '\0')
		{
			if (phonebook.getCount() > std::stoi(input))
			{
				std::cout << "First name: " 
				<< phonebook.showContactByIndex(std::stoi(input)).getFirst() << std::endl;
				std::cout << "Last name: " 
				<< phonebook.showContactByIndex(std::stoi(input)).getLast() << std::endl;
				std::cout << "Nickname: " 
				<< phonebook.showContactByIndex(std::stoi(input)).getNick() << std::endl;
				std::cout << "Phone number: " 
				<< phonebook.showContactByIndex(std::stoi(input)).getNum() << std::endl;
				std::cout << "Darkest Secret: " 
				<< phonebook.showContactByIndex(std::stoi(input)).getSec() << std::endl;
			}
			break;
		}
		else
			std::cout << "invalid input: enter a number between 0 and 7" << std::endl;
	}
}

void show_table(PhoneBook phonebook) {
	std::cout << std::setw(10) << "index" << " | " 
	<< std::setw(10) << "first name" << " | " 
	<< std::setw(10) << "last name" << " | " 
	<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < phonebook.getCount(); i++)
	{
		std::string first = phonebook.showContactByIndex(i).getFirst();
		std::string last = phonebook.showContactByIndex(i).getLast();
		std::string nick = phonebook.showContactByIndex(i).getNick();
		if (phonebook.showContactByIndex(i).getFirst().length() > 10) {
			first = phonebook.showContactByIndex(i).getFirst().substr(0, 9) + '.';
		}
		if (phonebook.showContactByIndex(i).getLast().length() > 10) {
			last = phonebook.showContactByIndex(i).getLast().substr(0, 9) + '.';
		}
		if (phonebook.showContactByIndex(i).getNick().length() > 10) {
			nick = phonebook.showContactByIndex(i).getNick().substr(0, 9) + '.';
		}
		std::cout << std::setw(10) << i << " | " << std::setw(10) << first << 
		" | " << std::setw(10) << last
		<< " | " << std::setw(10) << nick << std::endl;
	}
}

void check_field_input(std::string field, std::string &input) {
	while (true)
	{
		std::cout << field;
		bool tab = false;
		getline(std::cin, input);
		if (std::cin.fail())
			exit(0);
		for (size_t i = 0; input[i]; i++)
		{
			if (input[i] == '\t')
				tab = true;
		}
		if (tab == true)
			std::cout << "Invalid input!" << std::endl;
		if (!input.empty() && tab == false)
			break;
	}
}

void welcome_msg() {
	std::cout << " -- WELCOME TO MY AWESOME PHONEBOOK -- " << std::endl;
	std::cout << std::setw(37) << " by RED1 " << std::endl;
	std::cout << "•" << std::setw(7) << "ADD" << ": add a contact." << std::endl;
	std::cout << "•" << std::setw(7) << "SEARCH" << ": search for a contact." << std::endl;
	std::cout << "•" << std::setw(7) << "EXIT" << ": quit the program." << std::endl;
}
