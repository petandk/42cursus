#ifndef SERVERCONFIG_HPP
# define SERVERCONFIG_HPP

# include <string>
# include <vector>
# include <map>
# include <cstddef>
# include "LocationConfig.hpp"

class ServerConfig{
    private:
        
        std::vector<int> _ports;
        std::string _host;
        std::vector<std::string> _serverNames;
        std::string _root;
        std::vector<std::string> _indexFiles;
        std::size_t _clientMaxBodySize;
        std::map<int, std::string> _errorPages;
        std::vector<LocationConfig> _locations;

    public:
        ServerConfig(void);
        ServerConfig(const ServerConfig &other);
        ServerConfig &operator=(const ServerConfig &other);
        ~ServerConfig(void);

        //getters
        const std::vector<int> &getPorts(void) const;
        const std::string &getHost(void) const;
        const std::vector <std::string> &getServerNames(void) const;
        const std::string &getRoot(void) const;
        const std::vector <std::string> &getIndexFiles(void) const;
        std::size_t getClientMaxBodySize(void) const;
        const std::map<int, std::string> &getErrorPages(void) const;
        const std::vector<LocationConfig> &getLocations(void) const;

        //setters
        void setPorts(const std::vector<int> &ports);
        void setHost(const std::string &host);
        void setServerNames(const std::vector<std::string> &names);
        void setRoot(const std::string &root);
        void setIndexFiles(const std::vector<std::string> &indexFiles);
        void setClientMaxBodySize(std::size_t maxBodySize);
        void setErrorPages(const std::map<int, std::string> &pages);
        void setLocations(const std::vector <LocationConfig> &locations);

        //adders
        void addPort(int port);
        void addServerName(const std::string &name);
        void addIndexFile(const std::string &indexFile);
        void addErrorPage(int code,const std::string &path);
        void addLocation(const LocationConfig &location);
};

#endif
