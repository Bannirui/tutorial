#include <iostream>

int main(int argc, char **argv)
{
    const int var = 10;
    std::cout << var << std::endl;

    int *a = new int;
    *a = 2;
    std::cout << *a << std::endl;

    a = (int *)&var;
    std::cout << *a << std::endl;

    int v = 10;
    // b是变量 变量类型是指针 b存储的内容是地址
    // 地址上存储的数据类型是int 被const修饰
    // 语意就是b这个指针指向的int内容不能被修改
    const int *b = new int;
    std::cout << "b=" << *b << std::endl;
    // *b = 20; // 修改b这个指针指向的int内容不被允许
    b = &v; // 修改b这个指针指向的地址允许
    std::cout << "b=" << *b << std::endl;
    v = 30;
    std::cout << "b=" << *b << std::endl;

    // c是变量 变量类型是指针 指针指向的地址存储的数据类型是int
    // const修饰的是c
    // 语意就是c这个指针的地址不能变 地址上的内容随意
    int const *c = new int;
    std::cout << "c=" << *c << std::endl;
    c = &v; // c这个变量已经赋值了一个地址 不能再修改了
    // c = &val; // 尝试修改c的内容 不被允许
    std::cout << "c=" << *c << std::endl;
    v = 100;
    std::cout << "c=" << *c << std::endl;

    // 变量是d 变量d的类型是指针 指针指向的内存地址上存储的数据类型是int
    // const修饰的是d
    // 语意是d上的内容 就是地址不可修改
    int *const d = &v;
    std::cout << "d=" << *d << std::endl;
    v = 20;
    std::cout << "d=" << *d << std::endl;
    // d = &val; // 尝试修改变量d的内容(地址)不被允许

    return 0;
}