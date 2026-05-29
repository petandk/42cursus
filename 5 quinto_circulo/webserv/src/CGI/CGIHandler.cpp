/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI .cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:56:39 by marvin            #+#    #+#             */
/*   Updated: 2026/05/05 12:26:17 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CGI/CGIHandler.hpp"
#include <iostream>
#include <unistd.h>    
#include <sys/wait.h> 
#include <signal.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <cstdio>
#include <errno.h>


CGIHandler::CGIHandler(const HTTPRequest& req, HTTPResponse& res, const std::vector<uint8_t>& body) : 
    _cgiPid(-1), 
    _fullPath(""),
    _chEnv(NULL),
    _args(NULL),
    _body(body),
    _request(req),
    _response(res)
    
{}

CGIHandler::CGIHandler(const CGIHandler &src) :
    _cgiPid(src._cgiPid),
    _fullPath(src._fullPath),
    _chEnv(NULL),
    _args(NULL),
    _body(src._body),
    _request(src._request),
    _response(src._response)
{}

CGIHandler  &CGIHandler::operator=(const CGIHandler &src)
{
    if (this != &src)
    {
        freeMemory();
        _cgiPid = src._cgiPid;
        _fullPath = src._fullPath;
        _cgiPath = src._cgiPath;
        _env = src._env;
        _chEnv = NULL;
        _args = NULL;
    }
    return (*this);
}

CGIHandler::~CGIHandler()
{
    freeMemory();
}

void    CGIHandler::setCgiPath(const std::string& path)
{
    this->_cgiPath = path;
}

void    CGIHandler::freeMemory()
{
    if (_chEnv)
    {
        for (int i = 0; _chEnv[i]; i++)
            delete[]_chEnv[i];
        delete[]_chEnv;
        _chEnv = NULL;
    }
    if (_args)
    {
        for (int i = 0; _args[i]; i++)
            delete[]_args[i];
        delete[](_args);
        _args = NULL;
    }
}


void    CGIHandler::initEnv(const LocationConfig& loc)
{
    int poz = 0;
    _env["AUTH_TYPE"] = "Basic";

    std::stringstream ss;
    ss << _request.getBody().size();
    _env["CONTENT_LENGTH"] = ss.str();

    _env["CONTENT_TYPE"] = _request.getHeader("content-type");
    _env["GATEWAY_INTERFACE"] = "CGI/1.1";
    _env["SCRIPT_NAME"] = _cgiPath;
    _env["SCRIPT_FILENAME"] = _cgiPath;
    _env["PATH_INFO"] = _request.getPath();
    _env["PATH_TRANSLATED"] = loc.getRoot() + (this->_env["PATH_INFO"] == "" ? "/" : this->_env["PATH_INFO"]);
    _env["QUERY_STRING"] = decode(_request.getQueryString());
    _env["REMOTE_ADDR"] = _request.getHeader("host");
    poz = findStart(_request.getHeader("host"), ":");
    _env["SERVER_NAME"] = (poz > 0 ? _request.getHeader("host").substr(0, poz) : "");
    _env["SERVER_PORT"] = (poz > 0 ? _request.getHeader("host").substr(poz + 1, _request.getHeader("host").size()) : "");
    _env["REQUEST_METHOD"] = _request.getMethod();
    _env["HTTP_COOKIE"] = _request.getHeader("cookie");
    _env["DOCUMENT_ROOT"] = loc.getRoot();
    _env["REQUEST_URI"] = _request.getPath() + _request.getQueryString();
    _env["SERVER_PROTOCOL"] = "HTTP/1.1";
    _env["REDIRECT_STATUS"] = "200";
    _env["SERVER_SOFTWARE"] = "AMANIX";

    // --- RECOPILADOR DE SPECIAL HEADERS (RFC 3875) ---
    const std::map<std::string, std::string>& headers = _request.getHeaders(); 
    std::map<std::string, std::string>::const_iterator headIt;
    
    for (headIt = headers.begin(); headIt != headers.end(); ++headIt)
    {
        std::string headerName = headIt->first;
        std::string headerValue = headIt->second;
        
        std::string envKey = "HTTP_";
        for (size_t j = 0; j < headerName.length(); ++j)
        {
            if (headerName[j] == '-')
                envKey += '_';
            else
                envKey += std::toupper(static_cast<unsigned char>(headerName[j]));
        }
        
        if (_env.find(envKey) == _env.end())
            _env[envKey] = headerValue;
    }

    _chEnv = new char*[_env.size() + 1];

    std::map<std::string, std::string>::iterator it;
    size_t i = 0;
    for (it = _env.begin(); it != _env.end(); it++)
    {
        std::string fullEnv = it->first + "=" + it->second;
        _chEnv[i] = ft_strdup(fullEnv.c_str());
        i++;
    }
    _chEnv[i] = NULL;

    _args = new char*[3];
    _args[0] = ft_strdup(loc.getCgiPass().c_str());
    _args[1] = ft_strdup(_cgiPath.c_str());
    _args[2] = NULL;
}

int CGIHandler::execute()
{
    if (pipe(_pipeOut) < 0)
    {
        _response.setStatusCode(500);
        return (1);
    }

    std::string tmpFile = "/tmp/webserv_cgi_in.tmp";
    
    // 1. Open just to read, write and close
    int fdWrite = open(tmpFile.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fdWrite >= 0)
    {
        if (_request.getMethod() == "POST" && !_body.empty())
            write(fdWrite, _body.data(), _body.size());
        close(fdWrite);
    }

    // 2. Open again just to read
    int fdIn = open(tmpFile.c_str(), O_RDONLY);
    if (fdIn < 0)
    {
        close(_pipeOut[0]); close(_pipeOut[1]);
        _response.setStatusCode(500);
        return (1);
    }

    _cgiPid = fork();
    if (_cgiPid < 0)
    {
        close(_pipeOut[0]); close(_pipeOut[1]); close(fdIn);
        std::remove(tmpFile.c_str());
        _response.setStatusCode(500);
        return (1);
    }

    if (_cgiPid == 0)
    {
        dup2(_pipeOut[1], STDOUT_FILENO);
        dup2(fdIn, STDIN_FILENO); 
        close(_pipeOut[0]); close(_pipeOut[1]); close(fdIn);
        
        execve(_args[0], _args, _chEnv);
        exit(1);
    }
    else
    {
        close(_pipeOut[1]);
        close(fdIn);
        std::remove(tmpFile.c_str());
    }
    
    return (_pipeOut[0]);
}

bool CGIHandler::reapChild()
{
    if (_cgiPid <= 0)
        return (true);
    pid_t result = waitpid(_cgiPid, NULL, 0);
    if (result < 0)
        return (false);
    _cgiPid = -1;
    return (true);
}