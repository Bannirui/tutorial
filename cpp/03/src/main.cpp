#include <iostream>

int main()
{
    int v1 = 8;
    unsigned int v2 = 1;

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    std::cout << "bool=" << sizeof(bool) << std::endl;
    std::cout << "float=" << sizeof(float) << std::endl;
    std::cout << "double=" << sizeof(double) << std::endl;
    std::cout << "long=" << sizeof(long) << std::endl;
    std::cout << "long long=" << sizeof(long long) << std::endl;
    std::cout << "long int=" << sizeof(long int) << std::endl;
    std::cout << "ptr=" << sizeof(int *) << std::endl;
    return 0;
}