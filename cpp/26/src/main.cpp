#include <iostream>
#include <string>

#define Print(msg) \
    std::cout << msg << std::endl

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Multiply(const Vector2 &other) const
    {
        return operator*(other);
    }

    // 重载操作符
    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator*(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    bool operator==(const Vector2 &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2 &other) const
    {
        return !(*this == other);
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector2 &other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main(int argc, char **argv)
{
    Vector2 pos(4.0f, 4.0f);
    Vector2 speed(0.5f, 05.f);
    Vector2 powerup(1.1f, 1.25f);
    Vector2 ret1 = pos.Add(speed.Multiply(powerup));
    std::cout << ret1 << std::endl;
    // 使用操作符
    Vector2 ret2 = pos + speed * powerup;
    std::cout << ret2 << std::endl;
    bool b = ret1 == ret2;
    Print(b);
    return 0;
}