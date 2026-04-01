#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>

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

bool ScalarConverter::isBlacklisted(const std::string &literal)
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

int ScalarConverter::isChar(const std::string &literal)
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
NumType ScalarConverter::numType(const std::string &literal)
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
            return (NUM_INVALID);

    }
    if (digits > 0)
    {
        if (dots == 0 && !endsF)
            return (NUM_INT);
        if (dots == 1)
            return (endsF ? NUM_FLOAT : NUM_DOUBLE);
    }
    return (NUM_INVALID);
}

/*
    identify returns:
    0 - error or cannot identify
    1 - pseudo
    2 - char
    3 - int (2+1)
    4 - double (2+2)
    5 - float (2+3)
 */
int ScalarConverter::identify(const std::string &literal)
{
    if (literal.length() != 0)
    {
        if (isBlacklisted(literal))
            return (1);
        if(isChar(literal) != 2)
            return (2);
        NumType n = numType(literal);
        if (n != NUM_INVALID)
            return (2 + n);
    }
    return (0);
}

void ScalarConverter::auxChar(double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::auxInt(double d)
{
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

/*
    to check 
    if (c < 0 || c > 127)
    c has to be a int, so...
    int ci = static_cast<unsigned char>(c);
*/
void ScalarConverter::printFromChar(char c)
{
    int ci = static_cast<unsigned char>(c);
    std::cout << "char: ";
    if (ci < 0 || ci > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl
              << "float: " << static_cast<float>(c) << "f" << std::endl
              << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printFromInt(int i)
{
    auxChar(static_cast<double>(i));
    std::cout << "int: ";
    double d = static_cast<double>(i);
    if ((d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()))
    {
        std::cout << i << std::endl
                  << "float: " << static_cast<float>(i) << "f" << std::endl
                  << "double: " << static_cast<double>(i) << std::endl;
    }
    else
    {
        std::cout << "impossible" << std::endl
                  << "float: " << static_cast<float>(i) << "f" << std::endl
                  << "double: " << d << std::endl;
    }
}

void ScalarConverter::printFromFloat(float f)
{
    auxChar(static_cast<double>(f));
    auxInt(static_cast<double>(f));
    std::cout << "float: " << f << "f" << std::endl
              << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printFromDouble(double d)
{
    auxChar(d);
    auxInt(d);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl
              << "double: " << d << std::endl;
}

/*
    1- detect type (convert calls identify)
    2- convert from string to actual type (identify returns typeID and then it gets casted still inside convert)
    3- convert to other types
    4- display results

    std::cout << std::fixed << std::setprecision(1); //std::cout switches big numbers (more than 6 digits) to scientific notation. 
                                                        So 1234567891234 becomes 1.23457e+12.
                                                        With fixed you prevent that, and setprecision for the .0
                                                     //changes will work until modified or canceled, so we use 
                                                            std::cout.unsetf(std::ios::fixed);
                                                            std::cout.precision(6);
                                                        to reset it to "default"
*/
void ScalarConverter::convert(const std::string &literal)
{
    std::cout << std::fixed << std::setprecision(1);
    ScalarConverter data;
    int type = data.identify(literal);
    switch (type)
    {
        case (1):
            {
               if (literal[literal.size() - 1] == 'f')
                    printFromFloat(std::strtof(literal.c_str(), NULL));
                else
                    printFromDouble(std::strtod(literal.c_str(), NULL));
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
                    printFromInt(static_cast<int>(tmp));
                else
                    printFromDouble(tmp);
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
            std::cout << "Invalid literal!" << std::endl;
    }
    std::cout.unsetf(std::ios::fixed);
    std::cout.precision(6);
}
