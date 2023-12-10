#ifndef ENEMYCONTROLLER
#define ENEMYCONTROLLER

#include "./action.hpp"
#include "./movement.hpp"
#include "../Characters/enemy.hpp"
#include "../Field/coords.h"

class EnemyController{
    Enemy<Movement, Action>& enemy1;
    Enemy<Movement, Action>& enemy2;

    public:
    Coords getFirstEnemyCoords();
    Coords getSecondEnemyCoords();
    void setFirstEnemyCoords(Coords coords);
    void setFirstEnemyCoords(Coords coords);
    void firstEnemyAction();
    void secondEnemyAction();
    void firstEnemyMove();
    void secondEnemyMove();
};


#endif