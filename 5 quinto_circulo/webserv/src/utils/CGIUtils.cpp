/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGIUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:27:41 by pmorello          #+#    #+#             */
/*   Updated: 2026/05/14 15:26:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils/CGIUtils.hpp"

template <typename T>
std::string ToString(const T val)
{
    std::stringstream ss;
    ss << val;
    return (ss.str());
}

unsigned int    fromHexToDec(const std::string &nb)
{
    unsigned int x;
    std::stringstream ss;
    ss << std::hex << nb;
    ss >> x;
    return (x);
}

char*   ft_strdup(const char *str)
{
    if (!str)
        return (NULL);
    size_t  i = 0;
    while (str[i] != '\0')
        i++;
    char* res = new char[i + 1]; 
    if (!res)
        return (NULL);
    i = 0;
    while (str[i])
    {
        res[i] = str[i];
        i++; 
    }
    res[i] = '\0';
    return (res);
}

int     findStart(const std::string path, const std::string delim)
{
    if (path.empty())
        return (-1);
    size_t poz = path.find(delim);
    if (poz != std::string::npos)
        return (poz);
    else
        return (-1);
}

std::string decode(const std::string& path)
{
    std::string res = path;
    size_t token = res.find("%");
    while (token != std::string::npos)
    {
        if (res.length() < token + 2)
            break ;
        char decimal = fromHexToDec(res.substr(token + 1, 2));
        res.replace(token, 3, ToString(decimal));
        token = res.find("%");
    }
    return (res);
}

std::string getPathInfo(const std::string& path, std::string extension)
{
	if (extension.empty())
        return "";
    size_t start = path.find(extension);
	if (start == std::string::npos)
		return "";
    size_t  end = start + extension.length();
	if (end >= path.size())
		return "";
	std::string tmp = path.substr(end);
	if (!tmp.empty() || tmp[0] != '/')
		return "";
    size_t  querypos = tmp.find("?");
	if (querypos != std::string::npos)
        return tmp;
    return (tmp.substr(0, querypos));
}