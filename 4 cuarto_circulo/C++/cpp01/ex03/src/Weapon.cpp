/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/16 19:31:21 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string &type)
{
    this->_type = type;
}
Weapon::~Weapon()
{}

const   std::string &Weapon::getType(void) const
{
    return (this->_type);
}

void	Weapon::setType(const std::string &type)
{
	this->_type = type;
}