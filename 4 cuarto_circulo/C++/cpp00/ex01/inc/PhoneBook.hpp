/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:34:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 18:11:39 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _index;
	bool _isFull;
	bool showContacts(int &index);
	void showHeader();
	void showRow(int index);
	void showCell(const std::string &text);
	void showInfo(int index);

  public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
};
