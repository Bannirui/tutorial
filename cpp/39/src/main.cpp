#include <iostream>
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string &filepath)
{
    bool stream;
    if (stream)
    {
        std::string result;
        // read file
        return result;
    }
    return {};
}

int main(int argc, char **argv)
{
    std::optional<std::string> data = ReadFileAsString("data.txt");
    std::string value = data.value_or("Not present");
    if (data.has_value())
    {
        std::cout << "File read successfully\n";
    }
    else
    {
        std::cout << "File could not be opened\n";
    }
    return 0;
}