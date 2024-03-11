#include <iostream>

static int s_v = 5;

// extern int s_Val;
extern int val;
// 这个变量在Static.cpp文件中被static修饰 作用于限制在static文件中 linker在全局作用于找不到 报链接异常
extern int s_Val;

int main()
{
    std::cout << s_v << std::endl;
    // 这两个变量定义在Static.cpp中
    std::cout << val << std::endl;
    std::cout << s_Val << std::endl;
    return 0;
}