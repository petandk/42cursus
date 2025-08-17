/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:47:25 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/13 19:26:15 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Utils.hpp"

/**
 * Default constructor
 * Initializes an empty Contact object
 */
Contact::Contact()
{
}

/**
 * Destructor
 * Cleans up any resources used by the Contact
 */
Contact::~Contact()
{
}

/**
 * Returns the requested field from the contact
 * @param option The field name to retrieve ("firstName", "lastName", etc.)
 * @return The value of the requested field as a string
 */
std::string Contact::getInfo(std::string option)
{
	if (option == "firstName")
		return (this->_firstName);
	else if (option == "lastName")
		return (this->_lastName);
	else if (option == "nickname")
		return (this->_nickname);
	else if (option == "phoneNumber")
		return (this->_phoneNumber);
	else if (option == "darkestSecret")
		return (this->_darkestSecret);
	else
		return ("");
}

/**
 * Prompts the user for input and validates it
 * @param prompt The message to display when requesting input
 * @return A non-empty string entered by the user
 *
 * Handles EOF conditions and empty inputs by reprompting
 * until valid input is received
 */
std::string Contact::readField(const std::string &prompt)
{
	std::string userInput;
	std::string dummy;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, userInput) || userInput.empty())
		{
			if (std::cin.eof())
			{
				std::cout << "\nYou wanted EOF, here it is!" << std::endl;
				
				return ("");
			}
			std::cin.clear();
			std::getline(std::cin, dummy);
			std::cout << "\nInput cannot be empty. Please try again." << std::endl;
			continue;
		}
		return (userInput);
	}
}

/**
 * Populates a contact with user input for all fields
 * @param contact The Contact object to fill with information
 *
 * Uses readField to get and validate each piece of contact information
 */
void Contact::inputFields()
{
	clear_console();
	this->_firstName = this->readField("First Name: ");
	this->_lastName = this->readField("Last Name: ");
	this->_nickname = this->readField("Nickname: ");
	this->_phoneNumber = this->readField("Phone number: ");
	this->_darkestSecret = this->readField("Darkest secret: ");
}