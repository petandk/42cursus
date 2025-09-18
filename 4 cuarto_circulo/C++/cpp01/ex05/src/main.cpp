/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/18 17:44:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main (int argc, char *argv[])
{
	Harl harl;
	
	if (argc != 2)
	{
		harl.complain("NO");
		harl.complain("BACON");
		harl.complain("FOR");
		harl.complain("YOU");
		std::cout << "Hold my Bacon — I'm about to unleash some premium-grade complaints: " << std::endl;
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		harl.complain("WHATEVER");
	}	
	else
		harl.complain(argv[1]);
	return (0);
}