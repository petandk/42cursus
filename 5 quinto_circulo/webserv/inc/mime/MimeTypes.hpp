#ifndef MIMETYPES_HPP
# define MIMETYPES_HPP

# include <string>
# include <map>

class MimeTypes
{
public:
	static std::string	getMimeType(const std::string& extension);
	static std::string	getExtensionFromPath(const std::string& path);

	MimeTypes();
	~MimeTypes();
	MimeTypes(const MimeTypes& other);
	MimeTypes& operator=(const MimeTypes& other);

private:
	

	static std::map<std::string, std::string>	_initMimeMap();
	static const std::map<std::string, std::string>	_mimeMap;
};

#endif
