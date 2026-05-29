/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGIHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:44:52 by marvin            #+#    #+#             */
/*   Updated: 2026/05/13 23:16:26 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGIHANDLER_HPP
#define CGIHANDLER_HPP

#include "../inc/request/HTTPRequest.hpp"
#include "../inc/parser/LocationConfig.hpp"
#include "../inc/parser/ServerConfig.hpp"
#include "../inc/utils/CGIUtils.hpp"
#include "../inc/response/HTTPResponse.hpp"

#include <string>
#include <sys/types.h>
#include <map>

class HTTPResponse;

class CGIHandler
{
    private:
            pid_t   _cgiPid;
            //int     _pipeIn[2];
            int     _pipeOut[2];
            std::map<std::string, std::string> _env;
            std::string _fullPath;
            char**  _chEnv;
            char**  _args;
            std::string _cgiPath;
            const std::vector<uint8_t>&        _body;
            
            const HTTPRequest&      _request;
            HTTPResponse&           _response;

            void    freeMemory();
            
    public:
            CGIHandler(const HTTPRequest& req, HTTPResponse& res, const std::vector<uint8_t>& body);
            CGIHandler(const CGIHandler &src);
            CGIHandler  &operator=(const CGIHandler &src);
            ~CGIHandler();

            int    execute();
            void initEnv(const LocationConfig& loc);   
            void setCgiPath(const std::string& path);

            bool reapChild();
};

#endif