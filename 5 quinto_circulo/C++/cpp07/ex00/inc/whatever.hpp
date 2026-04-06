#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap (T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
/*
    For min and max T params have to be const
    so you can use the function with values 
    instead of just variables.
    such as:
    int i = 6, j = 2 would work as min(i,j);
    but with const you can also do:
    min (6,2);
*/
template <typename T>
T min(T const &a, T const &b)
{
    return ((a < b)? a : b);
}

template <typename T>
T max(T const &a, T const &b)
{
    return ((a > b)? a : b);
}

#endif
