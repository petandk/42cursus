#include "../inc/parser/ConfigParser.hpp"
#include "../inc/utils/Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdio>

ConfigParser::ConfigParser(void)
{
}

ConfigParser::ConfigParser(const ConfigParser &other)
{
    this->_parsedServerConfigs = other._parsedServerConfigs;
    this->_fileBuffer = other._fileBuffer;
}

ConfigParser &ConfigParser::operator=(const ConfigParser &other)
{
    if (this != &other)
    {
        this->_parsedServerConfigs = other._parsedServerConfigs;
        this->_fileBuffer = other._fileBuffer;
    }
    return (*this);
}

ConfigParser::~ConfigParser(void)
{
}

bool ConfigParser::parseConfigFile(void)
{
    #ifdef DEBUG
        std::cout << "\033[34mNo config file specified, using default configuration.\033[0m" << std::endl;
    #endif
    return (parseConfigFile("Default.conf"));
}

/*
    Main Parsing Function
 */
bool ConfigParser::parseConfigFile(const std::string &configFile)
{
    try
    {
        //std::string fullPath = "conf/" + configFile;
        std::string fullPath;
        if (configFile.find('/') != std::string::npos)
            fullPath = configFile;
        else
            fullPath = "conf/" + configFile;
        std::ifstream file(fullPath.c_str());

        if (!file.is_open())
            throw ConfFileException();
        if(!this->fillBuffer(file))
            throw ConfFileException();
        if (this->_fileBuffer.empty())
            throw ConfFileException();
        file.close();

        if (!this->tokenizeBuffer()) {
            #ifdef DEBUG
                        std::cout << "[DEBUG] Tokenization failed." << std::endl;
            #endif
            throw ConfSyntaxException();
        }
            #ifdef DEBUG
                std::cout << "\033[35m[DEBUG] Tokens after tokenization:\033[0m" << std::endl;
                for (size_t i = 0; i < this->_bufferTokens.size(); ++i) {
                    std::cout << "  [" << i << "]: '" << this->_bufferTokens[i] << "'" << std::endl;
                }
            #endif
        if (!this->parseTokens()) {
            #ifdef DEBUG
                        std::cout << "[DEBUG] Parsing tokens failed." << std::endl;
            #endif
            throw ConfSyntaxException();
        }
        return (true);
    }
    catch (const std::exception &e)
    {
        std::cerr <<e.what() << std::endl;
        return (false);
    }
}

bool ConfigParser::fillBuffer(std::ifstream &file)
{
    std::string line;
    this->_fileBuffer.clear();
        while (std::getline(file, line)) {
            ::RemoveComments(line);
            ::trimWhitepaces(line);
            if (!line.empty())
                this->_fileBuffer += line + "\n";
        }
    if (file.bad()) return (false);
    return (true);
}

bool ConfigParser::tokenizeBuffer(void)
{
    std::string current;
    char c;

    this->_bufferTokens.clear();
    for ( size_t i = 0; i < this->_fileBuffer.size(); i++)
    {
        c = this->_fileBuffer[i];
        if(c == ' ' || c =='\n'  || c =='\t' || c =='\r')
        {
            if (!current.empty())
                this->_bufferTokens.push_back(current);
            current.clear();
            continue;
        }
        else if(c == '{' || c == '}' || c == ';')
        {
            if (!current.empty())
                this->_bufferTokens.push_back(current);
            current.clear();
            this->_bufferTokens.push_back(std::string(1, c));
            continue;
        }

        else
            current.push_back(c);
    }
    if (!current.empty())
        this->_bufferTokens.push_back(current);

    if (this->_bufferTokens.empty()) return (false);
    return (true);
}

bool ConfigParser::parseTokens(void)
{
    this->_currentToken = 0;
    this->_parsedServerConfigs.clear();
    
    while (this->_currentToken < this->_bufferTokens.size())
    {
        ServerConfig server;
        #ifdef DEBUG
                std::cout << "[DEBUG] Calling parseServerBlock. Current token: '" << getToken() << "'" << std::endl;
        #endif
        if (!this->parseServerBlock(server)) {
            #ifdef DEBUG
                        std::cout << "[DEBUG] Error in parseServerBlock. Token: '" << getToken() << "'" << std::endl;
            #endif
            return (false);
        }
        #ifdef DEBUG
                std::cout << "[DEBUG] Server added to _parsedServerConfigs" << std::endl;
        #endif
        this->_parsedServerConfigs.push_back(server);
    }
    #ifdef DEBUG
        std::cout << "[DEBUG] Exiting parseTokens" << std::endl;
    #endif
    return (true);
}

bool ConfigParser::hasToken(void) const
{
    return(this->_currentToken < this->_bufferTokens.size());
}

const std::string &ConfigParser::getToken(void) const
{
    return (this->_bufferTokens[this->_currentToken]);
}

bool ConfigParser::consumeToken(const std::string &token)
{
        if (!hasToken() || getToken() != token) return (false);
    this->_currentToken++;
    return (true);
}

bool ConfigParser::parseServerBlock(ServerConfig &server)
{
#ifdef DEBUG
    std::cout << "[DEBUG] Entering parseServerBlock" << std::endl;
#endif
    const std::string serverDirectives[] ={
        "listen",
        "host",
        "server_name",
        "client_max_body_size",
        "root",
        "index",
        "error_page",
        "location"
    };
    size_t i;
    if (!consumeToken("server")) {
        #ifdef DEBUG
                std::cout << "[DEBUG] Failed to consume 'server' token." << std::endl;
        #endif
        return (false);
    }
    if (!consumeToken("{")) {
        #ifdef DEBUG
                std::cout << "[DEBUG] Failed to consume '{' after server." << std::endl;
        #endif
        return (false);
    }
    while (hasToken() && getToken() != "}")
    {
        i = 0;
        while (i < 8 && getToken() != serverDirectives[i])
            i++;
        switch(i)
        {
            case 0: if (!parseListen(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseListen. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false); 
                } 
                break;
            case 1: if (!parseHost(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseHost. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false); 
                } 
                break;
            case 2: if (!parseServerName(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseServerName. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false); 
                }
                break;
            case 3: if (!parseMaxBodySize(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseMaxBodySize. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 4: if (!parseServerRoot(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseServerRoot. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 5: if (!parseServerIndex(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseServerIndex. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 6: if (!parseErrorPage(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseErrorPage. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 7: if (!parseLocationBlock(server)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseLocationBlock. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            default: 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Unknown directive in server block. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
        }
    }
    // default values here:
    if (server.getHost().empty())
        server.setHost("0.0.0.0");
    if (server.getPorts().empty())
    {
        server.addPort(80);
        server.addPort(8080);
    }
    if (server.getRoot().empty())
        server.setRoot("./www");
    if (server.getIndexFiles().empty())
        server.addIndexFile("index.html");
    if (server.getClientMaxBodySize() == 0)
        server.setClientMaxBodySize(1048576); //1MB
    if (server.getServerNames().empty())
        server.addServerName("localhost");
    
    #ifdef DEBUG
        std::cout << "[DEBUG] Finished parsing server block. Checking for closing '}'..." << std::endl;
    #endif
    if(!consumeToken("}")) {
        #ifdef DEBUG
                std::cout << "[DEBUG] Failed to consume closing '}' for server block." << std::endl;
        #endif
        return (false);
    }
    #ifdef DEBUG
        std::cout << "[DEBUG] Exiting parseServerBlock" << std::endl;
    #endif
    return (true);
}

bool ConfigParser::parseListen(ServerConfig &server)
{
    return parseNumbers(server, "listen", 1, 65535, &ServerConfig::addPort);
}

/*
 * %d.%d.%d.%d matches the 4 numbers.
 * %c (garbage) catches any extra characters at the end.
 * Returns 4 only if there is no extra junk after the IP.
 */

bool ConfigParser::parseHost(ServerConfig &server)
{
    if(!consumeToken("host") || !hasToken()) return (false);
    std::string host = getToken();
    int a,b,c,d;
    char garbage;
    if (std::sscanf(host.c_str(), "%d.%d.%d.%d%c", &a, &b, &c, &d, &garbage) != 4)
        return (false);
    if (a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255)
        return (false);
    server.setHost(host);
    if (!consumeToken(host) || !consumeToken(";"))
        return (false);
    return (true);
}

bool ConfigParser::parseServerName(ServerConfig &server)
{
    return (parseString(server, "server_name", "*.-", &ServerConfig::addServerName));
}

bool ConfigParser::parseMaxBodySize(ServerConfig &server)
{
    return (parseNumbers<std::size_t>(server, "client_max_body_size", 0, ULONG_MAX, &ServerConfig::setClientMaxBodySize));
}

bool ConfigParser::parseServerRoot(ServerConfig &server)
{
    return (parseString(server, "root", "/._-", &ServerConfig::setRoot));
}

bool ConfigParser::parseServerIndex(ServerConfig &server)
{
    return (parseString(server, "index", "/._-", &ServerConfig::addIndexFile));
}

bool ConfigParser::parseErrorPage(ServerConfig &server)
{
    if (!consumeToken("error_page") || !hasToken())
        return (false);
    bool foundError = false;
    while (hasToken() && getToken() != ";")
    {
        std::string errorN = getToken();

        int code;
        if (!isAllDigits(errorN)) return false;
        std::stringstream ss(errorN);
        if (!(ss >> code) || code < 100 || code > 599)
            return false;
        if(!consumeToken(errorN)) return (false);
        std::string error = getToken();
        if(!::isAllowedChars(error, "/._-")) return (false);
        server.addErrorPage(code, error);
        foundError = true;
        if(!consumeToken(error)) return (false);
    }
    if (!foundError || !consumeToken(";")) return (false);
    return (true);
}

bool ConfigParser::parseLocationBlock(ServerConfig &server)
{
#ifdef DEBUG
    std::cout << "[DEBUG] Entering parseLocationBlock. Current token: '" << getToken() << "'" << std::endl;
#endif
    const std::string locationDirectives[] = {
        "root",
        "index",
        "allowed_methods",
        "upload_path",
        "autoindex",
        "cgi_extension",
        "cgi_pass",
        "client_max_body_size",
        "location",
        "return"
    };
    size_t i;
    LocationConfig location;
    if (!consumeToken("location") || ! hasToken()) {
        #ifdef DEBUG
                std::cout << "[DEBUG] Failed to consume 'location' token or missing token." << std::endl;
        #endif
        return (false);
    }
    std::string path = getToken();
    if (!::isAllowedChars(path, "/.*_-~%@+")){
        #ifdef DEBUG
            std::cout << "[DEBUG] Invalid character in location path: '" << path << "'" << std::endl;
        #endif
        return (false);
    }
    location.setPath(path);
    if (!consumeToken(path)) {
        #ifdef DEBUG
                std::cout << "[DEBUG] Failed to consume location path token: '" << path << "'" << std::endl;
        #endif
        return (false);
    }
    if (!consumeToken("{")) {
        #ifdef DEBUG
                std::cout << "[DEBUG] Failed to consume '{' after location path." << std::endl;
        #endif
        return(false);
    }
    while (hasToken() && getToken() != "}")
    {
        i = 0;
        while (i < 10 && getToken() != locationDirectives[i])
            i++;
        switch(i)
        {
            case 0: if (!parseLocationRoot(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseLocationRoot. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 1: if (!parseLocationIndex(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseLocationIndex. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 2: if (!parseAllowedMethods(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseAllowedMethods. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 3: if (!parseUploadPath(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseUploadPath. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 4: if (!parseAutoindex(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseAutoindex. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 5: if (!parseCGIExtension(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseCGIExtension. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 6: if (!parseCGIpass(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseCGIpass. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 7: if(!parseLocationMaxBodySize(location)){
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in locationMaxBodySize. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 8: if (!parseLocation(location)) { 
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseLocation (nested). Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            case 9: if(!parseReturn(location)){
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Error in parseReturn. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
                }
                break;
            default:
                    #ifdef DEBUG
                                    std::cout << "[DEBUG] Unknown directive in location block. Token: '" << getToken() << "'" << std::endl;
                    #endif
                    return (false);
        }
    }
    //default values here:
    if (location.getAllowedMethods().empty())
        location.addAllowedMethod("GET");
    if (location.getIndexFiles().empty())
        location.addIndexFile(server.getIndexFiles().empty() ? "index.html" : server.getIndexFiles()[0]);
    if (location.getRoot().empty())
        location.setRoot(server.getRoot());
    if (location.getLocationMaxBodySize() == 0)
        location.setLocationMaxBodySize(server.getClientMaxBodySize());
    

    server.addLocation(location);
    #ifdef DEBUG
        std::cout << "[DEBUG] Location added to server" << std::endl;
    #endif
    if (!consumeToken("}")) {
        #ifdef DEBUG
                std::cout << "[DEBUG] Failed to consume closing '}' for location block." << std::endl;
        #endif
        return (false);
    }
    #ifdef DEBUG
        std::cout << "[DEBUG] Exiting parseLocationBlock" << std::endl;
    #endif
    return (true);
}

bool ConfigParser::parseLocationRoot(LocationConfig &location)
{
    if (!parseString(location, "root", "/._-%", &LocationConfig::setRoot))
        return false;

    std::string encodedRoot = location.getRoot();
    size_t pos;
    
    while ((pos = encodedRoot.find("%20")) != std::string::npos) {
        encodedRoot.replace(pos, 3, " ");
    }

    location.setRoot(encodedRoot);
    
    return (true);
}

bool ConfigParser::parseLocationIndex(LocationConfig &location)
{
    return (parseString(location, "index", "/._-", &LocationConfig::addIndexFile));
}

bool ConfigParser::parseAllowedMethods(LocationConfig &location)
{
    if (!consumeToken("allowed_methods") || !hasToken())
        return (false);
    bool found = false;
    while (hasToken() && getToken() != ";")
    {
        std::string method = getToken();
        if (method != "GET" && method != "POST" && method != "DELETE")
            return (false);
        location.addAllowedMethod(method);
        found = true;
        if (!consumeToken(method))
            return(false);
    }
    if(!found || !consumeToken(";"))
        return (false);
    return (true);
}

bool ConfigParser::parseUploadPath(LocationConfig &location)
{
    return (parseString(location, "upload_path", "/._-%", &LocationConfig::setUploadPath));
}

bool ConfigParser::parseAutoindex(LocationConfig &location)
{
    if (!consumeToken("autoindex") || !hasToken())
        return (false);
    std::string flag = getToken();
    if (flag != "on" && flag != "off")
        return (false);
    location.setAutoindex(flag == "on");
    if (!consumeToken(flag) || !consumeToken(";"))
        return (false);
    return (true);
}

bool ConfigParser::parseCGIExtension(LocationConfig &location)
{
    return (parseString(location, "cgi_extension", ".", &LocationConfig::setCgiExtension));
}

bool ConfigParser::parseCGIpass(LocationConfig &location)
{
    return (parseString(location, "cgi_pass", "/._-%", &LocationConfig::setCgiPass));
}

bool ConfigParser::parseLocation(LocationConfig &location)
{
    (void)location;

    if (!consumeToken("location") || !hasToken())
        return (false);
    std::cout << "\033[31m⚠️  Anidated locations not allowed ⚠️" << std::endl;
    std::cout << "\t" << getToken();
    if (!consumeToken(getToken()))
        return (false);
    if (!hasToken() || !consumeToken("{"))
        return (false);
    int level = 1;
    while (hasToken() && level > 0)
    {
        if (getToken() == "{") ++level;
        else if (getToken() == "}") --level;
        if (!consumeToken(getToken())) return (false);
    }
    std::cout << " will be ignored!\033[0m" << std::endl;
    return (true);
}

/*
    I cannot use parseNumbers because we have 2 items to store but
    parseNumbers only wants 1. Also parseNumbers is only for ";" ended ones.
*/
bool ConfigParser::parseReturn(LocationConfig &location)
{
    if (!consumeToken("return") || !hasToken())
        return (false);
    std::string codeNum = getToken();
    int code;
    if (!isAllDigits(codeNum)) return false;
    std::stringstream ss(codeNum);
    if (!(ss >> code) || code < 100 || code > 599)
    return false;
    if(!consumeToken(codeNum)) return (false);
    std::string url;
    if (hasToken() && getToken() != ";"){
        url = getToken();
        bool isAbsolute = (url.compare(0, 7, "http://") == 0
                        || url.compare(0, 8, "https://") == 0);
        bool isRelative = (!url.empty() && url[0] == '/');
        if (!isAbsolute && !isRelative) return (false);
        if(!consumeToken(url)) return (false);
    }
    if (!consumeToken(";")) return (false);
    location.setRedirectCode(code);
    location.setRedirectUrl(url);
    return (true);
}

bool ConfigParser::parseLocationMaxBodySize(LocationConfig &location)
{
    if (!consumeToken("client_max_body_size") || !hasToken())
        return (false);
    std::string value = getToken();
    if (!isAllDigits(value)) return (false);
    std::stringstream ss(value);
    std::size_t num;
    if (!(ss >> num)) return (false);
    if (!consumeToken(value) || !consumeToken(";"))
        return (false);
    location.setLocationMaxBodySize(num);
    return (true);
}

const std::vector<ServerConfig> &ConfigParser::getParsedServerConfigs(void) const
{
    return this->_parsedServerConfigs;
}

//exceptions
const char *ConfigParser::ConfFileException::what() const throw()
{
    return("Error: Cannot open/read the configuration file or file is empty.");
}

const char *ConfigParser::ConfSyntaxException::what() const throw()
{
    return("Error: Invalid syntax in configuration file.");
}

const char *ConfigParser::ConfValueException::what() const throw()
{
    return("Error: Invalid value for directive in configuration file.");
}

const char *ConfigParser::ConfDirectiveException::what() const throw()
{
    return("Error: Missing required directive in configuration file.");
}
