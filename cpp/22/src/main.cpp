#include <iostream>
#include <string>

#define Print(msg) \
    std::cout << msg << std::endl

class Example
{
public:
    Example()
    {
        Print("Create Example");
    }

    Example(int x)
    {
        std::cout << "Create Example with " << x << std::endl;
    }
};

class Entity
{
private:
    std::string m_Name;
    int m_Score;

    Example m_Example;

public:
    /**
     * 收益有2个
     *   - 编码风格
     *   - 性能提升
     */
    Entity()
        : m_Name("Unknown"), m_Score(0), m_Example(Example(8))
    {
        // m_Example = Example(9);
    }

    Entity(const std::string &name)
        : m_Name(name)
    {
    }

    const std::string &GetName() const
    {
        return m_Name;
    }
};

int main(int argc, char **argv)
{
    Entity e1;
    Print(e1.GetName());

    return 0;
}