#include <iostream>

class Entity
{
public:
    virtual void play(){};
};

class Player : public Entity
{
};

class Enemy : public Entity
{
};

int main(int argc, char **argv)
{
    Player *player = new Player();
    Entity *actualPlayer = player;

    Entity *actualEnemy = new Enemy();

    Player *p1 = dynamic_cast<Player *>(actualEnemy);
    Player *p2 = dynamic_cast<Player *>(actualPlayer);
    return 0;
}