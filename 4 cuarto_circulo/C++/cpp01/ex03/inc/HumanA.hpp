/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:29:52 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 19:23:40 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

/*
    HumanA weapon should be a reference (&) because it's mandatory (cannot be NULL)
	Something HAS to be = &
	Something CAN be = *
*/
class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void);

    private:
        std::string _name;
        Weapon &_weapon;
};