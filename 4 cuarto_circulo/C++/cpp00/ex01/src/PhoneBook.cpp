/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:22:07 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/13 20:34:51 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * Default constructor
 * Initializes an empty PhoneBook object
 */
PhoneBook::PhoneBook()
{
}

/**
 * Destructor
 * Cleans up any resources used by the PhoneBook
 */
PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
	_contacts[_index % 8].inputFields();
	_index++;
}
void PhoneBook::showHeader()
{
	std::cout << std::setw(10) << "INDEX";
	std::cout << " | ";
	std::cout << std::setw(10) << "FIRST NAME";
	std::cout << " | ";
	std::cout << std::setw(10) << "LAST NAME";
	std::cout << " | ";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
}

void PhoneBook::showCell(std::string &text)
{
	if (text.length() > 10)
		text = text.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << text;
}
void PhoneBook::showRow(int index)
{
	std::cout << index + 1;
	std::string firstname = _contacts[index].getInfo("firstName");
	std::string lastname = _contacts[index].getInfo("lastName");
	std::string nickname = _contacts[index].getInfo("nickname");
	std::cout << " | ";
	showCell(firstname);
	std::cout << " | ";
	showCell(lastname);
	std::cout << " | ";
	showCell(nickname);
	std::cout << std::endl;
}
void PhoneBook::showContacts(int &index)
{
	showHeader();
	for (int i = 0; i < 8; i++)
		showRow(i);
	while (true)
	{
		std::cout << "Please select a contact index" << std::endl;
		if (std::cin >> index)
		{
			if (index >= 1 && index <= 8)
				break ;
			else
				std::cout << "Index must be between 1 and 8" << std::endl;
		}
		else
		{
			std::cout << "Please enter a valid number" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}
void PhoneBook::showInfo(int &index)
{
	std::cout << "First name: " << _contacts[index].getInfo("firstName") << std::endl;
	std::cout << "Last name: " << _contacts[index].getInfo("lastName") << std::endl;
	std::cout << "nickname: " << _contacts[index].getInfo("nickname") << std::endl;
	std::cout << "Phone number: " << _contacts[index].getInfo("phoneNumber") << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getInfo("darkestSecret") << std::endl;
}

void PhoneBook::searchContact()
{
	int selected;

	this->showContacts(selected);
	this->showInfo(selected);
}