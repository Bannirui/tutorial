#include <iostream>

class Entity
{
public:
    float x, y;

    void Move(float xa, float ya)
    {
        x += xa;
        y += ya;
    }
};

class Player : public Entity
{
public:
    const char *name;

    void PrintName()
    {
        std::cout << name << std::endl;
    }
};

int main()
{
    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    Player p1;
    p1.Move(1, 2);

    return 0;
}