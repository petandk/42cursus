/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:19:04 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/16 22:23:05 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

bool    parse(const std::string &filename, const std::string &s1, const std::string &s2)
{
    if(!filename.empty() && !s1.empty() && !s2.empty())
        return (true);
    return (false);
}

std::string ft_replace(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::size_t pos;
    std::size_t last = 0;
    std::string result;
    while (true)
    {
        pos = line.find(s1, last);
        if (pos == std::string::npos)
            break;
        result += line.substr(last, pos - last);
        result += s2;
        last = pos + s1.length();
        result += line.substr(last);
    }
    return (result);
}

bool    playMagic(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::ifstream ifs;
    ifs.open(filename.c_str(), std::ios::in);
    std::ofstream ofs;
    ofs.open((filename + ".replace").c_str(), std::ios::out);
    if (!ifs.is_open() || !ofs.is_open())
    {
        std::cout << "Cannot open the file: " << filename << std::endl;
        return (false);
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        ofs << ft_replace(line, s1, s2) << std::endl;
    }
    return (true);
}