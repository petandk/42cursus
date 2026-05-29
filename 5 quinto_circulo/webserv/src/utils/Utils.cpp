#include <string>
#include <iostream>
#include "../inc/utils/Utils.hpp"
/*
    If not # found, then find returns std::string::npos wich is just max size for size_t
 */
void RemoveComments(std::string &fullLine)
{
    size_t  pos;

    pos = fullLine.find("#");
    if (pos != std::string::npos)
        fullLine.erase(pos);
}

void    trimWhitepaces(std::string &fullLine)
{
    if (fullLine.empty())
        return;
    size_t start;
    size_t end;
    start = fullLine.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
    {
        fullLine.clear();
        return;
    }
    end = fullLine.find_last_not_of(" \t\r\n");
    fullLine = fullLine.substr(start, (end - start) + 1);
}

size_t digitCounter(int num)
{
    size_t digits = 0;
    
    if (num < 0)
        num *= -1;
    while (num > 0)
    {
        digits++;
        num /= 10;
    }
    return (digits);
}

bool isAllDigits(const std::string &totest)
{
    if(totest.empty())
        return (false);

    for(size_t i = 0; i<totest.size(); i++)
    {
        if(!std::isdigit(static_cast<unsigned char>(totest[i]))) {
            #ifdef DEBUG
                        std::cout << "[DEBUG] isAllDigits: non-digit character found at position " << i << "." << std::endl;
            #endif
            return (false);
        }
    }
    return (true);
}

bool isAllowedChars(const std::string &totest, const std::string &accepted)
{
    if (totest.empty())
        return (false);

    for(size_t i = 0; i<totest.size(); i++)
    {
        if(!std::isalnum(static_cast<unsigned char>(totest[i])) &&
            accepted.find(totest[i]) == std::string::npos) {
            #ifdef DEBUG
                        std::cout << "[DEBUG] isAllowedChars: invalid character '" << totest[i] << "' at position " << i << "." << std::endl;
            #endif
            return (false);
        }
    }
    return (true);
}

bool isAllowedChars(const std::string &totest)
{
    return (isAllowedChars(totest, ""));
}