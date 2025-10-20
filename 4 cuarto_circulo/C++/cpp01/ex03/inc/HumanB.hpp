/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:29:52 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 19:23:34 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

/*
    HumanB weapon should be pointer (*) because it's optional (can be NULL)
	Something HAS to be = &
	Something CAN be = *
*/
class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    attack(void);
        void    setWeapon(Weapon &weapon);
    private:
        std::string _name;
        Weapon *_weapon;
};