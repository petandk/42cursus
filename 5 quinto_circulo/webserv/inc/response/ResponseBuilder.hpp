/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseBuilder.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:53:34 by marvin            #+#    #+#             */
/*   Updated: 2026/05/15 14:37:37 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSEBUILDER_HPP
#define RESPONSEBUILDER_HPP

#include "../inc/request/HTTPRequest.hpp"
#include "../inc/parser/LocationConfig.hpp"
#include "../inc/parser/ServerConfig.hpp"
#include "../inc/response/HTTPResponse.hpp"
#include "../inc/utils/BuilderUtils.hpp"
#include "../inc/CGI/CGIHandler.hpp"

class Client;

class ResponseBuilder
{
    private:
            std::string             _fullPath;
            int                     _cgiFlag;
            bool                    _indexFlag;
            std::string             _redirectUrl; 
            std::string             _contentType; 
            size_t                  _contentLength;
            
            const HTTPRequest&      _request;
            const ServerConfig&     _serverConf;
            HTTPResponse&           _response;
            CGIHandler&             _cgi;
            const LocationConfig*   _location;

            int     buildHtmlIndex();
            void    buildErrorBody(Client &client);
            int     parsingPath();
            int     buildBody(Client &client);            
            int     readFile(Client &client);
            int     parsingCGIResponse(int fd);
            void    parseAndSetCgiHeads(std::string headPart);

    public:
                ResponseBuilder(const HTTPRequest& request, const ServerConfig& serverConf, HTTPResponse& response, CGIHandler& cgi);
                ResponseBuilder(const ResponseBuilder &src);
                ResponseBuilder &operator=(const ResponseBuilder&src);
                ~ResponseBuilder();

                void    buildResponse(Client &client);
                void    setHeaders();
};

#endif