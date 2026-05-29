#include "HTTPRequest.hpp"
#include <cctype>

HTTPRequest::HTTPRequest() : _errorCode(0), _isComplete(false) 
{

}

HTTPRequest::~HTTPRequest() 
{

}

HTTPRequest::HTTPRequest(const HTTPRequest& other)
	: _method(other._method), _uri(other._uri), _path(other._path),
	  _queryString(other._queryString),  _httpVersion(other._httpVersion),
	  _headers(other._headers), _body(other._body), _errorCode(other._errorCode),
	  _isComplete(other._isComplete) 
{

}

HTTPRequest& HTTPRequest::operator=(const HTTPRequest& other)
{
	if (this != &other)
	{
		_method = other._method;
		_uri = other._uri;
		_path = other._path;
		_queryString = other._queryString;
		_httpVersion = other._httpVersion;
		_headers = other._headers;
		_body = other._body;
		_errorCode = other._errorCode;
		_isComplete = other._isComplete;
	}
	return *this;
}

// Getters
const std::string& HTTPRequest::getMethod() const 
{ 
	return (this->_method); 
}

const std::string& HTTPRequest::getUri() const 
{ 
	return (this->_uri); 
}

const std::string& HTTPRequest::getPath() const 
{ 
	return (this->_path); 
}

const std::string& HTTPRequest::getQueryString() const 
{ 
	return (this->_queryString); 
}

const std::string& HTTPRequest::getHttpVersion() const 
{ 
	return (this->_httpVersion); 
}

const std::map<std::string, std::string>& HTTPRequest::getHeaders() const 
{ 
	return (this->_headers); 
}

const std::vector<uint8_t>	&HTTPRequest::getBody() const 
{ 
	return (this->_body); 
}

int HTTPRequest::getErrorCode() const 
{ 
	return (this->_errorCode); 
}

bool HTTPRequest::getIsComplete() const 
{ 
	return (this->_isComplete); 
}

const std::string &HTTPRequest::getHeader(std::string name) const
{
	/*
	for (size_t i = 0; i < name.size();i++)
	{
		name[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(name[i])));
	}
	std::map<std::string, std::string>::const_iterator it = _headers.find(name);
	if (it != _headers.end())
		return it->second;
	return "";*/
	for (size_t i = 0; i < name.size(); i++)
	{
		name[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(name[i])));
	}
	std::map<std::string, std::string>::const_iterator it = _headers.find(name);
	if (it != _headers.end())
		return it->second;
	
	// Solución al temporal: creamos un string vacío estático que viva en memoria
	static const std::string empty = "";
	return empty;
}

// Setters
void HTTPRequest::setMethod(const std::string& method) 
{ 
	this->_method = method; 
}

void HTTPRequest::setUri(const std::string& uri) 
{ 
	this->_uri = uri; 
}

void HTTPRequest::setPath(const std::string& path) 
{ 
	this->_path = path; 
}

void HTTPRequest::setQueryString(const std::string& queryString) 
{ 
	this->_queryString = queryString; 
}

void HTTPRequest::setHttpVersion(const std::string& version) 
{ 
	this->_httpVersion = version; 
}

//void HTTPRequest::setBody(std::vector<uint8_t> body) 
void HTTPRequest::setBody(const std::vector<uint8_t>& body)
{ 
	this->_body = body; 
}

void HTTPRequest::setErrorCode(int code) 
{ 
	this->_errorCode = code; 
}

void HTTPRequest::setIsComplete(bool complete) 
{ 
	this->_isComplete = complete; 
}

void HTTPRequest::setHeader(std::string name, const std::string& value)
{
	
	for (size_t i = 0; i < name.size();i++)
	{
		name[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(name[i])));
	}
	_headers[name] = value;
}

void HTTPRequest::appendBody(const std::string& data)
{
	this->_body.insert(_body.end(), data.begin(), data.end());
}

// Utils
bool HTTPRequest::hasHeader(const std::string& name) const
{
	/*std::map<std::string, std::string>::const_iterator it = _headers.begin(); it != _headers.end(); it++;
	if (_headers.find(name) != _headers.end())
		return (true);
	else
		return (false);*/
	return (_headers.find(name) != _headers.end());
}

bool HTTPRequest::shouldKeepAlive() const
{
	std::string connection = getHeader("connection");
	for (size_t i = 0; i < connection.size(); ++i)
		connection[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(connection[i])));
	if (_httpVersion == "HTTP/1.1")
	{
		if (connection != "close")
			return (true);
		else
			return (false);
	}
	if (connection == "keep-alive")
		return (true);
	return (false);
}

void HTTPRequest::clear()
{
	this->_method.clear();
	this->_uri.clear();
	this->_path.clear();
	this->_queryString.clear();
	this->_httpVersion.clear();
	this->_headers.clear();
	this->_body.clear();
	this->_errorCode = 0;
	this->_isComplete = false;
}
