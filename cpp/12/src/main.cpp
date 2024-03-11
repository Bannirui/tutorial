#include <iostream>

struct Entity
{
    /* data */
    static int x;
    static int y;

    static void Print()
    {
        std::cout << "x=" << x << ", y=" << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

int main()
{
    Entity::x = 1;
    Entity::y = 2;
    Entity::Print();

    Entity::x = 3;
    Entity::y = 4;
    Entity::Print();
    return 0;
}