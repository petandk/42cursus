#include "HTTPStatus.hpp"

std::map<int, std::string> HTTPStatus::_initStatusMap()
{
	std::map<int, std::string> m;

	// 2xx Success
	m[200] = "OK";
	m[201] = "Created";
	m[204] = "No Content";

	// 3xx Redirection
	m[301] = "Moved Permanently";
	m[302] = "Found";
	m[303] = "See Other";
	m[307] = "Temporary Redirect";
	m[308] = "Permanent Redirect";

	// 4xx Client Error
	m[400] = "Bad Request";
	m[403] = "Forbidden";
	m[404] = "Not Found";
	m[405] = "Method Not Allowed";
	m[408] = "Request Timeout";
	m[411] = "Length Required";
	m[413] = "Content Too Large";
	m[414] = "URI Too Long";
	m[415] = "Unsupported Media Type";
	m[431] = "Request Header Fields Too Large";

	// 5xx Server Error
	m[500] = "Internal Server Error";
	m[501] = "Not Implemented";
	m[502] = "Bad Gateway";
	m[504] = "Gateway Timeout";
	m[505] = "HTTP Version Not Supported";

	return m;
}

const std::map<int, std::string> HTTPStatus::_statusMap = HTTPStatus::_initStatusMap();

std::string HTTPStatus::getReasonPhrase(int code)
{
	std::map<int, std::string>::const_iterator it = _statusMap.find(code);
	if (it != _statusMap.end())
		return it->second;
	return "Unknown";
}

bool HTTPStatus::isValidCode(int code)
{
	return _statusMap.find(code) != _statusMap.end();
}
