#include <iostream>

#include "log.h"

// if
void if_func()
{
    int x = 6;
    bool flag = x == 5;
    if (flag)
    {
        Log("true");
    }
    else
    {
        Log("false");
    }

    const char *ptr = NULL;
    if (ptr)
        Log(ptr);
    else
        Log("ptr is null");
}

// for
void for_func(int cnt)
{
    int i = 0;
    for (; i < cnt; i++)
    {
        if (i < 2)
            continue;
        if (i == 4)
            break;
        std::cout << "for, i=" << i << std::endl;
    }
}

// while
void while_func()
{
    int i = 0;
    while (i < 5)
    {
        Log("while");
        i++;
    }

    int j = 5;
    do
    {
        Log("do while");
    } while (j < 5);
}

int main()
{
    if_func();
    for_func(5);
    while_func();
    return 0;
}