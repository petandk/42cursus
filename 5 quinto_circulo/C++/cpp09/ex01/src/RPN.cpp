#include "../inc/RPN.hpp"

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
        if (token.size() > 1)
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
        if (std::isdigit(val))
        {
            values.push(val - '0');
        }
        else if (values.size() >= 2)
        {
            int num1, num2;
            num1 = values.top();
            values.pop();
            num2 = values.top();
            values.pop();
            if (val == '+')
                values.push(num2 + num1);
            if (val == '*')
                values.push(num2 * num1);
            if (val == '-')
                values.push(num2 - num1);
            if (val == '/')
            {
                if (num1 != 0)
                    values.push(num2 / num1);
                else
                {
                    #ifdef DEBUG
                        std::cout <<  "\033[1;33m\t-----debug message operation result-----\033[0m" << std::endl;
                        std::cout << "\033[1;33m\tcannot divide by zero\033[0m" << std::endl;
                    #endif
                    return (false);
                }
            }
            #ifdef DEBUG
                std::cout <<  "\033[1;33m\t-----debug message operation result-----\033[0m" << std::endl;
                std::cout << "\033[1;33m\t" << values.top() << "\033[0m" << std::endl;
            #endif
        }
        else
        {
            #ifdef DEBUG
                std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
                std::cout << "\033[1;33m\tNot enought numbers for a operation\033[0m" << std::endl;
            #endif
            return (false);
        }

    }
    if (values.size() != 1)
    {
            #ifdef DEBUG
                std::cout <<  "\033[1;33m\t-----debug message-----\033[0m" << std::endl;
                std::cout << "\033[1;33m\tNeeded at least 2 numbers and a operator\033[0m" << std::endl;
            #endif
            return (false);
        }
    std::cout << values.top() << std::endl;
    return (true);
}
