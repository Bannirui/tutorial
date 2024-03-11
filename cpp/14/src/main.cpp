#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
    }

    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

int main()
{
    Entity e1;
    e1.Print();

    Entity e2(1.0f, 2.0f);
    e2.Print();
    return 0;
}