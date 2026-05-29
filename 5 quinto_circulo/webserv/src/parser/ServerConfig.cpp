#include "../inc/parser/ServerConfig.hpp"

/*
    Vectors, strings and maps are initialized by default to empty.
    But std::size_t is not, so we must initialize it to avoid
    undefined behavior.
*/
ServerConfig::ServerConfig(void)
{
    this->_clientMaxBodySize = 0;
}

ServerConfig::ServerConfig(const ServerConfig &other)
{
    this->_ports = other._ports;
    this->_host = other._host;
    this->_serverNames = other._serverNames;
    this->_root = other._root;
    this->_indexFiles = other._indexFiles;
    this->_clientMaxBodySize = other._clientMaxBodySize;
    this->_errorPages = other._errorPages;
    this->_locations = other._locations;
}

ServerConfig    &ServerConfig::operator=(const ServerConfig &other)
{
    if (this != &other)
    {
        this->_ports = other._ports;
        this->_host = other._host;
        this->_serverNames = other._serverNames;
        this->_root = other._root;
        this->_indexFiles = other._indexFiles;
        this->_clientMaxBodySize = other._clientMaxBodySize;
        this->_errorPages = other._errorPages;
        this->_locations = other._locations;
    }
    return (*this);
}

ServerConfig::~ServerConfig(void)
{

}

//getters
const std::vector<int> &ServerConfig::getPorts(void) const
{
    return (this->_ports);
}

const std::string &ServerConfig::getHost(void) const
{
    return (this->_host);
}

const std::vector <std::string> &ServerConfig::getServerNames(void) const
{
    return (this->_serverNames);
}

const std::string &ServerConfig::getRoot(void) const
{
    return (this->_root);
}

const std::vector <std::string> &ServerConfig::getIndexFiles(void) const
{
    return (this->_indexFiles);
}

const std::map<int, std::string> &ServerConfig::getErrorPages(void) const
{
    return (this->_errorPages);
}

std::size_t ServerConfig::getClientMaxBodySize(void) const
{
    return (this->_clientMaxBodySize);
}

const std::vector<LocationConfig> &ServerConfig::getLocations(void) const
{
    return (this->_locations);
}

//setters
void ServerConfig::setPorts(const std::vector<int> &ports)
{
    this->_ports = ports;
}

void ServerConfig::setHost(const std::string &host)
{
    this->_host = host;
}

void ServerConfig::setServerNames(const std::vector<std::string> &names)
{
    this->_serverNames = names;
}

void ServerConfig::setRoot(const std::string &root)
{
    this->_root = root;
}

void ServerConfig::setIndexFiles(const std::vector<std::string> &indexFiles)
{
    this->_indexFiles = indexFiles;
}

void ServerConfig::setErrorPages(const std::map<int, std::string> &pages)
{
    this->_errorPages = pages;
}

void ServerConfig::setClientMaxBodySize(std::size_t maxBodySize)
{
    this->_clientMaxBodySize = maxBodySize;
}

void ServerConfig::setLocations(const std::vector <LocationConfig> &locations)
{
    this->_locations = locations;
}

//adders
void ServerConfig::addPort(int port)
{
    this->_ports.push_back(port);
}

void ServerConfig::addServerName(const std::string &name)
{
    this->_serverNames.push_back(name);
}

void ServerConfig::addIndexFile(const std::string &indexFile)
{
    this->_indexFiles.push_back(indexFile);
}

void ServerConfig::addErrorPage(int code, const std::string &path)
{
    this->_errorPages[code] = path;
}

void ServerConfig::addLocation(const LocationConfig &location)
{
    this->_locations.push_back(location);
}
