#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>

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

bool isBlacklisted(const std::string &literal)
{
    int i;
	std::string blacklisted[4] = {"nan", "-inf", "+inf", "inf"};
	for (i = 0; i < 4; i++)
	{
		if (blacklisted[i] == literal || blacklisted[i] + "f" == literal)
		    return (true);

	}
	return (false);
}

int isChar(const std::string &literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return (0);
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return (1);
    return (2);
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
    1 - pseudo
    2 - char
    3 - int
    4 - double
    5 - float
 */
int ScalarConverter::identify(const std::string &literal)
{
    if (literal.length() != 0)
    {
        if (isBlacklisted(literal))
            return (1);
        if(isChar(literal) != 2)
            return (2);
        if (numType(literal) != 0)
            return (2 + numType(literal));
    }
    return (0);
}

void printFromChar(char c)
{
    std::cout <<
    "char: \'" << c << "\'" << std::endl <<
    "int: " << static_cast<int>(c) << std::endl <<
    "float: " << static_cast<float>(c) << ".0f" << std::endl <<
    "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printFromInt(double d, int i)
{
    std::cout <<
    "char: \'" <<  static_cast<char>(i) << "\'" << std::endl
    << "int: ";
    if ((d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()))
    {
        std::cout << i << std::endl <<
        "float: " << static_cast<float>(i) << ".0f" << std::endl <<
        "double: " << static_cast<double>(i) << ".0" << std::endl;
    }
    else
    {
        std::cout << "impossible" << std::endl <<
        "float: " << static_cast<float>(d) << ".0f" << std::endl <<
        "double: " << d << ".0" << std::endl;
    }
}

void printFromFloat(float f)
{
    std::cout <<
    "char: \'" << static_cast<char>(f) << "\'" << std::endl << "int: ";
     if ((static_cast<double>(f) >= std::numeric_limits<int>::min()) && (static_cast<double>(f) <= std::numeric_limits<int>::max()))
         std::cout << static_cast<int>(f);
     else
         std::cout << "impossible";
    std::cout << std::endl <<
    "float: " << f << std::endl <<
    "double: " << static_cast<double>(f) << ".0" << std::endl;
}

void printFromDouble(double d)
{
    std::cout <<
    "char: \'" <<  static_cast<char>(d) << "\'" << std::endl << "int: ";
    if ((d >= std::numeric_limits<int>::min()) && (d <= std::numeric_limits<int>::max()))
        std::cout << static_cast<int>(d);
    else
        std::cout << "impossible";
   std::cout << std::endl <<
    "float: " << static_cast<float>(d) << ".0f" << std::endl <<
    "double: " << d << std::endl;
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
    switch (type)
    {
        case (1):
            {
                std::cout <<
                "char: impossible" << std::endl <<
                "int: impossible" << std::endl;
                if (literal[literal.size() - 1] == 'f')
                {
                    std::cout << "float: " << literal << std::endl;
                    std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
                }
                else
                {
                    std::cout << "float: " << literal << "f" << std::endl;
                    std::cout << "double: " << literal << std::endl;
                }
                break;
            }
        case (2):
            {
                printFromChar(literal[isChar(literal)]);
                break;
            }
        case (3):
            {
                double tmp = std::strtod(literal.c_str(), NULL);
                if ((tmp >= std::numeric_limits<int>::min() && tmp <= std::numeric_limits<int>::max()))
                    printFromInt(tmp, static_cast<int>(tmp));
                else
                    printFromInt(tmp, 0);
                break;
            }
        case (4):
            {
                printFromDouble(std::strtod(literal.c_str(), NULL));
                break;
            }
        case (5):
            {
                printFromFloat(std::strtof(literal.c_str(), NULL));
                break;
            }
        case (0):
        default:
            std::cout << "temporary error msg" << std::endl;
    }
}
