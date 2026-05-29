#ifndef WEBSRV_HPP
#define WEBSRV_HPP

#include <string>

class WebSrv {
    public:
        WebSrv(void);
        ~WebSrv(void);
        WebSrv(const WebSrv &other);
        WebSrv &operator=(const WebSrv &other);
};

#endif