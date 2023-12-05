#ifndef ENEMY
#define ENEMY

#include "../Field/coords.h"

#define ENEMY_HP 10
#define ENEMY_DAMAGE 10
#define ENEMY_RATE 10

template<class Move, class Action>
class Enemy{
    int hp;
    int damage;
    int rate;
    Coords coords;

    public:
    int getHP();
    int getDamage();
    int getRate();
    Coords getCoords();
    void setCoords(Coords coords);
    Enemy();
};

#endif