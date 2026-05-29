#ifndef CONFIGPREFLIGHT_HPP
# define CONFIGPREFLIGHT_HPP

# include <vector>
# include "ServerConfig.hpp"

bool runConfigPreflight(const std::vector<ServerConfig> &servers);

#endif