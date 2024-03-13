#include <iostream>
#include <string>

#define Print(msg) \
    std::cout << msg << std::endl

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Entity() : m_Name("Unknown") {}

    Entity(const std::string &name)
        : m_Name(name), m_Age(-1) {}

    Entity(const int age)
        : m_Name("Unkonwn"), m_Age(age) {}

    const std::string &GetName() const { return m_Name; }
};

int main(int argc, char **argv)
{
    Entity a = Entity("ding");
    Print(a.GetName());
    Entity b = Entity(1);
    Print(b.GetName());

    // 隐式转换
    Entity d = 2;
    Print(d.GetName());

    Entity e(3);
    Print(e.GetName());

    Entity f = (Entity)22;
    Print(f.GetName());
}