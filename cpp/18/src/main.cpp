#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; };

    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name) : m_Name(name)
    {
    }

    std::string GetName() override { return m_Name; }

    std::string GetClassName() override { return m_Name; }
};

void Print(Printable *p)
{
    std::cout << p->GetClassName() << std::endl;
}

int main()
{

    Entity *e = new Entity();
    Player *p = new Player("dingrui");

    Print(e);
    Print(p);

    return 0;
}