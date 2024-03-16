#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived Constructor" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main(int argc, char **argv)
{
    Base *base = new Base();
    delete base;

    Derived *derived = new Derived();
    delete derived;

    return 0;
}