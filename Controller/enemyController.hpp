#ifndef ENEMYCONTROLLER
#define ENEMYCONTROLLER

#include "./action.hpp"
#include "./movement.hpp"
#include "../Characters/enemy.hpp"
#include "../Field/coords.h"
#include "./actionDamage.hpp"
#include "./movementGivenWay.hpp"
#include "./movementToPlayer.hpp"
#include "./actionPush.hpp"

class Field;
class ShowField;

class EnemyController{
    Enemy<MovementGivenWay, ActionDamage>& enemy1;
    Enemy<MovementToPlayer, ActionPush>& enemy2;

    public:
    EnemyController(Enemy<MovementGivenWay, ActionDamage>& enemy1, Enemy<MovementToPlayer, ActionPush>& enemy2);

    Coords getFirstEnemyCoords();
    Coords getSecondEnemyCoords();
    void setFirstEnemyCoords(Coords coords);
    void setSecondEnemyCoords(Coords coords);
    void firstEnemyAction();
    void secondEnemyAction();
    void firstEnemyMove();
    void secondEnemyMove();
};


#endif