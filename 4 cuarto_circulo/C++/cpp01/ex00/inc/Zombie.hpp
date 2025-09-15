/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:48:27 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/15 18:38:37 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Zombie
{    
    public:
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
        
    private:
        std::string _name;
        Zombie(void);

};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);