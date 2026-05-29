#include "../inc/server/Server.hpp"
#include "../inc/parser/RequestParser.hpp"
#include "../inc/response/HTTPResponse.hpp"
#include "../inc/response/ResponseBuilder.hpp"
#include "../inc/CGI/CGIHandler.hpp"

#include <iostream>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <fcntl.h> 
#include <cstring> 
#include <cctype> 
#include <poll.h> 
#include <unistd.h> 
#include <netdb.h> 
#include <sstream> 
#include <arpa/inet.h> 

// Reference to global run flag from main.cpp
extern volatile bool g_running;

void printServerInfo(std::string &host, int port, const std::vector<std::string> &names)
{

    std::cout << std::endl << "\033[96m--- [SERVER] listening on ---\033[0m" << std::endl
    << "-IP/HOST: " << host << std::endl
    << "-PORT: " << port << std::endl;
    bool validName = false;
            for(size_t n = 0; n < names.size(); n++)
            {
                if (!names[n].empty())
                {
                    if (!validName)
                    {
                        std::cout << "-SERVER NAME(S): " << std::endl;
                        validName = true;
                    }
                    std::cout << "\t" << names[n] << std::endl;
                }
            }
}

static int responseToFd(const std::string &responseStr)
{
    int pipeFds[2];
    if (pipe(pipeFds) < 0)
    {
        std::cout << "\033[1;31m[ERROR] pipe() failed.\033[0m" << std::endl;
        return (-1);
    }
 
    // Write the whole response to the write end and close it.
    // For very large responses this would block if the pipe fills,
    //  but for this project responses fit in the kernel pipe buffer (normally 64KB).
    ssize_t written = write(pipeFds[1], responseStr.c_str(), responseStr.size());
    close(pipeFds[1]);
 
    if (written < 0)
    {
        close(pipeFds[0]);
        return (-1);
    }
    return (pipeFds[0]);
}


bool Server::setupSockets(void)
{
    std::vector<std::string>    openedHosts;
    std::vector<int>            openedPorts;

    //first we go over all servers
    for (size_t i = 0; i < this->_allServers.size(); i++)
    {
        std::string host = this->_allServers[i].getHost();
        const std::vector<int> &ports = this->_allServers[i].getPorts();

        //now we have to go over all ports
        for (size_t p = 0; p < ports.size(); p++)
        {
            int port = ports[p];

            bool isOpened = false;
            for (size_t j = 0; j < openedPorts.size(); j++)
            {
                if (openedHosts[j] == host && openedPorts[j] == port)
                {
                     isOpened = true;
                    break;
                }
            }
            if (isOpened)
                continue;
            int listenFd = socket(AF_INET, SOCK_STREAM, 0);
            if (listenFd < 0)
            {
                std::cout << "\033[1;31m[ERROR] Socket creation failed.\033[0m" << std::endl;
                return (false);
            }
            
            int opt = 1;
            if (setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
            {
                #ifdef DEBUG
                    std::cout << "[DEBUG-SERVER] Socket config failed." << std::endl;
                #endif
                close(listenFd);
                return (false);
            }
            if (fcntl(listenFd, F_SETFL,O_NONBLOCK) < 0)
            {
                std::cout << "\033[1;31m[ERROR] fcntl failed to set NONBLOCK.\033[0m" << std::endl;
                close(listenFd);
                return (false);
            }
            struct addrinfo hints, *res;
            memset(&hints, 0, sizeof(hints));
            hints.ai_family = AF_INET;
            hints.ai_socktype  = SOCK_STREAM;
            hints.ai_flags = AI_PASSIVE;

            std::stringstream ss;
            ss << port;
            std::string portStr = ss.str();

            if (getaddrinfo(host.c_str(), portStr.c_str(), &hints, &res) != 0)
            {
                std::cout << "\033[1;31m[ERROR] getaddrinfo failed for host '" << host << "' and port '" << port << "'.\033[0m" << std::endl;
                close(listenFd);
                return (false);
            }

            if (bind(listenFd, res->ai_addr, res->ai_addrlen) < 0)
            {
                std::cout << "\033[1;31m[ERROR] Port " << port << " on host '" << host
                << "' is already in use or cannot be bound.\n\tMake sure no other server is running on this port and the IP exists.\033[0m" << std::endl;
                freeaddrinfo(res);
                close(listenFd);
                return (false);
            }

            freeaddrinfo(res);
                //SOMAXCONN is a macro that defines max pending connections queue for a listening socket. (usually 128 on linux)
            if (listen(listenFd, SOMAXCONN) < 0)
            {
                std::cout << "\033[1;31m[ERROR] listen() failed.\033[0m" << std::endl;
                close(listenFd);
                return (false);
            }

            struct pollfd pfd;
            pfd.fd = listenFd;
            pfd.events = POLLIN;
            pfd.revents = 0;
            this->_fds.push_back(pfd);
            this->_listenFds.push_back(listenFd);
            this->_listenFdToServerIndices[listenFd].push_back(i);

            openedHosts.push_back(host);
            openedPorts.push_back(port);

            const std::vector<std::string> &names = this->_allServers[i].getServerNames();
            printServerInfo(host, port, names);
        }

    }
    return (!this->_listenFds.empty()); 
}

bool Server::acceptNewConnection(int fd)
{

    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int clientFd = accept(fd, (struct sockaddr*)&clientAddr, &clientLen);
    const ServerConfig *config = NULL;

    if (clientFd < 0)
    {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
            return (true);
        std::cout << "\033[1;31m[ERROR]  accept() failed. \033[0m" << std::endl;
        return (false);
    }
    if (fcntl(clientFd, F_SETFL, O_NONBLOCK) < 0)
    {
        std::cout << "\033[1;31m[ERROR]  New connection fcntl() failed to set O_NONBLOCK. \033[0m" << std::endl;
        close(clientFd);
        return (false);
    }
    std::map<int, std::vector<size_t> >::const_iterator cfgIt = this->_listenFdToServerIndices.find(fd);
    if (cfgIt != this->_listenFdToServerIndices.end() &&
        !cfgIt->second.empty() &&
        cfgIt->second[0] < this->_allServers.size())
    {
        config = &this->_allServers[cfgIt->second[0]]; // default server for this listen socket
    }
    if (config)
        this->_clients[clientFd] = Client(clientFd, config);
    else
    {
        std::cout << "\033[1;31m[ERROR] No ServerConfig found for listening fd " << fd << ". Closing client.\033[0m" << std::endl;
        close(clientFd);
        return false;
    }

    struct pollfd pfd;
    pfd.fd = clientFd;
    pfd.events = POLLIN;
    pfd.revents = 0;
    this->_fds.push_back(pfd);

    /*
        OS stores IP as a huge unsigned int,
        inet_ntoa convers it to readeable format X.X.X.X
        
        Internet reverses bits to transfer data, so
        ntohs has to reverse them again to be printable
        Ex: port 80 gets stored as hex 00 50; but
        if you try to print it it will reverse them and 
        print 50 00. 
        So 80 becomes 20480.
    */
    std::cout << "\033[92m-New client-\nfd: " << clientFd << std::endl
                << "\tIP:" << inet_ntoa(clientAddr.sin_addr) << std::endl
                << "\tPORT: " << ntohs(clientAddr.sin_port) << "\033[0m" << std::endl;

    // store which listen fd accepted this client so we can lookup candidate servers later
    this->_clients[clientFd].setListenFd(fd);
    return (true);
}

/*
    I need to get the client_max_body_size from the .conf file.
    so I needed to somehow map a fd to a ServerConfig, that way
    with this->_fdToServerConfig[clientFd] = config;
    Each client knows what is its config and I can use getClientMaxBodySize();
*/
bool Server::readFromClient(int fd)
{
    char buffer[READ_BUFFER];
    std::map<int, Client>::iterator it = this->_clients.find(fd);
    if (it == this->_clients.end())
        return (false);
    Client &client = it->second;

    ssize_t bytesRead = recv(fd, buffer, sizeof(buffer) - 1, 0);

    if (bytesRead < 0)
    {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
            return (true);
        std::cout << "\033[1;31m[ERROR] recv() failed for fd: " << fd << "\033[0m" << std::endl;
        return (false);
    }

    if (bytesRead == 0)
        return (false);
    
    buffer[bytesRead] = '\0';

    client.getParser().feed(std::string(buffer, bytesRead));
    #ifdef DEBUG
        std::cout << "[DEBUG] Received " << bytesRead << " bytes from fd " << fd << std::endl;
    #endif

    if (!client.getParser().isComplete())
    {
        return (true);
    }
    const HTTPRequest& request = client.getParser().getRequest();
    if (request.getErrorCode() != 0)
    {
        std::cout << "\033[93m[INFO] Parse error " << request.getErrorCode()
                  << " for fd " << fd << "\033[0m" << std::endl;
 
        HTTPResponse errResp = HTTPResponse::buildErrorResponse(request.getErrorCode());
        std::string serialized = errResp.serialize();
 
        int responseFd = responseToFd(serialized);
        if (responseFd < 0)
            return (false);
 
        client.setResponseFd(responseFd);
        setClientEvents(fd, POLLOUT);
        return (true);
    }
    const ServerConfig *selectedConfig = client.getConfig();
    int acceptListenFd = client.getListenFd();
    std::map<int, std::vector<size_t> >::const_iterator lstIt =
        this->_listenFdToServerIndices.find(acceptListenFd);
    if (lstIt != this->_listenFdToServerIndices.end() && !lstIt->second.empty())
    {
        size_t chosen = lstIt->second[0]; // default
        std::string host = request.getHeader("host");
        if (!host.empty())
        {
            size_t colon = host.find(':');
            if (colon != std::string::npos) host = host.substr(0, colon);
            for (size_t i = 0; i < host.size(); ++i)
                host[i] = std::tolower(static_cast<unsigned char>(host[i]));
            bool matched = false;
            for (size_t ci = 0; ci < lstIt->second.size() && !matched; ++ci)
            {
                size_t sidx = lstIt->second[ci];
                if (sidx >= this->_allServers.size()) continue;
                const std::vector<std::string> &names = this->_allServers[sidx].getServerNames();
                for (size_t n = 0; n < names.size(); ++n)
                {
                    std::string nm = names[n];
                    for (size_t k = 0; k < nm.size(); ++k) nm[k] = std::tolower(static_cast<unsigned char>(nm[k]));
                    if (nm == host) { chosen = sidx; matched = true; break; }
                }
            }
        }
        selectedConfig = &this->_allServers[chosen];
    }
    client.setConfig(selectedConfig);

    HTTPResponse response;
    CGIHandler cgi(request, response, request.getBody());
    ResponseBuilder builder(request, *selectedConfig, response, cgi);
    builder.buildResponse(client);

    setClientEvents(fd, POLLOUT);
 
    // ── Keep-alive: reset the parser for the next request ───────────
    if (request.shouldKeepAlive())
        client.getParser().reset();

    return (true);
}

// fd should contain everything so just send it to client
bool Server::sendToClient(int fd)
{
    std::map<int, Client>::iterator it = this->_clients.find(fd);
    if (it == this->_clients.end())
        return (false);
    Client &client = it->second;
    int bodyFd = client.getResponseFd();
    if (bodyFd < 0)
        return (true); //nothing to send
    char buffer[READ_BUFFER];
    ssize_t bytesRead = read(bodyFd, buffer, sizeof(buffer));

    if (bytesRead < 0)
    {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
            return (true); //retry
        
        std::cout << "\033[1;31m[ERROR] read() failed on fd " 
                  << bodyFd << ": " << strerror(errno) << "\033[0m" << std::endl;
        return (false);
    }
    if (bytesRead == 0)
    {
        close(bodyFd);
        client.setResponseFd(-1);
        client.clearRequest();
        #ifdef DEBUG
            std::cout << "[DEBUG] Response fully sent to fd " << fd << std::endl;
        #endif
        //keep-alive
        setClientEvents(fd, POLLIN);
        return (true);
    }
    ssize_t totalSent = 0;
    while (totalSent < bytesRead)
    {
        ssize_t sent = send(fd, buffer+totalSent, bytesRead - totalSent, MSG_DONTWAIT);
        if (sent < 0)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                return (true);

            std::cout << "\033[1;31m[ERROR] send() failed for fd: " 
                      << fd << "\033[0m" << std::endl;
            return (false);
        }
        totalSent += sent;
    }

    #ifdef DEBUG
        std::cout << "[DEBUG] Sent " << totalSent << " bytes to fd " << fd << std::endl;
    #endif

    return (true);
}

bool Server::isListening(int fd)
{
    for (size_t i = 0; i < this->_listenFds.size(); i++)
    {
        if (fd == this->_listenFds[i])
            return (true);
    }
    return (false);
}

std::string Server::getRawRequest(int client_fd) const
{
    std::map<int, Client>::const_iterator it = this->_clients.find(client_fd);
    if (it != this->_clients.end())
        return (it->second.getRequestBuffer());
    return ("");
}

void Server::kickClient(int fd, const std::string &reason)
{
    std::map<int, Client>::iterator it = this->_clients.find(fd);
    if (it != this->_clients.end())
    {
        if (it->second.hasResponse())
            close(it->second.getResponseFd());
    }
    close(fd);
    for (size_t i = 0; i < this->_fds.size(); i++)
    {
        if (this->_fds[i].fd == fd)
        {
            this->_fds.erase(_fds.begin() + i);
            break;
        }
    }
    this->_clients.erase(fd);
    std::cout << "\033[93m[INFO] Client fd '" << fd
              << "' disconnected (" << reason << ")\033[0m" << std::endl;

    #ifdef DEBUG
        std::cout << "[DEBUG] Remaining clients: " << this->_clients.size() << std::endl;
    #endif
}

void Server::setClientEvents(int fd, short events)
{
    for (size_t i = 0; i < this->_fds.size(); i++)
    {
        if (this->_fds[i].fd == fd)
        {
            this->_fds[i].events = events;
            break;
        }
    }
}

void Server::checkTimeouts(void)
{
    for (std::map<int, Client>::iterator it = this->_clients.begin();
         it != this->_clients.end();)
    {
        if (it->second.hasTimedOut(IDLE_TIMEOUT / 1000))
        {
            int fd = it->first;
            ++it;              
            kickClient(fd, "Timeout");
        }
        else
            ++it;
    }
}

void Server::cleanup(void)
{
    for (size_t i = 0; i < this->_fds.size(); i++)
    {
        if (this->_fds[i].fd >= 0)
            close(this->_fds[i].fd);
    }
    this->_fds.clear();
    this->_listenFdToServerIndices.clear();
    #ifdef DEBUG
        std::cout << "\033[31mAll resources cleaned!\033[0m" << std::endl;
    #endif
}

Server::Server(void)
{
    #ifdef DEBUG
        std::cout << "Default server created" << std::endl;
    #endif
}

Server::Server(const ConfigParser &configs):_allServers(configs.getParsedServerConfigs())
{
    #ifdef DEBUG
        std::cout << "Server created using config file" << std::endl;
    #endif
}

Server::Server(const Server &other)
    :_allServers(other._allServers),
    _fds(other._fds),
    _listenFds(other._listenFds)
{
    #ifdef DEBUG
        std::cout << "Server created as a copy" << std::endl;
    #endif
}

Server &Server::operator=(const Server &other)
{
    if (this != &other)
    {
        _allServers = other._allServers;
        _fds = other._fds;
        _listenFds = other._listenFds;
    }
    #ifdef DEBUG
        std::cout << "Server assigned as a copy" << std::endl;
    #endif
    return (*this);
}

Server::~Server(void)
{
    cleanup();
    #ifdef DEBUG
        std::cout << "\033[1;32mServer successfully destroyed!\033[0m" << std::endl;
    #endif
}

bool Server::run(void)
{
    if (!setupSockets())
        return (false);

    bool activeServer = true;
    while (activeServer && g_running)
    {
        checkTimeouts();
        int pollRes = poll(&this->_fds[0], this->_fds.size(), POLL_TIMEOUT);
        if (pollRes < 0)
        {
            activeServer = false;
            break;
        }
        if (pollRes == 0)
            continue;
        for (int i = this->_fds.size() - 1; i >= 0 ; i--)
        {
            if (this->_fds[i].revents == 0)
                continue;
            
            int fd = _fds[i].fd;
            
            if(isListening(fd))
            {
                if (!acceptNewConnection(fd))
                    activeServer = false;
                continue;
            }
            /*
                POLLRDHUP is kind of new and linux-specific so need to be protected
                POLLIN - there's data waiting to be read.
                POLLPRI - there's urgent data waiting to be read.
                POLLOUT - we can write.
                POLLHUP - client disconnected or connection lost
                POLLERR - socket is broken
                POLLNVAL - invalid fd, probably closed but not removed from
                            _fds vector. So poll tried to check a closed fd
                POLLRDHUP - its like a nice goodbye. The client finished "talking" and left.
            */
            # ifdef POLLRDHUP
                if (_fds[i].revents & (POLLERR | POLLHUP | POLLNVAL | POLLRDHUP))
            # else
                if (_fds[i].revents & (POLLERR | POLLHUP | POLLNVAL))
            # endif
            {
                kickClient(fd, "poll_error_or_hangup");
                continue;
            }
            if (_fds[i].revents & POLLIN)
            {
                if (!readFromClient(fd))
                    kickClient(fd, "read_error_or_peer_closed");
                else
                    this->_clients[fd].updateActivity();
            }
            if (_fds[i].revents & POLLOUT)
            {
                if (!sendToClient(fd))
                {
                    kickClient(fd, "send_error");
                    continue;
                }
                else
                    this->_clients[fd].updateActivity();
            }
        }
    }
    return (activeServer);
}