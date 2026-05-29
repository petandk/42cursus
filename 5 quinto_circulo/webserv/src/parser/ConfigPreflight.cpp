#include "../../inc/parser/ConfigPreflight.hpp"
#include "../../inc/utils/BuilderUtils.hpp"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

/*
    I need to convert int to string
*/
static std::string itos(int n) 
{
std::stringstream oss;
oss << n;
return (oss.str());
}

static std::string concatRootError(const std::string &root, const std::string &err)
{
    if (root.empty())
        return (err);
    if (err.empty())
        return (root);
    if (root[root.size() - 1] == '/' && err[0] == '/')
        return (root + err.substr(1));
    if (root[root.size() - 1] != '/' && err[0] != '/')
        return (root + "/" + err);
    return (root + err);
}

static bool isValidPathNoLog(const std::string &path, bool needDir, bool needExec)
{
    std::string tmp = path;

    if (!fileExist(tmp))
        return (false);
    if (needDir && !isDirectory(path))
        return (false);
    if (needExec)
    {
        struct stat st;
        if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode) || access(path.c_str(), X_OK) != 0)
            return (false);
    }
    return (true);
}

static std::string resolveLocationPath(const std::string &root,
                                       const std::string &value,
                                       bool needDir,
                                       bool needExec)
{
    if (value.empty())
        return (value);

    // 1) Keep explicit FS paths as-is when they already validate.
    if (isValidPathNoLog(value, needDir, needExec))
        return (value);

    // 2) Fallback to site-root relative resolution (e.g. /uploads).
    if (!root.empty())
    {
        std::string rooted = concatRootError(root, value);
        if (isValidPathNoLog(rooted, needDir, needExec))
            return (rooted);
    }

    // Return direct value so caller prints a meaningful error label/path.
    return (value);
}

/* 
   needExist - path must exist
   needDir - path must be a directory
   needExec - path must be an executable regular file
   warnOnly - print warning instead of error and return true
*/
static bool checkPath(const std::string &path,
                      bool needExist,
                      bool needDir,
                      bool needExec,
                      const std::string &label,
                      bool warnOnly)
{
    if (path.empty())
    {
        if (warnOnly)
            std::cerr << "[WARN] " << label << " is empty." << std::endl;
        else
            std::cerr << "[ERROR] " << label << " is empty." << std::endl;
        return (warnOnly);
    }

    if (needExist)
    {
        std::string tmp = path;
        if (!fileExist(tmp))
        {
            if (warnOnly)
                std::cerr << "[WARN] " << label << " does not exist: " << path << std::endl;
            else
                std::cerr << "[ERROR] " << label << " does not exist: " << path << std::endl;
            return (warnOnly);
        }
    }

    if (needDir)
    {
        if (!isDirectory(path))
        {
            if (warnOnly)
                std::cerr << "[WARN] " << label << " is not a directory: " << path << std::endl;
            else
                std::cerr << "[ERROR] " << label << " is not a directory: " << path << std::endl;
            return (warnOnly);
        }
    }

    if (needExec)
    {
        struct stat st;
        if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode) || access(path.c_str(), X_OK) != 0)
        {
            if (warnOnly)
                std::cerr << "[WARN] " << label << " is not an executable file: " << path << std::endl;
            else
                std::cerr << "[ERROR] " << label << " is not an executable file: " << path << std::endl;
            return (warnOnly);
        }
    }
    return (true);
}

static void checkErrorPages(const ServerConfig &srv, size_t srvIdx)
{
    const std::map<int, std::string> &pages = srv.getErrorPages();
    const std::vector<LocationConfig> &locs = srv.getLocations();
    std::map<int, std::string>::const_iterator it;

    for (it = pages.begin(); it != pages.end(); ++it)
    {
        bool found = false;

        if (!srv.getRoot().empty())
        {
            std::string full = concatRootError(srv.getRoot(), it->second);
            std::string tmp = full;
            if (fileExist(tmp) && !isDirectory(full))
                found = true;
        }

        if (!found)
        {
            for (size_t i = 0; i < locs.size(); ++i)
            {
                if (locs[i].getRoot().empty())
                    continue;
                std::string full = concatRootError(locs[i].getRoot(), it->second);
                std::string tmp = full;
                if (fileExist(tmp) && !isDirectory(full))
                {
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            std::cerr << "[WARN] server #" << itos(srvIdx + 1)
                      << " error_page " << itos(it->first)
                      << " -> " << it->second
                      << " not found in configured roots." << std::endl;
    }
}

static bool checkServerRoot(const ServerConfig &srv, size_t srvIdx)
{
    const std::string &root = srv.getRoot();
    if (root.empty())
        return true;
    return checkPath(root, true, true, false,
                 std::string("server #") + itos(srvIdx + 1) + " root",
                 false);
}

static bool checkLocation(const ServerConfig &srv,
                          const LocationConfig &loc,
                          size_t srvIdx,
                          size_t locIdx)
{
    const std::string &locRoot = loc.getRoot();
    const std::string effRoot = locRoot.empty() ? srv.getRoot() : locRoot;

    if (!checkPath(effRoot, true, true, false,
               std::string("server #") + itos(srvIdx + 1) +
               " location #" + itos(locIdx + 1) + " root",
               false))
        return (false);

    const std::string &up = loc.getUploadPath();
    if (!up.empty())
    {
        const std::string resolvedUp = resolveLocationPath(effRoot, up, true, false);
        if (!checkPath(resolvedUp, true, true, false,
                       std::string("server #") + itos(srvIdx + 1) +
                       " location #" + itos(locIdx + 1) + " upload_path",
                       false))
            return (false);
    }

    const std::string &cgi = loc.getCgiPass();
    if (!cgi.empty() || !loc.getCgiExtension().empty())
    {
        if (cgi.empty())
        {
            std::cerr << "[ERROR] server #" << (srvIdx + 1)
                      << " location #" << (locIdx + 1)
                      << " has CGI extension configured but cgi_pass is empty." << std::endl;
            return (false);
        }
        const std::string resolvedCgi = resolveLocationPath(effRoot, cgi, false, true);
        if (!checkPath(resolvedCgi, true, false, true,
                       std::string("server #") + itos(srvIdx + 1) +
                       " location #" + itos(locIdx + 1) + " cgi_pass",
                       false))
            return (false);
    }

    return (true);
}

bool runConfigPreflight(const std::vector<ServerConfig> &servers)
{
    for (size_t i = 0; i < servers.size(); ++i)
    {
        const ServerConfig &srv = servers[i];
        const std::vector<LocationConfig> &locs = srv.getLocations();

        if (!checkServerRoot(srv, i))
            return (false);

        checkErrorPages(srv, i);

        for (size_t j = 0; j < locs.size(); ++j)
        {
            if (!checkLocation(srv, locs[j], i, j))
                return (false);
        }
    }
    return (true);
}