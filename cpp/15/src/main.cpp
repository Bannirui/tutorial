#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity()
    {
        std::cout << "Create Entity" << std::endl;
        X = 0.0f;
        Y = 0.0f;
    }

    Entity(float x, float y)
    {
        std::cout << "Create Entity" << std::endl;
        X = x;
        Y = y;
    }

    ~Entity()
    {
        std::cout << "Destory Entity" << std::endl;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

void func()
{
    Entity e1;
    e1.Print();
}

int main()
{
    func();

    return 0;
}