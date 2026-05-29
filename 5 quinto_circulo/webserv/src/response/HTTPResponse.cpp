/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:37:25 by pmorello          #+#    #+#             */
/*   Updated: 2026/04/28 10:44:28 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HTTPResponse.hpp"

HTTPResponse::HTTPResponse()
	: _statusCode(200), _statusMessage("OK")
{
	_setDateHeader();
	_setServerHeader();
}

HTTPResponse::HTTPResponse(int statusCode)
	: _statusCode(statusCode),
	  _statusMessage(HTTPStatus::getReasonPhrase(statusCode))
{
	_setDateHeader();
	_setServerHeader();
}

HTTPResponse::~HTTPResponse()
{
}

HTTPResponse::HTTPResponse(const HTTPResponse& other)
	: _statusCode(other._statusCode),
	  _statusMessage(other._statusMessage),
	  _headers(other._headers),
	  _body(other._body)
{
}

HTTPResponse& HTTPResponse::operator=(const HTTPResponse& other)
{
	if (this != &other)
	{
		_statusCode = other._statusCode;
		_statusMessage = other._statusMessage;
		_headers = other._headers;
		_body = other._body;
	}
	return *this;
}

// Setters

void HTTPResponse::setStatusCode(int code)
{
	_statusCode = code;
	_statusMessage = HTTPStatus::getReasonPhrase(code);
}

void HTTPResponse::setHeader(const std::string& name, const std::string& value)
{
	_headers[name] = value;
}

void HTTPResponse::setBody(const std::string& body)
{
	_body = body;
	std::ostringstream oss;
	oss << _body.size();
	_headers["Content-Length"] = oss.str();
}


// Getters

int HTTPResponse::getStatusCode() const { return _statusCode; }
const std::string& HTTPResponse::getBody() const { return _body; }

// Serialization

std::string HTTPResponse::serialize() const
{
	std::ostringstream oss;

	oss << "HTTP/1.1 " << _statusCode << " " << _statusMessage << "\r\n";
	for (std::map<std::string, std::string>::const_iterator it = _headers.begin();
		 it != _headers.end(); ++it)
	{
		oss << it->first << ": " << it->second << "\r\n";
	}
	oss << "\r\n";
	if (!_body.empty())
		oss << _body;
	#ifdef DEBUG
		std::cout << oss.str() << std::endl;
	#endif
	return (oss.str());
}

// Factory methods

HTTPResponse HTTPResponse::buildErrorResponse(int code)
{
	std::string message = HTTPStatus::getReasonPhrase(code);
	std::string body = _generateErrorPage(code, message);

	HTTPResponse response(code);
	response.setHeader("Content-Type", "text/html");
	response.setBody(body);
	response.setHeader("Connection", "close");
	return response;
}

HTTPResponse HTTPResponse::buildErrorResponse(int code, const std::string& customBody)
{
	HTTPResponse response(code);
	response.setHeader("Content-Type", "text/html");
	response.setBody(customBody);
	response.setHeader("Connection", "close");
	return response;
}

HTTPResponse HTTPResponse::buildRedirectResponse(int code, const std::string& location)
{
	HTTPResponse response(code);
	response.setHeader("Location", location);
	response.setBody("");
	return response;
}

// Private helpers

void HTTPResponse::_setDateHeader()
{
	char buf[64];
	time_t now = time(NULL);
	struct tm* gmt = gmtime(&now);

	strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S GMT", gmt);
	_headers["Date"] = buf;
}

void HTTPResponse::_setServerHeader()
{
	_headers["Server"] = "webserv/1.0";
}

std::string HTTPResponse::_generateErrorPage(int code, const std::string& message)
{
	std::ostringstream oss;
	oss << "<html>\r\n"
		<< "<head><title>" << code << " " << message << "</title></head>\r\n"
		<< "<body>\r\n"
		<< "<center><h1>" << code << " " << message << "</h1></center>\r\n"
		<< "<hr><center>webserv/1.0</center>\r\n"
		<< "<hr><center>Pmorello</center>\r\n"
		<< "<hr><center>Rmanzana</center>\r\n"
		<< "<hr><center>Jaacosta</center>\r\n"
		<< "</body>\r\n"
		<< "</html>\r\n";
	return oss.str();
}