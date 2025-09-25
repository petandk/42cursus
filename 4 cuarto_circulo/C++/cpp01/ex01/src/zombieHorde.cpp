/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:24:30 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/25 20:13:56 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

Zombie *zombieHorde(int N, std::string name)
{	if (N <= 0)
    {
		std::cout << "Cannot have negative zombies!" << std::endl;
		return (NULL);
	}
    if (name.empty())
    {
        std::cout << "Name can't be empty!" << std::endl;
        return (NULL);    
    }
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}