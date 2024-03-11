#include <iostream>
#include <cstring>

void increamentVal(int v)
{
    v++;
}

void increamentPtr(int *v)
{
    (*v)++;
}

void increamentRef(int &v)
{
    v++;
}

int main()
{
    int a = 5;
    int &ref = a;
    std::cout << "a=" << a << std::endl;
    std::cout << "ref=" << ref << std::endl;

    a = 2;
    std::cout << "a=" << a << std::endl;
    std::cout << "ref=" << ref << std::endl;

    ref = 3;
    std::cout << "a=" << a << std::endl;
    std::cout << "ref=" << ref << std::endl;

    // 值拷贝
    increamentVal(a);
    std::cout << "a=" << a << std::endl;
    std::cout << "ref=" << ref << std::endl;

    // 指针拷贝
    increamentPtr(&a);
    std::cout << "a=" << a << std::endl;
    std::cout << "ref=" << ref << std::endl;

    // 引用拷贝
    increamentRef(a);
    std::cout << "a=" << a << std::endl;
    std::cout << "ref=" << ref << std::endl;

    int c = 1;
    int d = 2;
    // 引用必须初始化
    int &r2 = c;
    std::cout << "c=" << c << std::endl;
    std::cout << "d=" << d << std::endl;
    std::cout << "r=" << r2 << std::endl;
    r2 = d;
    std::cout << "c=" << c << std::endl;
    std::cout << "d=" << d << std::endl;
    std::cout << "r=" << r2 << std::endl;
}