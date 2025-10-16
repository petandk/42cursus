/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/16 19:50:56 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fixed.hpp"
#include "../inc/point.hpp"

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[1;0m"


/*
	1- Use this link
	https://www.geogebra.org/geometry
	2- Left click->Show Axes
	3- Left click->Settings->Show Mouse Coordinates
	4- Use "Polygon" and create a triangle
	5- Use "Point" and place a point inside/outside
	6- Hover the points to see coords

	INSIDE:
		Point p(2.1f, 4.2f);
	OUTSIDE:
		Point p(0.0f, 0.0f);
*/
int	main(void)
{
	Point a(-2.7f, 5.5f);
	Point b(2.9f, 1.6f);
	Point c(3.2f, 6.0f);

	Point p(2.1f, 4.2f);

	if (bsp(a, b, c, p))
		std::cout << GREEN << "INSIDE" << RESET << std::endl;
	else
		std::cout << RED << "OUTSIDE" << RESET << std::endl;
	
	return (0);
}