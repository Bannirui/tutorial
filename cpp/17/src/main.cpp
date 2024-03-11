#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName()
    {
        return "Entity";
    }
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name) : m_Name(name)
    {
    }

    std::string GetName() override
    {
        return m_Name;
    }
};

void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    Player *p = new Player("dingrui");
    std::cout << p->GetName() << std::endl;
    std::cout << ((Entity *)p)->GetName() << std::endl;

    PrintName(p);
    PrintName((Entity *)p);

    return 0;
}