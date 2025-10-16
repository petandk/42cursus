/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/16 19:22:27 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/point.hpp"

static Fixed abs(Fixed val)
{
	if (val < 0)
		val = val * Fixed(-1);
	return (val);
}

/*
	Triangles Area Approach:
	We create 3 triangles.
	ABP, BCP and ACP.
	If the sum of the 3 areas are = original Triangle, 
	then P is inside the triangle.
	Else one of the triangles makes the area bigger than original,
	so point has to be outside.
	Check here for image:
	https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle
*/
static Fixed triangleArea(Point const a, Point const b, Point const c)
{
	Fixed abx = b.getX() - a.getX();
	Fixed aby = b.getY() - a.getY();
	Fixed acx = c.getX() - a.getX();
	Fixed acy = c.getY() - a.getY();

	return (abs(((abx * acy) - (aby * acx))) / 2);
} 

/*
	a, b, c = triangle vertex
	point... the point!
	return:
		true = point is inside triangle.
		false = is not!
	I modified the "Triangles Area Approach",
	because the subject says:
	"if the point is a vertex or on an edge, it will return False"
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle = triangleArea(a, b, c);
	Fixed area1 = triangleArea(a, b, point);
	Fixed area2 = triangleArea(a, c, point);
	Fixed area3 = triangleArea(b, c, point);
	Fixed sum;

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);

	sum = area1 + area2 + area3;

	if (triangle == sum)
		return (true);
	else
		return (false);
}