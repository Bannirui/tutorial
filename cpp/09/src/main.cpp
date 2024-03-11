#include <iostream>
#include <cstring>

class Player
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

int main()
{
    Player p1;
    p1.x = 5;
    p1.Move(1, -1);

    return 0;
}