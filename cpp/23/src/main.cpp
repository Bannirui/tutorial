#include <iostream>
#include <string>

#define Print(msg) \
    std::cout << msg << std::endl

class Entity
{
private:
    std::string m_Name;

public:
    Entity()
        : m_Name("Unknown")
    {
    }

    Entity(const std::string &name)
        : m_Name(name)
    {
    }

    ~Entity()
    {
        std::cout << "Destory Entity, name=" << m_Name << std::endl;
    }

    const std::string &GetName() const
    {
        return m_Name;
    }
};

int main(int argc, char **argv)
{
    // 栈上内存
    Entity e1;
    Print(e1.GetName());

    Entity e2 = Entity("ding");
    Print(e2.GetName());

    Entity e3("rui");
    Print(e3.GetName());

    /**
     * 堆上分配内存
     * 什么时候选择将实例创建在堆上呢
     *   - 实例对象较大
     *   - 生命周期需求
     *
     * 大部分时候分配在栈上是比较好的选择
     */
    Entity *e4 = new Entity("dingrui");
    Print(e4->GetName());
    delete e4;

    return 0;
}