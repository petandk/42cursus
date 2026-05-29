#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <string>
#include <vector>
#include <map>
#include <stdint.h>

class HTTPRequest
{
	private:
			std::string							_method;
			std::string							_uri;
			std::string							_path;
			std::string							_queryString;
			std::string							_httpVersion;
			std::map<std::string, std::string>	_headers;
			//a uint vect
			//std::string							_body;
			std::vector<uint8_t>				_body; // <-- Corregido a vector
			int									_errorCode;
			bool								_isComplete;

	public:
			HTTPRequest();
			~HTTPRequest();
			HTTPRequest(const HTTPRequest& other);
			HTTPRequest& operator=(const HTTPRequest& other);

			// Getters
			const std::string							&getMethod() const;
			const std::string							&getUri() const;
			const std::string							&getPath() const;
			const std::string							&getQueryString() const;
			const std::string							&getHttpVersion() const;
			const std::map<std::string, std::string>	&getHeaders() const;
			const std::string							&getHeader(std::string name) const;
			//const std::string							&getBody() const;
			const std::vector<uint8_t>					&getBody() const;
			int											getErrorCode() const;
			bool										getIsComplete() const;

			// Setters
			void	setMethod(const std::string& method);
			void	setUri(const std::string& uri);
			void	setPath(const std::string& path);
			void	setQueryString(const std::string& queryString);
			void	setHttpVersion(const std::string& version);
			void	setHeader(std::string name, const std::string& value);
			//void	setBody(std::string& body);
			void	setBody(const std::vector<uint8_t>& body);
			void	appendBody(const std::string& data);
			void	setErrorCode(int code);
			void	setIsComplete(bool complete);

			// Utils
			bool	hasHeader(const std::string& name) const;
			bool	shouldKeepAlive() const;
			void	clear();


};

#endif

