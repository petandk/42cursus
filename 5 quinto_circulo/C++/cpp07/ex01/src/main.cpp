#include "../inc/iter.hpp"
#include <iostream>
#include <string>

void allOnes(int &n)
{
    n = 1;
}

template <typename T>
void doubleThem(T &n)
{
    n += n;
}

void shout(std::string &s)
{
    s += "!";
}

template <typename T>
void printThem(const T &n)
{
    std::cout << n << std::endl;
}

int main(void)
{

    int arr[4];
    const int constArr[3] = {10, 20, 30};
    int *nullArr = 0;

    std::string txt[5] = {"can", "yo", "tar", "bee", "aye"};

    std::cout << std::endl << "----------Simple array with Int values----------" << std::endl;
    iter(arr, 4, allOnes);
    std::cout << "all values must be set to \'1\':" << std::endl;
    iter(arr, 4, printThem);
    std::cout << "let's double all values:" << std::endl;
    iter(arr, 4, doubleThem);
    iter(arr, 4, printThem);
    std::cout << "let's double them again:" << std::endl;
    iter(arr, 4, doubleThem);
    iter(arr, 4, printThem);

    std::cout << std::endl << "----------Simple array with Strings----------" << std::endl;
    iter(txt, 5, printThem);
    std::cout << "all values must be doubled:" << std::endl;
    iter(txt, 5, doubleThem);
    iter(txt, 5, printThem);
    std::cout << "now they're shouting:" << std::endl;
    iter(txt, 5, shout);
    iter(txt, 5, printThem);

    std::cout << std::endl << "----------Const array with Int values----------" << std::endl;
    iter(constArr, 3, printThem);
    //iter(constArr, 3, doubleThem); // cannot double a const array!

    std::cout << std::endl << "----------NULL pointer test----------" << std::endl;
    iter(nullArr, 5, printThem);

    return (0);
}