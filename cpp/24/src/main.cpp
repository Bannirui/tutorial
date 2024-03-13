#include <iostream>
#include <string>

#define Print(msg) \
    std::cout << msg << std::endl

class Entity
{
private:
    std::string m_Name;

public:
    Entity() : m_Name("Unknown") {}

    Entity(const std::string &name) : m_Name(name) {}

    const std::string &GetName() const { return m_Name; }
};

int main(int argc, char **argv)
{
    /**
     * malloc->free
     * new->delete
     *
     * new在malloc的基础之上调用了构造方法
     * delete在free的基础之上调用了析构方法
     */
    int a = 2;
    int *b = new int;
    *b = a;
    delete b;

    Entity *e = new Entity();
    Print(e->GetName());
    delete e;
    return 0;
}