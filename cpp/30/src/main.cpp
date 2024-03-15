#include <iostream>

template <typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

template <typename T, int N>
class Array
{
private:
    T m_Array[N];

public:
    int GetSize() const { return N; }
};

int main(int argc, char **argv)
{
    Print<int>(5);
    Print(5.0f);
    Print("hello");

    Array<int, 55> array;
    std::cout << array.GetSize() << std::endl;
    return 0;
}