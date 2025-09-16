/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:20:07 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/16 19:31:16 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
 {
    public:
        Weapon(void);
        Weapon(const std::string &type);
        ~Weapon(void);
        const std::string &getType(void) const;
        void setType(const std::string &type);
    private:
        std::string _type;
 };