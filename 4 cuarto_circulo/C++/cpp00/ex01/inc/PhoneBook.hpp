/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:34:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/12 22:35:39 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _index;

  public:
	PhoneBook();
	~PhoneBook();
};