#include <iostream>
#include <cstring>

int main()
{
    int var = 8;
    void *p1 = &var;
    std::cout << p1 << std::endl;
    std::cout << *(int *)p1 << std::endl;

    int *p2 = &var;
    std::cout << *p2 << std::endl;
    *p2 = 10;
    std::cout << *p2 << std::endl;
    return 0;

    char *buffer = new char[8];
    memset(buffer, 0, 8);

    char **ptr = &buffer;

    delete[] buffer;
}