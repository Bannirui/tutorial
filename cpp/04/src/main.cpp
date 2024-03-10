#include <iostream>

int Multiply(int a, int b)
{
    return a * b;
}

void MultiplyAndLog(int a, int b)
{
    int ret = Multiply(a, b);
    std::cout << a << "*" << b << "=" << ret << std::endl;
}

int main()
{
    MultiplyAndLog(2, 3);
    MultiplyAndLog(3, 4);
    MultiplyAndLog(4, 5);
    return 0;
}