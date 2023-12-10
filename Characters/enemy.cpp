#include "./enemy.hpp"

template <class Movement, class Action>
Enemy<Movement, Action>::Enemy(){}

template <class Movement, class Action>
Coords Enemy<Movement, Action>::getCoords(){
    return coords;
}
template <class Movement, class Action>
void Enemy<Movement, Action>::setCoords(Coords coords){
    this->coords.setX(coords.getX());
    this->coords.setY(coords.getY());
}

template <class Movement, class Action>
void Enemy<Movement, Action>::action(){
    Action action = Action();
    Action.enemyAction();
}

template <class Movement, class Action>
void Enemy<Movement, Action>::moveEnemy(){
    Movement move = Movement();
    move.move();
}