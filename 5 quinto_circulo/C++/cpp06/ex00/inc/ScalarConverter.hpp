#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
    private:
        int identify(const std::string &literal);

        void beString(char c);
        void beInt(int i);
        void beFloat(float f);
        void beDouble(double d);

    public:
        static void convert(const std::string &literal);
};

#endif
