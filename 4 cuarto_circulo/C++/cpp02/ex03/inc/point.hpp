/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:33:56 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/16 17:57:08 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/fixed.hpp"

class Point{
	public:
		Point(void);
		~Point(void);

		Point(const float n1, const float n2);

		Point(const Point &src);
	
		Point &operator=(const Point &other);

		Fixed getX(void) const;
		Fixed getY(void) const;
		
	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);