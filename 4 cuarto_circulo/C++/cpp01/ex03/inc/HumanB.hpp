/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:29:52 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/16 20:06:59 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

/*
    HumanB weapon should be pointer because needs to be nullable
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