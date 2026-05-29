/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BuilderUtils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:02:00 by pmorello          #+#    #+#             */
/*   Updated: 2026/05/13 20:27:18 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDERUTILS_HPP
#define BUILDERUTILS_HPP

#include "../inc/request/HTTPRequest.hpp"
#include "../inc/parser/LocationConfig.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <sys/stat.h>



void LocationMatchRequest(const std::string &reqPath, const std::vector<LocationConfig> &locsPath, std::string &urlMatch);
int  validMethods(const std::string &method, const LocationConfig *ptr);
bool isDirectory(const std::string &path);
bool fileExist(std::string &path);
std::string removeBoundary(const std::string &body, std::string &bdary);



#endif