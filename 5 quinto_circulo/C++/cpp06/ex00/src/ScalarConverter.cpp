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
	std::string blacklisted[4] = {"nan", "-inf", "+inf", "inf"};
	for (i = 0; i < 4; i++)
	{
		if (blacklisted[i] == literal)
		    return (1);
		if (blacklisted[i] + "f" == literal)
		    return (2);
	}
	return (0);
}
/*
 * 0 - no num at all
 * 1 - int
 * 2 - double
 * 3 - float
 */
int numType(const std::string &literal)
{
    int     dots = 0;
    int     digits = 0;
    bool    endsF = (literal[literal.length() - 1] == 'f');
    int     loopSize = endsF ? literal.length() - 1 : literal.length();
    int     i = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;

    for(; i < loopSize; i++)
    {
        if (literal[i] == '.')
            dots++;
        else if (std::isdigit(literal[i]))
            digits++;
        else
            return (0);

    }
    if (digits > 0)
    {
        if (dots == 0 && !endsF)
            return (1);
        if (dots == 1)
            return (endsF ? 3 : 2);
    }
    return (0);
}

/*
    identify returns:
    0 - error or cannot identify
    1 - double (pseudo)
    2 - float (pseudo)
    3 - char
    4 - int
    5 - double
    6 - float
 */
int ScalarConverter::identify(const std::string &literal)
{
    if (literal.length() != 0)
    {
        if (isBlacklisted(literal) != 0)
            return (isBlacklisted(literal));
        if (literal.length() == 1 && !std::isdigit(literal[0]))
            return (3);
        if (numType(literal) != 0)
            return (3 + numType(literal));
    }
    return (0);
}
/*
    1- detect type (convert calls identify)
    2- convert from string to actual type (identify returns typeID and then it gets casted still inside convert)
    3- convert to other types
    4- display results
*/
void ScalarConverter::convert(const std::string &literal)
{
    ScalarConverter data;
    int type = data.identify(literal);
}
