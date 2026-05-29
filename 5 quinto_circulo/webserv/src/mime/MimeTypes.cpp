#include "MimeTypes.hpp"

MimeTypes::MimeTypes(){}

MimeTypes::MimeTypes(const MimeTypes& other) 
{ 
	*this = other; 
}

MimeTypes& MimeTypes::operator=(const MimeTypes& other)
{	
	if (this != &other)
	{
	
	}
	return *this; 
}

MimeTypes::~MimeTypes(){}

std::map<std::string, std::string> MimeTypes::_initMimeMap()
{
	std::map<std::string, std::string> m;

	// Text
	m[".html"] = "text/html";
	m[".htm"]  = "text/html";
	m[".php"]  = "text/html";
	m[".css"]  = "text/css";
	m[".txt"]  = "text/plain";
	m[".csv"]  = "text/csv";

	// Application
	m[".js"]   = "application/javascript";
	m[".json"] = "application/json";
	m[".xml"]  = "application/xml";
	m[".pdf"]  = "application/pdf";
	m[".zip"]  = "application/zip";
	m[".gz"]   = "application/gzip";
	m[".tar"]  = "application/x-tar";

	// Image
	m[".jpg"]  = "image/jpeg";
	m[".jpeg"] = "image/jpeg";
	m[".png"]  = "image/png";
	m[".gif"]  = "image/gif";
	m[".ico"]  = "image/x-icon";
	m[".svg"]  = "image/svg+xml";
	m[".bmp"]  = "image/bmp";
	m[".webp"] = "image/webp";

	// Audio/Video
	m[".mp3"]  = "audio/mpeg";
	m[".mp4"]  = "video/mp4";
	m[".avi"]  = "video/x-msvideo";

	// Font
	m[".woff"]  = "font/woff";
	m[".woff2"] = "font/woff2";
	m[".ttf"]   = "font/ttf";

	return m;
}

const std::map<std::string, std::string> MimeTypes::_mimeMap = MimeTypes::_initMimeMap();

std::string MimeTypes::getMimeType(const std::string& extension)
{
	std::map<std::string, std::string>::const_iterator it = _mimeMap.find(extension);
	if (it != _mimeMap.end())
		return it->second;
	return "application/octet-stream";
}

std::string MimeTypes::getExtensionFromPath(const std::string& path)
{
	std::string::size_type dotPos = path.rfind('.');
	if (dotPos == std::string::npos || dotPos == path.size() - 1)
		return "";
	// Ensure the dot is in the filename, not in a directory
	std::string::size_type slashPos = path.rfind('/');
	if (slashPos != std::string::npos && dotPos < slashPos)
		return "";
	return path.substr(dotPos);
}
