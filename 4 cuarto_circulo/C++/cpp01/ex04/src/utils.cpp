/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:19:04 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 19:46:10 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

/*
	s2 can be empty so it will just remove s1 appearences.
*/
bool    parse(const std::string &filename, const std::string &s1)
{
    return (!filename.empty() && !s1.empty());
}

/*
	finds all <s1> occurences in <line> and replaces it with <s2>
	then returns the modified string.
	if <line> doesn't contain <s1> returns <line>... because is not modified, duh!

	result += line.substr(last, pos - last); -> copies everything to result until s1 POSition
    result += s2;	//copy s2 to result
    last = pos + s1.length(); points to the end of s1, so we can keep checking the rest of line
	Basically, we find s1, ignore it, copy s2 instead, and keep going
*/
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
    }
    result += line.substr(last);
    return (result);
}

/*
	opens <filename> for reading, and creates <filename>.replace as output.
	then reads <filename> line by line and replaces all occurences of <s1> with <s2> using ft_replace
	finally writes the result line to the output file.
	if <filename> or <filename>.replace cannot be opened, writes a error and returns false.
	returns true on success
	filename.c_str -> convertsts std::string to c-string (just because c++98)
*/
bool    playMagic(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::ifstream ifs;
	std::ofstream ofs;
    ifs.open(filename.c_str(), std::ios::in);

    if (!ifs.is_open())
    {
        std::cout << "Cannot open the input file: " << filename << std::endl;
        return (false);
    }
    ofs.open((filename + ".replace").c_str(), std::ios::out);
	if (!ofs.is_open())
    {
        std::cout << "Cannot create the output file: " << filename << ".replace" << std::endl;
		ifs.close();
        return (false);
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        ofs << ft_replace(line, s1, s2) << std::endl;
    }

	ifs.close();
	ofs.close();
	
    return (true);
}