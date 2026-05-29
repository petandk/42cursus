#ifndef HTTPSTATUS_HPP
# define HTTPSTATUS_HPP

# include <string>
# include <map>

class HTTPStatus
{
public:
	static std::string getReasonPhrase(int code);
	static bool        isValidCode(int code);
	
	HTTPStatus();
	~HTTPStatus();
	HTTPStatus(const HTTPStatus& other);
	HTTPStatus& operator=(const HTTPStatus& other);

	static std::map<int, std::string>	_initStatusMap();
	static const std::map<int, std::string>	_statusMap;
};

#endif
