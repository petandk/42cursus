#ifndef LOCATIONCONFIG_HPP
# define LOCATIONCONFIG_HPP

#include <string>
#include <vector>

class LocationConfig {
    private:
        std::string _path;
        std::string _root;
        std::string _alias;
        std::vector<std::string> _allowedMethods;
        bool _autoindex;
        std::vector<std::string> _indexFiles;
        std::string _uploadPath;
        std::string _cgiExtension;
        std::string _cgiPass;
        int _redirectCode;
        std::string _redirectUrl;
        std::vector<std::string> _tryFiles;
        std::size_t _locationMaxBodySize;


    public:
        LocationConfig(void);
        LocationConfig(const LocationConfig &other);
        LocationConfig &operator=(const LocationConfig &other);
        ~LocationConfig(void);

        //getters
        const std::string &getPath(void) const;
        const std::string &getRoot(void) const;
        const std::string &getAlias(void) const;
        const std::vector<std::string> &getAllowedMethods(void) const;
        bool getAutoindex(void) const;
        const std::vector<std::string> &getIndexFiles(void) const;
        const std::string &getUploadPath(void) const;
        const std::string &getCgiExtension(void) const;
        const std::string &getCgiPass(void) const;
        int getRedirectCode(void) const;
        const std::string &getRedirectUrl(void) const;
        const std::vector<std::string> &getTryFiles(void) const;
        size_t getLocationMaxBodySize(void) const;

        //setters
        void setPath(const std::string &path);
        void setRoot(const std::string &root);
        void setAlias(const std::string &alias);
        void setAllowedMethods(const std::vector <std::string> &methods);
        void setAutoindex(bool state);
        void setIndexFiles(const std::vector<std::string> &paths);
        void setUploadPath(const std::string &path);
        void setCgiExtension(const std::string &extension);
        void setCgiPass(const std::string &path);
        void setRedirectCode(int code);
        void setRedirectUrl(const std::string &path);
        void setTryFiles(const std::vector<std::string> &files);
        void setLocationMaxBodySize(size_t maxBodySize);

        //adders
        void addAllowedMethod(const std::string &method);
        void addTryFile(const std::string &file);
        void addIndexFile(const std::string &index);
};

#endif
