/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/16 19:42:37 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
}
HumanB::~HumanB()
{
}
void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
void    HumanB::attack(void)
{
    std::cout << this->_name;
    if (this->_weapon)
        std::cout << " attacks with their " << this->_weapon->getType();
    else
        std::cout << " has no weapon";
    std::cout << std::endl;
}
