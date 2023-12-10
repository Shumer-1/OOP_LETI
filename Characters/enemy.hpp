#ifndef ENEMY
#define ENEMY

#include "../Field/coords.h"
#include "../Controller/controller.h"
#include <random>
template<class Movement, class Action>
class Enemy{
    Coords coords;
    Controller& contr;
    Field& field;
    public:
    Coords getCoords();
    void setCoords(Coords coords);
    void action();
    void moveEnemy();
    Enemy(Controller& contr, Field& field);
};


template <class Movement, class Action>
Enemy<Movement, Action>::Enemy(Controller& contr, Field& field): contr(contr), field(field){
    std::random_device rand;
    coords.setX(rand()%20 + 6);
    coords.setY(rand()%20 + 6);
}

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
    Action action = Action(contr, coords);
    action.enemyAction();
}

template <class Movement, class Action>
void Enemy<Movement, Action>::moveEnemy(){
    Movement move = Movement(coords, contr, field);
    move.move();
}
#endif