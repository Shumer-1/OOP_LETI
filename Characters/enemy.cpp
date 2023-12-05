#include "./enemy.hpp"

template <class Move, class Action>
Enemy<Move, Action>::Enemy(): hp(ENEMY_HP), damage(ENEMY_DAMAGE), rate(ENEMY_RATE){}
template <class Move, class Action>
int Enemy<Move, Action>::getDamage(){
    return damage;
}
template <class Move, class Action>
int Enemy<Move, Action>::getHP(){
    return hp;
}
template <class Move, class Action>
int Enemy<Move, Action>::getRate(){
    return rate;
}
template <class Move, class Action>
Coords Enemy<Move, Action>::getCoords(){
    return coords;
}
template <class Move, class Action>
void Enemy<Move, Action>::setCoords(Coords coords){
    this->coords.setX(coords.getX());
    this->coords.setY(coords.getY());
}
