/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/15 20:54:41 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    Zombie  *horde;
    int     num;
    
    if (argc >= 3)
    {
        num = std::atoi(argv[1]);
        horde = zombieHorde(num, argv[2]);
   
        for (int i = 0; i < num; i++)
        {
            horde[i].announce();

        }
        delete[] horde;
     }
     else
        std::cout << "Usage: ./zombie <number> \"name\"\nExample: ./zombie 42 okto" << std::endl;
    return (0);
}