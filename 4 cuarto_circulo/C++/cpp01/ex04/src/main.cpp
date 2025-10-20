/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 19:52:12 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

int main (int argc, char **argv)
{
    if (argc != 4)
    {
		std::cout << "Error: Not enough arguments." << std::endl;
		return (1);
    }
    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    if (!parse(filename, s1))
    {
		std::cout << "Error: Invalid arguments." << std::endl;
		return (1);
    }
	if (!playMagic(filename, s1, s2))
		return (1);
    return (0);
}

