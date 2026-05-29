#include "../inc/utils/Debug.hpp"

void printParsedConfig(const ConfigParser& parser) {
    const std::vector<ServerConfig>& servers = parser.getParsedServerConfigs();
    std::cout << "\n\033[35m=== Data after parsing ===\033[0m\n";
    for (size_t i = 0; i < servers.size(); ++i) {
        const ServerConfig& srv = servers[i];
        std::cout << "\033[36m=== Server " << i << " ===\033[0m\n";
        std::cout << "Host: " << srv.getHost() << "\n";
        std::cout << "Ports: ";
        const std::vector<int>& ports = srv.getPorts();
        for (size_t j = 0; j < ports.size(); ++j)
            std::cout << ports[j] << (j + 1 < ports.size() ? ", " : "");
        std::cout << "\nServer Names: ";
        const std::vector<std::string>& names = srv.getServerNames();
        for (size_t j = 0; j < names.size(); ++j)
            std::cout << names[j] << (j + 1 < names.size() ? ", " : "");
        std::cout << "\nRoot: " << srv.getRoot() << "\n";
        std::cout << "Index files: ";
        const std::vector<std::string>& idx = srv.getIndexFiles();
        for (size_t j = 0; j < idx.size(); ++j)
            std::cout << idx[j] << (j + 1 < idx.size() ? ", " : "");
        std::cout << "\nClient max body size: " << srv.getClientMaxBodySize() << "\n";
        std::cout << "Error pages:\n";
        const std::map<int, std::string>& errors = srv.getErrorPages();
        for (std::map<int, std::string>::const_iterator it = errors.begin(); it != errors.end(); ++it)
            std::cout << "  " << it->first << " -> " << it->second << "\n";
        // Locations
        const std::vector<LocationConfig>& locs = srv.getLocations();
        for (size_t k = 0; k < locs.size(); ++k) {
            const LocationConfig& loc = locs[k];
            std::cout << "\033[33m --- Location " << k << " ---\033[0m\n";
            std::cout << "  Path: " << loc.getPath() << "\n";
            std::cout << "  Root: " << loc.getRoot() << "\n";
            std::cout << "  Index files: ";
            const std::vector<std::string>& lidx = loc.getIndexFiles();
            for (size_t j = 0; j < lidx.size(); ++j)
                std::cout << lidx[j] << (j + 1 < lidx.size() ? ", " : "");
            std::cout << "\n  Allowed methods: ";
            const std::vector<std::string>& methods = loc.getAllowedMethods();
            for (size_t j = 0; j < methods.size(); ++j)
                std::cout << methods[j] << (j + 1 < methods.size() ? ", " : "");
            std::cout << "\n  Upload path: " << loc.getUploadPath() << "\n";
            std::cout << "  Autoindex: " << (loc.getAutoindex() ? "on" : "off") << "\n";
            std::cout << "  CGI extension: " << loc.getCgiExtension() << "\n";
            std::cout << "  CGI pass: " << loc.getCgiPass() << "\n";
            std::cout << "  Redirection code: " << loc.getRedirectCode() << "\n";
            std::cout << "  Redirect URL: " << loc.getRedirectUrl() << "\n";
        }
    }
}
