#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static int  isBlacklisted(const std::string &literal);

        static int  numType(const std::string &literal);

        int identify(const std::string &literal);

        void beString(char c);
        void beInt(int i);
        void beFloat(float f);
        void beDouble(double d);

    public:
        static void convert(const std::string &literal);
};
#endif
