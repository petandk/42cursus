#include "../../inc/server/Client.hpp"
#include <iostream>


Client::Client(void)
    :_fd(-1),
    _lastActivity(time(NULL)),
    _responseFd(-1),
    _config(NULL),
    _listenFd(-1)
{}

Client::Client(int fd, const ServerConfig *config)
    :_fd(fd),
    _lastActivity(time(NULL)),
    _responseFd(-1),
    _config(config),
    _listenFd(-1)
{
    if (config)
        _parser.setMaxBodySize(config->getClientMaxBodySize());
}

Client::Client(const Client &other)
    :_fd(other._fd),
    _lastActivity(other._lastActivity),
    _requestBuffer(other._requestBuffer),
    _responseFd(other._responseFd),
    _config(other._config),
    _listenFd(other._listenFd),
    _parser(other._parser)

{}

Client &Client::operator=(const Client &other)
{
    if (this != &other)
    {
        this->_fd = other._fd;
        this->_lastActivity = other._lastActivity;
        this->_requestBuffer = other._requestBuffer;
        this->_responseFd = other._responseFd;
        this->_config = other._config;
        this->_parser = other._parser;
        this->_listenFd = other._listenFd;
    }
    return (*this);
}

Client::~Client(void)
{
    if (this->hasResponse())
        close(this->_responseFd);
}

void Client::updateActivity(void)
{
    this->_lastActivity = time(NULL);
}

bool Client::hasTimedOut(int timeoutLimit) const
{
    return ((time(NULL) - this->_lastActivity) > timeoutLimit);
}

void Client::appendRequest(const char *data, ssize_t size)
{
    this->_requestBuffer.append(data, size);
}

void Client::setResponseFd(int fd)
{
    this->_responseFd = fd;
}

bool Client::hasResponse(void) const
{
    return (this->_responseFd >= 0);
}

void Client::clearRequest(void)
{
    this->_requestBuffer.clear();
}

int Client::getFd(void) const
{
    return (this->_fd);
}

const std::string &Client::getRequestBuffer(void) const
{
    return (this->_requestBuffer);
}

int Client::getResponseFd(void) const
{
   return (this->_responseFd);
}

const ServerConfig *Client::getConfig(void) const
{
    return (this->_config);
}

RequestParser& Client::getParser()
{
    return (this->_parser);
}

void Client::setListenFd(int fd)
{
    this->_listenFd = fd;
}

int Client::getListenFd(void) const
{
    return this->_listenFd;
}

void Client::setConfig(const ServerConfig *config)
{
    this->_config = config;
    if (config)
        this->_parser.setMaxBodySize(config->getClientMaxBodySize());
}