#include "../inc/ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter()
{
    #ifdef DEBUG
        std::cout << "Constructor called" << std::endl;
    #endif
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    #ifdef DEBUG
        std::cout << "Destructor called" << std::endl;
    #endif
}

int isBlacklisted(const std::string &literal)
{
    int i;
	std::string blacklisted[3] = {"nan", "-inf", "+inf"};
	for (i = 0; i < 3; i++)
	{
		if (blacklisted[i] == literal)
		    return (1);
		if (blacklisted[i] + "f" == literal)
		    return (2);
	}
	return (0);
}

int ScalarConverter::identify(const std::string &literal)
{
    if (isBlacklisted(literal) != 0)
        return (isBlacklisted(literal));
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return (3);
    return (0);
}

void ScalarConverter::convert(const std::string &literal)
{
    ScalarConverter data;
    int type = data.identify(literal);
}
