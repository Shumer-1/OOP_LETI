#include "./enemyController.hpp"

Coords EnemyController::getFirstEnemyCoords(){
    return enemy1.getCoords();
}
Coords EnemyController::getSecondEnemyCoords(){
    return enemy2.getCoords();
}
void EnemyController::setFirstEnemyCoords(Coords coords){
    enemy1.setCoords(coords);
}
void EnemyController::setFirstEnemyCoords(Coords coords){
    enemy2.setCoords(coords);
}

void EnemyController::firstEnemyAction(){
    enemy1.action();
}
void EnemyController::secondEnemyAction(){
    enemy2.action();
}
void EnemyController::firstEnemyMove(){
    enemy1.moveEnemy();
}
void EnemyController::secondEnemyMove(){
    enemy2.moveEnemy();
}
EnemyController::EnemyController(Enemy<MovementGivenWay, ActionDamage>& enemy1, Enemy<MovementToPlayer, ActionPush>& enemy2): enemy1(enemy1), enemy2(enemy2){}