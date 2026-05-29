
#ifndef CONFIGPARSER_TPP
#define CONFIGPARSER_TPP

#include <sstream>
#include <climits>
#include "../utils/Utils.hpp"
#include "ConfigParser.hpp"
#include <iostream>

template <typename T>
bool ConfigParser::parseNumbers(ServerConfig &server,
    const std::string &token,
    T min,
    T max,
    void (ServerConfig::*addFunc)(T))
{
    if (!consumeToken(token) || !hasToken())
        return false;
    bool found = false;
    while (hasToken() && getToken() != ";") {
        std::string value = getToken();
        if (!isAllDigits(value))
            return false;
        std::stringstream ss(value);
        T num;
        if (!(ss >> num) || num < min || num > max)
            return false;
        if (value.length() != digitCounter(num))
            return false;
        (server.*addFunc)(num);
        found = true;
        if (!consumeToken(value))
            return false;
    }
    if (!found || !consumeToken(";"))
        return false;
    return true;
}

template <typename Config, typename Setter>
bool ConfigParser::parseString(Config &config, 
    const std::string &token, const std::string &accepted,
    Setter setter)
{
    if (!consumeToken(token) || !hasToken())
        return (false);
    bool found = false;
    while (hasToken() && getToken() != ";")
    {
        std::string value = getToken();
        if(!::isAllowedChars(value, accepted))
            return (false);
        (config.*setter)(value);
        found = true;
        if(!consumeToken(value))
            return (false);
    }
    if (!found || !consumeToken(";"))
        return (false);
    return (true);
}

#endif
