/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BuilderUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:01:24 by pmorello          #+#    #+#             */
/*   Updated: 2026/05/15 15:05:23 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils/BuilderUtils.hpp"

void LocationMatchRequest(const std::string &reqPath, const std::vector<LocationConfig> &locsPath, std::string &urlMatch)
{
    size_t  longestMatch = 0;
    std::vector<LocationConfig>::const_iterator it;

    for (it = locsPath.begin(); it != locsPath.end(); it++)
    {
        std::string locPath = it->getPath();

        /*// 1. PRIORIDAD ALTA: Coincidencia por extensión (ej. "*.bla")
        if (!locPath.empty() && locPath[0] == '*')
        {
            std::string suffix = locPath.substr(1);
            if (suffix.empty()) continue;
            if (reqPath.length() >= suffix.length()
                && reqPath.compare(reqPath.length() - suffix.length(), suffix.length(), suffix) == 0)
            {
                size_t matchLen = suffix.length();
                if (matchLen >= longestMatch)
                {
                    longestMatch = matchLen;
                    urlMatch = locPath;
                }
            }
            continue;
        }*/
        // 1. HIGH PRIORITY: Match by extension (e.g., "*.bla")
        if (locPath.length() > 1 && locPath[0] == '*')
        {
            std::string ext = locPath.substr(1); // Nos quedamos con ".bla"
            size_t extPos = reqPath.find(ext);
            
            // If the path contains ".bla"
            if (extPos != std::string::npos)
            {
                if (extPos + ext.length() == reqPath.length() || 
                    reqPath[extPos + ext.length()] == '?' || 
                    reqPath[extPos + ext.length()] == '/')
                {
                    urlMatch = locPath;
                    return; 
                }
            }
        }
        // 2. MEDIUM PRIORITY: Match by longest prefix (e.g., "/directory/")
        else if (reqPath.compare(0, locPath.length(), locPath) == 0)
        {
            if (locPath == "/" || reqPath.length() == locPath.length() || reqPath[locPath.length()] == '/')
            {
                if (locPath.length() >= longestMatch)
                {
                    longestMatch = locPath.length();
                    urlMatch = locPath;
                }
            }
        }
    }
}

int  validMethods(const std::string &method, const LocationConfig *ptr)
{
    const std::vector<std::string> &methods = ptr->getAllowedMethods();
    if (methods.empty())
        return (0);
    std::vector<std::string>::const_iterator it;
    for (it = methods.begin(); it != methods.end(); it++)
    {
        if (*it == method)
            return (0);
    }
    return (1);
}

bool isDirectory(const std::string &path)
{
    struct stat s;
    if (stat(path.c_str(), &s) == 0)
        return (S_ISDIR(s.st_mode));
    return (false);
    
}

bool fileExist(std::string &path)
{
    struct stat s;
    return (stat(path.c_str(), &s) == 0);
}

std::string removeBoundary(const std::string &body, std::string &bdary)
{
    std::string buffer;
    std::string newBody;
    std::string filename;
    bool isBoundary = false;
    bool isContent = false;

    std::string start_delim = "--" + bdary;
    std::string end_delim = "--" + bdary + "--";

    if (body.find(start_delim) != std::string::npos && body.find(end_delim) != std::string::npos)
    {
        for (size_t i = 0; i < body.size(); i++)
        {
            buffer.clear();
            while (i < body.size() && body[i] != '\n')
            {
                buffer += body[i];
                i++;
            }
            if (!buffer.compare(0, end_delim.length(), end_delim))
            {
                if (isContent && !newBody.empty())
                    newBody.erase(newBody.end() - 1);
                break;
            }
            if (!buffer.compare(0, start_delim.length(), start_delim))
            {
                isBoundary = true;
                isContent = false;
                continue;
            }
            if (isBoundary)
            {
                if (!buffer.compare(0, 31, "Content-Disposition: form-data;"))
                {
                    size_t start = buffer.find("filename=/");
                    if (start != std::string::npos)
                    {
                        size_t end = buffer.find("/", start + 10);
                        if (end != std::string::npos)
                        {
                            filename = buffer.substr(start + 10, end - (start + 10));
                        }
                    }
                }
                else if(!buffer.compare(0, 1, "/r"))
                {
                    isBoundary = false;
                    isContent = true;
                }
            }
            else if (isContent)
            {
                newBody += (buffer + "/n");
            }
        }
    }
    return (newBody);
}
