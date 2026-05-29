/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTPResponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:18:16 by pmorello          #+#    #+#             */
/*   Updated: 2026/05/13 22:51:08 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPRESPONSE_HPP
# define HTTPRESPONSE_HPP

#include <string>
#include <map>
#include "../inc/utils/HTTPStatus.hpp"
#include "../inc/mime/MimeTypes.hpp"
#include <sstream>
#include <ctime>
#include <iostream>

class HTTPResponse
{
        public:
	        HTTPResponse();
	        HTTPResponse(int statusCode);
	        ~HTTPResponse();
	        HTTPResponse(const HTTPResponse& other);
	        HTTPResponse& operator=(const HTTPResponse& other);

	        // Setters
	        void	setStatusCode(int code);
	        void	setHeader(const std::string& name, const std::string& value);
	        void	setBody(const std::string& body);

	        // Getters
	        int					getStatusCode() const;
	        const std::string&	getBody() const;

	        // Serialization
	        std::string	serialize() const;

	        // Factory methods
	        static HTTPResponse	buildErrorResponse(int code);
	        static HTTPResponse	buildErrorResponse(int code, const std::string& customBody);
	        static HTTPResponse	buildRedirectResponse(int code, const std::string& location);

        private:
	        int				        			_statusCode;
	        std::string							_statusMessage;
	        std::map<std::string, std::string>	_headers;
	        std::string							_body;

			

	void	_setDateHeader();
	void	_setServerHeader();

	static std::string	_generateErrorPage(int code, const std::string& message);
};

#endif
