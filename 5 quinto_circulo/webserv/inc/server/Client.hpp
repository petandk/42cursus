#ifndef CLIENT_HPP
#define CLIENT_HPP

# include <string>
# include <ctime>
# include <unistd.h>
# include <sys/types.h>
# include "../parser/ServerConfig.hpp"
# include "../parser/RequestParser.hpp"

class Client {
    private:
        int                 _fd;
        time_t              _lastActivity;
        std::string         _requestBuffer;
        int                 _responseFd;
        const ServerConfig *_config;
        int                 _listenFd;
        RequestParser       _parser; 

    public:
        Client(void);
        Client(int fd, const ServerConfig *config);
        Client(const Client &other);
        Client &operator=(const Client &other);
        ~Client(void);

        void                updateActivity(void);
        bool                hasTimedOut(int timeoutLimit) const;
        void                appendRequest(const char *data, ssize_t size);
        
        void                setResponseFd(int fd);
        bool                hasResponse(void) const;
        
        void                clearRequest(void);

        int                 getFd(void) const;
        RequestParser&      getParser();
        const std::string   &getRequestBuffer(void) const;
        int                 getResponseFd(void) const;
        const ServerConfig  *getConfig(void) const;

        /* support virtual-host selection */
        void                setListenFd(int fd);
        int                 getListenFd(void) const;
        void                setConfig(const ServerConfig *config);
};

#endif