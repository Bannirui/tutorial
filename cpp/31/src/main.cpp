#include <iostream>
#include <vector>

void Print()
{
    std::cout << "Hello World" << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int> &values, void (*f)(int))
{
    for (int value : values)
        f(value);
}

int main(int argc, char **argv)
{
    Print();

    void (*f)() = &Print;
    f();

    typedef void (*MyFunction)();
    MyFunction func = &Print;
    func();

    std::vector<int> values = {1, 2, 3, 4, 5};
    ForEach(values, PrintValue);

    ForEach(values, [](int value)
            { std::cout << "lambda: " << value << std::endl; });

    return 0;
}