#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

enum NumType
{
    NUM_INVALID,
    NUM_INT,
    NUM_DOUBLE,
    NUM_FLOAT
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static bool isBlacklisted(const std::string &literal);
        static int isChar(const std::string &literal);
        static NumType  numType(const std::string &literal);

        static int identify(const std::string &literal);

        static void auxChar(double d);
        static void auxInt(double d);

        static void printFromChar(char c);
        static void printFromInt( int i);
        static void printFromFloat(float f);
        static void printFromDouble(double d);

    public:
        static void convert(const std::string &literal);
};
#endif
