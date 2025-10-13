/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/13 21:52:44 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/point.hpp"

/*
	Default constructor, initializes x and y to 0.
	they go as 
	funct : _var1(value), _var2(value2)
	because that is how const variables are initialized.
*/
Point::Point(void): _x(0), _y(0)
{
}
/*
	Destructor
*/
Point::~Point(void)
{
}

/*
	float constructor
*/
Point::Point(const float n1, const float n2): _x(n1), _y(n2)
{
}

/*
	Copy constructor
	remember src is the original!!
	"this" is the destination:
	Point p2(p1);
	Gets the content of p1 and copies it on p2
	so p1 is src and "this" is p2!!
	also cant use "this->" because the object (p2)
	doesn't exist yet.
*/
Point::Point(const Point &src): _x(src._x), _y(src._y)
{
}

/*
	Copy assignment operator
	PROBLEM!! both x and y are const vars so...
	the p1 = p2 will do nothing,
	values are set using the constructor and are const!!!
	Just need to be here because of Orthodox Canonical Form
*/
Point &Point::operator=(const Point &src)
{
	(void)src;
	return (*this);
}

/*
	Since _x and _y are private, I need getters, so...
	NOTE:
	dont use & because they are private, not safe;
	return a copy instead, good boi
*/

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}