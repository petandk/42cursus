#ifndef CONFIGPARSER_HPP
# define CONFIGPARSER_HPP

#include <string>
#include <vector>
#include <exception>
#include <fstream>

#include "ServerConfig.hpp"
#include "LocationConfig.hpp"

class ConfigParser{
    private:
        std::vector<ServerConfig>   _parsedServerConfigs;
        std::string                 _fileBuffer;
        std::vector<std::string>    _bufferTokens;
        std::size_t                 _currentToken;

    public:
        ConfigParser(void);
        ConfigParser(const ConfigParser &other);
        ConfigParser &operator=(const ConfigParser &other);
        ~ConfigParser(void);

        bool parseConfigFile(void);
        bool parseConfigFile(const std::string &configFile);

        bool fillBuffer(std::ifstream &file);
        bool tokenizeBuffer(void);

        bool hasToken(void) const;
        const std::string &getToken(void) const;
        bool consumeToken(const std::string &token);
        
        bool parseTokens(void);

        //server parsing:
        bool parseServerBlock(ServerConfig &server);
        bool parseListen(ServerConfig &server);
        bool parseHost(ServerConfig &server);
        bool parseServerName(ServerConfig &server);
        bool parseMaxBodySize(ServerConfig &server);
        bool parseServerRoot(ServerConfig &server);
        bool parseServerIndex(ServerConfig &server);
        bool parseErrorPage(ServerConfig &server);
        
        //location parsing:
        bool parseLocationBlock(ServerConfig &server);
        bool parseLocationRoot(LocationConfig &location);
        bool parseLocationIndex(LocationConfig &location);
        bool parseAllowedMethods(LocationConfig &location);
        bool parseUploadPath(LocationConfig &location);
        bool parseAutoindex(LocationConfig &location);
        bool parseCGIExtension(LocationConfig &location);
        bool parseCGIpass(LocationConfig &location);
        bool parseLocation(LocationConfig &location);
        bool parseReturn(LocationConfig &location);
        bool parseLocationMaxBodySize(LocationConfig &location);
        
        //const std::string   &getFileBuffer(void);
        const std::vector<ServerConfig> &getParsedServerConfigs(void) const;

        //exceptions
        class ConfFileException: public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class ConfSyntaxException: public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class ConfValueException: public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class ConfDirectiveException: public std::exception{
            public:
                virtual const char *what() const throw();
        };

        template <typename T>
        bool parseNumbers(ServerConfig &server,
            const std::string &token,
            T min,
            T max,
            void (ServerConfig::*addFunc)(T));
        
        template <typename Config, typename Setter>
        bool parseString(Config &config, 
            const std::string &token, 
            const std::string &accepted, 
            Setter setter);
};

#include "ConfigParser.tpp"

#endif
