#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

/*
    arrT for the array type, they can be const
    funcT for the function type, so can be const or not

    Both arr and func must match, because the function 
    parameter depends on the array type.
    So we need 2 iter, 1 non-const 1 all-const.

*/

template <typename arrT, typename funcT>
void iteraction(arrT *arr, const size_t len, funcT func)
{
    if (!arr || !func)
        return;
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void iter(T *arr, const size_t len, void (*func)(T &))
{
    iteraction(arr,len,func);
}

template <typename T>
void iter(const T *arr, const size_t len, void (*func)(const T &))
{
    iteraction(arr,len,func);
}

#endif