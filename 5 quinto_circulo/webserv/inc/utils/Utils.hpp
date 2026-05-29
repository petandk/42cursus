#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

void    RemoveComments(std::string &fullLine);
void    trimWhitepaces(std::string &fullLine);
size_t  digitCounter(int num);
bool    isAllDigits(const std::string &totest);
bool    isAllowedChars(const std::string &totest, const std::string &accepted);
bool    isAllowedChars(const std::string &totest);

#endif
