/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:17:27 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/16 22:23:06 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool        parse(const std::string &filename, const std::string &s1, const std::string &s2);
std::string ft_replace(const std::string &line, const std::string &s1, const std::string &s2);
bool        playMagic(const std::string &filename, const std::string &s1, const std::string &s2);
