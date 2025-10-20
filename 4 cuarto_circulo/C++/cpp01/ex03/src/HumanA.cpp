/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 19:19:44 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

/*
    Reference members should be initialized using an initializer list
*/
HumanA::HumanA(std::string name, Weapon &weapon)
    :_name(name), _weapon(weapon)
{
}
HumanA::~HumanA()
{
}

void    HumanA::attack(void)
{
    std::cout << this->_name
    << " attacks with their "
    << this->_weapon.getType()
    << std::endl;
}
