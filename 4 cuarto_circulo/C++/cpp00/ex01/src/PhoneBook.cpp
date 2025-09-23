/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:22:07 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/23 22:16:50 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"

/**
 * Default constructor
 * Initializes an empty PhoneBook object
 * Also initializes the index to 0 and sets the isFull flag to false.
 */
PhoneBook::PhoneBook() : _index(0), _isFull(false)
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
	if (_index >= 8)
	{
		_index = 0;
		_isFull = true;
	}
	if (_contacts[_index].inputFields())
	{
		_index++;
		std::cout << "\nContact added successfully!" << std::endl;
	}
	else
		return ;
}

void PhoneBook::showHeader()
{
	std::cout << std::endl;
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
	std:: string result = text;
	if (result.length() > 10)
		result = result.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << result;
}

void PhoneBook::showRow(int index)
{
	std::cout << std::setw(10) << std::right << index + 1;
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

bool PhoneBook::showContacts(int &index)
{
    int		toShow = _isFull ? 8 : _index;
	bool	badIndex = false;
	bool	isChar = false;

    while (true)
    {
        clear_console();
        showHeader();
        for (int i = 0; i < toShow; i++)
            showRow(i);

        if (badIndex) // index is set to an invalid value after first try
            std::cout << "\n\e[31mIndex must be between 1 and " << toShow << "\e[0m" << std::endl;
		else if (isChar)
			std::cout << "\n\e[33mPlease enter a valid \e[1;33mNUMBER\e[0m\e[33m\e[0m" << std::endl;

        std::cout << "\nPlease select a contact index:" << std::endl;
        if (std::cin >> index)
        {
            std::cin.ignore();
            if (index >= 1 && index <= toShow)
                return true;
			badIndex = true;
			isChar = false;
        }
        else
        {
            if (std::cin.eof())
                return false;
            
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            badIndex = false;
			isChar = true;
        }
    }
}

void PhoneBook::showInfo(int &index)
{
	clear_console();
	std::cout << std::endl;
	std::cout << "First name: " << _contacts[index - 1].getInfo("firstName") << std::endl;
	std::cout << "Last name: " << _contacts[index - 1].getInfo("lastName") << std::endl;
	std::cout << "nickname: " << _contacts[index - 1].getInfo("nickname") << std::endl;
	std::cout << "Phone number: " << _contacts[index - 1].getInfo("phoneNumber") << std::endl;
	std::cout << "Darkest secret: " << _contacts[index - 1].getInfo("darkestSecret") << std::endl;
}

void PhoneBook::searchContact()
{
	int selected = 0;

	if (_index == 0)
	{
		std::cout << "Phonebook is still empty! Please, add contacts first!" << std::endl;
		return ;
	}
	if (this->showContacts(selected))
		this->showInfo(selected);
}
