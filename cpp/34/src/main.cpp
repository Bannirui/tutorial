#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
    std::vector<int> values = {1, 2, 5, 4};
    std::sort(values.begin(), values.end());

    for (int v : values)
        std::cout << v << std::endl;

    std::sort(values.begin(), values.end(), [](int a, int b)
              { return b < a; });

    for (int v : values)
        std::cout << v << std::endl;
    return 0;
}