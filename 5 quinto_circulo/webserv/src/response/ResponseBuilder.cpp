/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseBuilder.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:14:30 by marvin            #+#    #+#             */
/*   Updated: 2026/05/15 15:42:08 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/response/ResponseBuilder.hpp"
#include "../inc/server/Client.hpp"
#include "../inc/mime/MimeTypes.hpp"

#include <fstream>
#include <map>
#include <sstream>
#include <dirent.h>
#include <algorithm>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>

static int responseToFd(const std::string &data)
{
    // Unic names generator C++98 legal
    static int fileCounter = 0;
    std::stringstream ss;
    ss << "/tmp/webserv_resp_" << fileCounter++;
    std::string tempFile = ss.str();

    // 1. Open to write
    int writeFd = open(tempFile.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (writeFd < 0) return (-1);

    ssize_t totalWritten = 0;
    ssize_t dataSize = data.size();
    const char *ptr = data.c_str();

    // Dump the 100MB
    while (totalWritten < dataSize) {
        ssize_t bytes = write(writeFd, ptr + totalWritten, dataSize - totalWritten);
        if (bytes < 0) {
            close(writeFd);
            std::remove(tempFile.c_str());
            return (-1);
        }
        totalWritten += bytes;
    }
    close(writeFd);

    // 2. Open to read
    int readFd = open(tempFile.c_str(), O_RDONLY);

    // Delete the tmp file from de disk. 
    std::remove(tempFile.c_str());

    return (readFd);
}
/*static int responseToFd(const std::string &data)
{
    int pipeFds[2];
    if (pipe(pipeFds) < 0)
        return (-1);
 
    ssize_t written = write(pipeFds[1], data.c_str(), data.size());
    close(pipeFds[1]);
 
    if (written < 0)
    {
        close(pipeFds[0]);
        return (-1);
    }
    return (pipeFds[0]);
}*/


ResponseBuilder::ResponseBuilder(const HTTPRequest& request, const ServerConfig& serverConf, HTTPResponse& response, CGIHandler& cgi) :
    _fullPath(""),
    _cgiFlag(0),
    _indexFlag(false),
    _redirectUrl(""),
    _contentType(""),
    _contentLength(0),
    _request(request),
    _serverConf(serverConf),
    _response(response),
    _cgi(cgi),
     _location(NULL)
{}

ResponseBuilder::ResponseBuilder(const ResponseBuilder& src) :
    _fullPath(src._fullPath),
    _cgiFlag(src._cgiFlag),
    _indexFlag(src._indexFlag),
    _redirectUrl(src._redirectUrl),
    _contentType(src._contentType),
    _contentLength(src._contentLength),
    _request(src._request),
    _serverConf(src._serverConf),
    _response(src._response),
    _cgi(src._cgi),
    _location(src._location)
{}

ResponseBuilder &ResponseBuilder::operator=(const ResponseBuilder& src)
{
    if (this != &src)
    {
        _fullPath = src._fullPath;
        _cgiFlag = src._cgiFlag;
        _indexFlag = src._indexFlag;
        _redirectUrl = src._redirectUrl;
        _contentType = src._contentType;
        _contentLength = src._contentLength;
        _response = src._response;
        _cgi = src._cgi;
    }
    return (*this);
}

ResponseBuilder::~ResponseBuilder() {}

int ResponseBuilder::readFile(Client &client)
{
    (void)client;
    std::ifstream file(_fullPath.c_str(), std::ios::binary);
    if (!file.is_open())
    {
        _response.setStatusCode(404);
        return (1);
    }
    std::stringstream ss;
    ss << file.rdbuf();
    _response.setBody(ss.str());
    file.close();
    return (0);
}

void ResponseBuilder::setHeaders()
{
    MimeTypes mime;
    if (_contentType.empty() || _contentType == "text/plain")
    {
        if (!_fullPath.empty())
        {
            size_t dot = _fullPath.find_last_of(".");
            if (dot != std::string::npos)
                _contentType = mime.getMimeType(_fullPath.substr(dot));
        }
    }
    if (_contentType.empty())
        _contentType = "application/octet-stream";
 
    _response.setHeader("Content-Type", _contentType);
 
    std::stringstream ss;
    ss << _response.getBody().size();
    _response.setHeader("Content-Length", ss.str());
 
    if (_request.getHeader("connection") == "keep-alive")
        _response.setHeader("Connection", "keep-alive");
    else
        _response.setHeader("Connection", "close");
 
    if (_response.getStatusCode() >= 300 && _response.getStatusCode() < 400 && !_redirectUrl.empty())
        _response.setHeader("Location", _redirectUrl);
}


int ResponseBuilder::buildHtmlIndex()
{
    DIR *directory = opendir(_fullPath.c_str());
    if (directory == NULL) 
        return (1);
    std::ostringstream oss;
    oss << "<html><head><title>Index of ";
    oss << _request.getPath() << "</title></head>";
    oss << "<body><h1>Index of " << _request.getPath() << "</h1><hr><table>";
    
    struct dirent *entity;
    while((entity = readdir(directory)) != NULL)
    {
        if(std::string(entity->d_name) == ".") 
            continue;
        oss << "<tr><td><a href=\"" << entity->d_name << "\">";
        oss << entity->d_name << "</a></td></tr>";
    }
    oss << "</table><hr></body></html>";
    closedir(directory);
    _response.setBody(oss.str());
    _contentType = "text/html"; 
    return (0);
}
/*
void    ResponseBuilder::buildErrorBody(Client &client)
{
    int code = _response.getStatusCode();
    if (_serverConf.getErrorPages().count(code))
    {
        if (_location == NULL)
        {   
            std::string root = "./www";
            _fullPath = root + _serverConf.getErrorPages().at(code);
        }
        else
            _fullPath = _location->getRoot() + _serverConf.getErrorPages().at(code);
        if (readFile(client) == 1)
            return ;
    }
    _response = HTTPResponse::buildErrorResponse(code);
}*/
void ResponseBuilder::buildErrorBody(Client &client)
{
    int code = _response.getStatusCode();
    if (_serverConf.getErrorPages().count(code))
    {
        std::string root = (_location ? _location->getRoot() : "./www");
        _fullPath = root + _serverConf.getErrorPages().at(code);

        if (_fullPath.size() >= 4
            && _fullPath.compare(_fullPath.size() - 4, 4, ".php") == 0)
        {
            _cgiFlag = 1;
            _cgi.setCgiPath(_fullPath);
            return;
        }

        if (readFile(client) == 0)
        {
            _contentType = "text/html";
            return;
        }
    }
    _response = HTTPResponse::buildErrorResponse(code);
}

int ResponseBuilder::parsingPath()
{
    std::string urlMatch = "";
    LocationMatchRequest(_request.getPath(), _serverConf.getLocations(), urlMatch);
    if (urlMatch.empty())
    {
        _response.setStatusCode(404);
        return (1);
    }
    
    const std::vector<LocationConfig>& locations = _serverConf.getLocations();
    std::vector<LocationConfig>::const_iterator it;
    for (it = locations.begin(); it != locations.end(); it++)
    {
        if (urlMatch == it->getPath())
        {
            _location = &(*it);
            break ;
        }
    }
    
    if (!_location)
    {
        _response.setStatusCode(404);
        return (1);
    }
    if (validMethods(_request.getMethod(), _location))
    {
        _response.setStatusCode(405);
        return (1);
    }
    if (_location->getRedirectCode() != 0)
    {
        _response.setStatusCode(_location->getRedirectCode());
        _redirectUrl = _location->getRedirectUrl();
        return (1);
    }

    std::string root = _location->getRoot();
    std::string path = _request.getPath();
    std::string locPrefix = _location->getPath();

    
    
    // ==========================================
    // ALIAS BEHAVIOR (Replacement)
    // ==========================================
    if (!locPrefix.empty() && locPrefix[0] != '*')
    {
        if (path.compare(0, locPrefix.length(), locPrefix) == 0)
            path = path.substr(locPrefix.length()); 
        else if (path + "/" == locPrefix)
            path = "/";
    }

    // Clean construction of the physical path
    if (path.empty()) {
        _fullPath = root;
    } else {
        bool rootEndsWithSlash = (!root.empty() && root[root.length() - 1] == '/');
        bool pathStartsWithSlash = (!path.empty() && path[0] == '/');

        if (rootEndsWithSlash && pathStartsWithSlash)
            _fullPath = root + path.substr(1);
        else if (!rootEndsWithSlash && !pathStartsWithSlash)
            _fullPath = root + "/" + path;
        else
            _fullPath = root + path;
    }

    // ==========================================
    // DIRECTORIES AND INTERNAL REDIRECT
    // ==========================================
    if (isDirectory(_fullPath))
    {
        if ((_request.getMethod() == "POST" || _request.getMethod() == "PUT") ) 
        {
            std::string rootStr = _location->getRoot();
            std::string reqPath = _request.getPath();
            
            // Secure concatenation to avoid double // (ej: ./www/html//post_body)
            if (!rootStr.empty() && rootStr[rootStr.length() - 1] == '/' && !reqPath.empty() && reqPath[0] == '/')
                _fullPath = rootStr + reqPath.substr(1);
            else if (!rootStr.empty() && rootStr[rootStr.length() - 1] != '/' && !reqPath.empty() && reqPath[0] != '/')
                _fullPath = rootStr + "/" + reqPath;
            else
                _fullPath = rootStr + reqPath;
            return (0);
        }
        
        // The 301 MUST verify the original customer request, not the path on your hard drive.
        std::string reqPath = _request.getPath();
        if (reqPath[reqPath.length() - 1] != '/')
        {
            _response.setStatusCode(301);
            _redirectUrl = reqPath + "/";
            return (1);
        }

        std::string basePath = _fullPath;
        if (basePath[basePath.length() - 1] == '/')
            basePath.erase(basePath.length() - 1, 1);

        const std::vector<std::string>& indexFiles = _location->getIndexFiles();
        bool indexFound = false;

        for (size_t i = 0; i < indexFiles.size(); i++)
        {
            std::string indexPath = basePath + "/" + indexFiles[i];
            if (fileExist(indexPath))
            {
                _fullPath = indexPath;
                indexFound = true;
                break;
            }
        }

        // If there is no real index, we force it to look for the fake one.
        if (!indexFound && !indexFiles.empty() && !_location->getAutoindex())
        {
            _fullPath = basePath + "/" + indexFiles.back();
        }
        else if (isDirectory(_fullPath))
        {
            if (_location->getAutoindex())
            {
                _indexFlag = true;
                return (0);
            }
            _response.setStatusCode(403);
            return (1);
        }
    }
    // We identify if this location is for a CGI:
    bool isCgiBlock = (!locPrefix.empty() && locPrefix[0] == '*') 
                      || locPrefix.find("cgi-bin") != std::string::npos 
                      || !_location->getCgiExtension().empty();

    // If the file does NOT exist, and it is NOT a CGI block either, then it is a real 404 Error.
    if (!fileExist(_fullPath) && !isCgiBlock && _request.getMethod() != "POST" && _request.getMethod() != "PUT" )
    {
        _response.setStatusCode(404);
        return (1);
    }

    // Final CGI checks
    if (_location->getPath().find("cgi-bin") != std::string::npos)
    {
        _cgiFlag = 1;
        _cgi.setCgiPath(_fullPath);
        return (0);
    }
    if (!_location->getCgiExtension().empty())
    {
        const std::string ext = _location->getCgiExtension();
        if (_fullPath.size() >= ext.size() && _fullPath.compare(_fullPath.size() - ext.size(), ext.size(), ext) == 0)
        {
            _cgiFlag = 1;
            _cgi.setCgiPath(_fullPath);
            return (0);
        }
    }
    
    return (0);
}

int ResponseBuilder::buildBody(Client &client)
{
    // 1. FIRST: We perform parsing to determine our location.
    if (parsingPath())
    {
        buildErrorBody(client);
        return (1);
    }
    // 2. SECOND: Now that we have _location, we get its real limit
    size_t limit = _serverConf.getClientMaxBodySize();
    if (_location != NULL)
        limit = _location->getLocationMaxBodySize();

    // 3. THIRD: We check the size limit before touching anything
    if (_request.getBody().size() > limit)
    {
        _response.setStatusCode(413);
        buildErrorBody(client);
        return (1);
    }
    
    if (_cgiFlag == 1 || _indexFlag == true)
        return (0);
    std::string method = _request.getMethod();
    if (method == "GET")
    {
        if (readFile(client) != 0)
        {
            _response.setStatusCode(404);
            buildErrorBody(client);
            return (1);
        }
        _contentType = "text/plain";
    }
    else if (method == "POST" || method == "PUT")
    {
        std::ofstream   file(_fullPath.c_str(), std::ios::binary);
        if (!file.is_open())
        {
            _response.setStatusCode(500);
            buildErrorBody(client);
            return (1);
        }
        
        const std::vector<uint8_t>& bodyData = _request.getBody();
        std::string rawData(reinterpret_cast<const char*>(bodyData.data()), bodyData.size());
        std::string contentType = _request.getHeader("content-Type");
        if (contentType.find("multipart/form-data") != std::string::npos)
        {
            size_t  boundaryPos = contentType.find("boundary=");
            if (boundaryPos != std::string::npos)
            {
                std::string boundary = contentType.substr(boundaryPos + 9);
                std::string cleanBody = removeBoundary(rawData, boundary);
                file.write(cleanBody.c_str(), cleanBody.length());
            }
            else
                file.write(rawData.data(), rawData.size());
        }
        else
            file.write(rawData.data(), rawData.size());
        file.close();
        _response.setStatusCode(201);
    }
    else if (method == "DELETE")
    {
        if (std::remove(_fullPath.c_str()))
            _response.setStatusCode(404);
        else
            _response.setStatusCode(204);
    }
    if (_response.getStatusCode() == 0)
        _response.setStatusCode(200);
    return (0);
}

void    ResponseBuilder::buildResponse(Client& client)
{
    if (buildBody(client))
    {
        if (_cgiFlag != 1)
        {
            setHeaders();
            int fd = responseToFd(_response.serialize());
            if (fd >= 0)
                client.setResponseFd(fd);
            return;
        }
    }
    if (_cgiFlag == 1)
    {
        _cgi.initEnv(*_location);
        int cgiFD = _cgi.execute();
        if (cgiFD > 0)
        {
            parsingCGIResponse(cgiFD);
            _cgi.reapChild();
        }    
    }

    if (_indexFlag == true)
    {
        if (buildHtmlIndex())
        {
            _response.setStatusCode(500);
            buildErrorBody(client);
        }
        else
            _response.setStatusCode(200);
    }

    if (_response.getStatusCode() == 0)
        _response.setStatusCode(200);  

    setHeaders();
    int fd = responseToFd(_response.serialize());
    if (fd >= 0)
        client.setResponseFd(fd);
}

int    ResponseBuilder::parsingCGIResponse(int fd)
{
    char   buffer[4096];
    ssize_t  bytesRead;
    std::string cgiResponse;
    while ((bytesRead = read(fd, &buffer, sizeof(buffer))) > 0)
            cgiResponse.append(buffer, bytesRead);
    if (bytesRead < 0)
        return (close(fd), 1);
    close(fd);
    std::string cgiHead; 
    std::string cgiBody;
    size_t  sep = cgiResponse.find("\r\n\r\n");
    if (sep != std::string::npos)
    {
        cgiHead = cgiResponse.substr(0, sep);
        cgiBody = cgiResponse.substr(sep + 4);
    }
    else
    {
        sep = cgiResponse.find("\n\n");
        if (sep != std::string::npos)
        {
            cgiHead = cgiResponse.substr(0, sep);
            cgiBody = cgiResponse.substr(sep + 2);
        }
        else
        {
            cgiBody = cgiResponse;
        }
    }
    if(!cgiHead.empty())
        parseAndSetCgiHeads(cgiHead);
    _response.setBody(cgiBody);
    return (0);
}

void    ResponseBuilder::parseAndSetCgiHeads(std::string headPart)
{
    std::stringstream ss;
    ss << headPart;
    std::string line;
    while (std::getline(ss, line))
    {
       if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
       if (line.empty())
            continue;
        size_t  colonPos = line.find(":");
        if (colonPos != std::string::npos)
        {
            std::string key = line.substr(0, colonPos);
            std::string value = line.substr(colonPos + 1);
            size_t  first = value.find_first_not_of(" ");
            if (first != std::string::npos)
                value = value.substr(first);
            if (key == "Status")
            {
                int code = std::atoi(value.substr(0, 3).c_str());
                _response.setStatusCode(code);
            }
            else if (key == "Content-Type")
            {
                _response.setHeader("Content-Type", value);
                _contentType = value;
            }
            else if (key == "Location")
            {
                _response.setStatusCode(302);
                _response.setHeader("Location", value);
            }
            else
                _response.setHeader(key, value);
        }
    }
}