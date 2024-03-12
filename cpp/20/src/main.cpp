#include <iostream>
#include <string>

#define Print(msg) \
    std::cout << msg << std::endl

// 字符串拷贝极其消耗性能 使用引用
void PrintString(std::string &s)
{
    Print(s);
}

int main(int argc, char **argv)
{
    const char *name1 = "dingrui";
    Print(name1);

    char name2[1024] = {'d', 'i', 'n', 'g', 'r', 'u', 'i', '\0'};
    Print(name2);

    std::string name3 = "ding";
    Print(name3);

    std::string name4 = std::string("ding") + "rui";
    Print(name4);

    std::string name5 = "ding";
    name5 += "rui";
    Print(name5);
    PrintString(name5);

    const char name6[32] = "ding\0rui";
    Print(name6);

    const char *name7 = "dingrui";
    Print(name7);

    const char *name8 = u8"dingrui";
    const wchar_t *name9 = L"dingrui";
    const char16_t *name10 = u"dingrui";
    const char32_t *name11 = U"dingrui";
    Print(name8);
    Print(name9);
    Print(name10);
    Print(name11);

    return 0;
}