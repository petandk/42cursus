/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/18 17:55:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main (int argc, char *argv[])
{
	Harl harl;
	
	if (argc != 2)
		harl.complain("NO");
	else
		harl.complain(argv[1]);
	return (0);
}