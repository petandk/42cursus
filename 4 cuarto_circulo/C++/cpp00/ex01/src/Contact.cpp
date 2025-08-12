/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:47:25 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/12 22:28:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}
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
}