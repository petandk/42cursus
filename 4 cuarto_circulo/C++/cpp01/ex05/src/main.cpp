/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 20:03:00 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main (int argc, char *argv[])
{
	Harl harl;
	
	if (argc != 2)
	{
		std::cout << "==================================" << std::endl;
        std::cout << "         Invalid cases" << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << std::endl;
		harl.complain("NO");
		harl.complain("BACON");
		harl.complain("FOR");
		harl.complain("YOU");
        harl.complain("");
		harl.complain("WHATEVER");
        harl.complain("debug");
		std::cout << std::endl;
		std::cout << "=============================================" << std::endl;
        std::cout << "Hold my Bacon — I'm about to unleash some premium-grade complaints" << std::endl;
        std::cout << "=============================================" << std::endl;
		std::cout << std::endl;
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		std::cout << std::endl;
		std::cout << "=============================================" << std::endl;
        std::cout << " Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
        std::cout << "=============================================" << std::endl;
	}	
	else
		harl.complain(argv[1]);
	return (0);
}