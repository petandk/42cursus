/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:46:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 12:57:21 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain{
	private:
		std::string _ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain(void);
};
