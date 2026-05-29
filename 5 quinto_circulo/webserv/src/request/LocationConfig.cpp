#include "../inc/parser/LocationConfig.hpp"

/*
    Since we have a default.conf, we don't need default values here.
    Strings and vectors are initialized by default to empty,
    but bool and int are not, so we must initialize them to avoid
    undefined behavior.
 */
LocationConfig::LocationConfig(void)
{
    this->_autoindex = false;
    this->_redirectCode = 0;
}

LocationConfig::LocationConfig(const LocationConfig &other)
{
    this->_path = other._path;
    this->_root = other._root;
    this->_alias = other._alias;
    this->_allowedMethods = other._allowedMethods;
    this->_autoindex = other._autoindex;
    this->_indexFiles = other._indexFiles;
    this->_uploadPath = other._uploadPath;
    this->_cgiExtension = other._cgiExtension;
    this->_cgiPass = other._cgiPass;
    this->_redirectCode = other._redirectCode;
    this->_redirectUrl = other._redirectUrl;
    this->_tryFiles = other._tryFiles;
}

LocationConfig &LocationConfig::operator=(const LocationConfig &other)
{
    if (this != &other)
    {
        this->_path = other._path;
        this->_root = other._root;
        this->_alias = other._alias;
        this->_allowedMethods = other._allowedMethods;
        this->_autoindex = other._autoindex;
        this->_indexFiles = other._indexFiles;
        this->_uploadPath = other._uploadPath;
        this->_cgiExtension = other._cgiExtension;
        this->_cgiPass = other._cgiPass;
        this->_redirectCode = other._redirectCode;
        this->_redirectUrl = other._redirectUrl;
        this->_tryFiles = other._tryFiles;
    }
    return (*this);
}

LocationConfig::~LocationConfig(void)
{
}

//getters
const std::string &LocationConfig::getPath(void) const
{
    return(this->_path);
}

const std::string &LocationConfig::getRoot(void) const
{
    return(this->_root);
}

const std::string &LocationConfig::getAlias(void) const
{
    return(this->_alias);
}

const std::vector<std::string> &LocationConfig::getAllowedMethods(void) const
{
    return(this->_allowedMethods);
}

bool LocationConfig::getAutoindex(void) const
{
    return (this->_autoindex);
}

const std::vector<std::string> &LocationConfig::getIndexFiles(void) const
{
    return (this->_indexFiles);
}

const std::string &LocationConfig::getUploadPath(void) const
{
    return (this->_uploadPath);
}

const std::string &LocationConfig::getCgiExtension(void) const
{
    return (this->_cgiExtension);
}

const std::string &LocationConfig::getCgiPass(void) const
{
    return (this->_cgiPass);
}

int   LocationConfig::getRedirectCode(void) const
{
    return (this->_redirectCode);
}

const std::string &LocationConfig::getRedirectUrl(void) const
{
    return (this->_redirectUrl);
}

const std::vector<std::string> &LocationConfig::getTryFiles(void) const
{
    return (this->_tryFiles);
}

//setters
void LocationConfig::setPath(const std::string &path)
{
    this->_path = path;
}

void LocationConfig::setRoot(const std::string &root)
{
    this->_root = root;
}

void LocationConfig::setAlias(const std::string &alias)
{
    this->_alias = alias;
}

void LocationConfig::setAllowedMethods(const std::vector <std::string> &methods)
{
    this->_allowedMethods = methods;
}

void LocationConfig::setAutoindex(bool state)
{
    this->_autoindex = state;
}

void LocationConfig::setIndexFiles(const std::vector<std::string> &paths)
{
    this->_indexFiles = paths;
}

void LocationConfig::setUploadPath(const std::string &path)
{
    this->_uploadPath = path;
}

void LocationConfig::setCgiExtension(const std::string &extension)
{
    this->_cgiExtension = extension;
}

void LocationConfig::setCgiPass(const std::string &path)
{
    this->_cgiPass = path;
}

void LocationConfig::setRedirectCode(int code)
{
    this->_redirectCode = code;
}

void LocationConfig::setRedirectUrl(const std::string &path)
{
    this->_redirectUrl = path;
}

void LocationConfig::setTryFiles(const std::vector<std::string> &files)
{
    this->_tryFiles = files;
}

//adders
void LocationConfig::addAllowedMethod(const std::string &method)
{
    this->_allowedMethods.push_back(method);
}

void LocationConfig::addTryFile(const std::string &file)
{
    this->_tryFiles.push_back(file);
}

void LocationConfig::addIndexFile(const std::string &index)
{
    this->_indexFiles.push_back(index);
}
