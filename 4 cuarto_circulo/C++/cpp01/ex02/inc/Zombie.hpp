/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:48:27 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/15 20:43:40 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Zombie
{    
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
        void    setName(std::string name);
    private:
        std::string _name;
};

Zombie *zombieHorde(int N, std::string name);