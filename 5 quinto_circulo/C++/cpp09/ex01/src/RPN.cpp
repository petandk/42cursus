#include "../inc/RPN.hpp"

static bool isOperator(char o)
{
    return (o == '+' || o == '-' || o == '*' || o == '/');
}

static bool calculate(std::stack<int> &values, char op)
{
    if (values.size() < 2)
    {
        #ifdef DEBUG
            std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
            std::cout << "\033[1;33m\tNot enought numbers for a operation\033[0m" << std::endl;
        #endif
        return (false);
    }
    int num1 = values.top();
    values.pop();
    int num2 = values.top();
    values.pop();
    switch (op)
    {
        case '+':
            values.push(num2 + num1);
            break;
        case '-':
            values.push(num2 - num1);
            break;
        case '*':
            values.push(num2 * num1);
            break;
        case '/':
        {
            if (num1 == 0)
            {
                #ifdef DEBUG
                    std::cout <<  "\033[1;33m\t-----debug message operation result-----\033[0m" << std::endl;
                    std::cout << "\033[1;33m\tcannot divide by zero\033[0m" << std::endl;
                #endif
                return (false);
            }
            values.push(num2 / num1);
            break;
        }
    }
    #ifdef DEBUG
        std::cout <<  "\033[1;33m\t-----debug message operation result-----\033[0m" << std::endl;
        std::cout << "\033[1;33m\t" << values.top() << "\033[0m" << std::endl;
    #endif
    return (true);
}

bool RPN(std::string &op)
{
    if (op.empty())
    {
            #ifdef DEBUG
                std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
                std::cout << "\033[1;33m\tempty parameter\033[0m" << std::endl;
            #endif
            return (false);
        }
    std::istringstream iss(op);
    std::string token;
    std::stack<int>values;

    while (iss >> token)
    {
        if (token.size() != 1)
        {
            #ifdef DEBUG
                std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
                std::cout << "\033[1;33m\tthere's a number > than 9\033[0m" << std::endl;
            #endif
            return (false);
        }

        char val = token[0];
        #ifdef DEBUG
            std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
            std::cout << "\033[1;33m\t"<< val << "\033[0m" << std::endl;
        #endif
        if (std::isdigit(static_cast<unsigned char>(val)))
            values.push(val - '0');
        else if (isOperator(val)) // I did it with std::find but this is easier to read
        {
            if (!calculate(values, val))
                return (false);
        }
        else
        {
            #ifdef DEBUG
                std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
                std::cout << "\033[1;33m\tInvalid char\033[0m" << std::endl;
            #endif
            return (false);
        }
    }
    if (values.size() != 1)
    {
        #ifdef DEBUG
            std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
            std::cout << "\033[1;33m\tInvalid expression\033[0m" << std::endl;
        #endif
        return (false);
    }
    std::cout << values.top() << std::endl;
    return (true);
}
