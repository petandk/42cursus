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

        int isBlacklisted(const std::string &literal);

        int identify(const std::string &literal);

        void beString(char c);
        void beInt(int i);
        void beFloat(float f);
        void beDouble(double d);

    public:
        /*
            1- detect type (convert calls identify)
            2- convert from string to actual type (identify returns typeID and then it gets casted still inside convert)
            3- convert to other types
            4- display results
        */
        static void convert(const std::string &literal);
};
#endif
