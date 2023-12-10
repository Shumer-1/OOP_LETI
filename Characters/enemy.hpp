#ifndef ENEMY
#define ENEMY

#include "../Field/coords.h"


template<class Movement, class Action>
class Enemy{
    Coords coords;

    public:
    Coords getCoords();
    void setCoords(Coords coords);
    void action();
    void moveEnemy();
    Enemy();
};

#endif