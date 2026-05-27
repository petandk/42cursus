 #include "../inc/easyfind.hpp"
 #include <iostream>
 #include <vector>
 #include <list>
 #include <deque>

 int main(void)
 {
    //vector
    std::vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    try
    {
        int pos = easyfind(v, 4);
        std::cout << "Vector: " << pos << " (expected 1)" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //list
    std::list<int> l;
    l.push_back(10);
    l.push_back(40);
    l.push_back(20);
     try
    {
        int pos = easyfind(l, 20);
        std::cout << "List: " << pos << " (expected 2)" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //deque
    std::deque<int> d;
    d.push_back(100);
    d.push_back(400);
    d.push_back(200);
    try
    {
        int pos = easyfind(d, 100);
        std::cout << "Deque: " << pos << " (expected 0)" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //fail
    try
    {
        int pos = easyfind(v, 100);
        std::cout << "Vector: " << pos << " (expected ERROR)" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << " (expected ERROR)" << std::endl;
    }

 }