#include <iostream>

void Function1()
{
    int i = 0;
    i++;
    std::cout << i << std::endl;
}

void Function2()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main(int argc, char **argv)
{
    std::cout << "Function1" << std::endl;
    Function1();
    Function1();
    Function1();
    std::cout << "Function2" << std::endl;
    Function2();
    Function2();
    Function2();
}