#include <iostream>
#include <vector>

void ForEach(const std::vector<int> &values, void (*func)(int))
{
    for (int value : values)
        func(value);
}

int main(int argc, char **argv)
{
    std::vector<int> values = {1, 2, 3};
    auto lambda = [](int value)
    { std::cout << value << std::endl; };
    ForEach(values, lambda);
}