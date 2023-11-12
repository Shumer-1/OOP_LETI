#include "player.h"


Player::Player(int hp, int money, int points, int damage){
    if ((hp < HP_DOWN || hp > HP_DEFAULT || money < MONEY_DOWN || money > MONEY_UP || points < POINTS_DOWN || points > POINTS_UP || damage < DAMAGE_DOWN || damage > DAMAGE_UP)){
        this->damage = DAMAGE_DEFAULT;
        this->hp = HP_DEFAULT;
        this->money = MONEY_DEFAULT;
        this->points = POINTS_DEFAULT;
        return;
    }
    this->damage = damage;
    this->hp = hp;
    this->points = points;
    this->money = money;
}
Player::Player(){
    damage = DAMAGE_DEFAULT;
    hp = HP_DEFAULT;
    points = POINTS_DEFAULT;
    money = MONEY_DEFAULT;
}
void Player::setHp(int hp){
    if (hp < HP_DOWN){
        this->hp = 0;
        return;
    }  
    this->hp = hp;
}
void Player::setMoney(int money){
    if (money < MONEY_DOWN || money > MONEY_UP){
        this->money = MONEY_DEFAULT;
        return;
    }  
    this->money = money;
}
void Player::setPoints(int points){
    if (points < POINTS_DOWN || points > POINTS_UP){
        this->points = POINTS_DEFAULT;
        return;
    }  
    this->points = points;
}
void Player::setDamage(int damage){
    if (damage < DAMAGE_DOWN || damage > DAMAGE_UP){
        this->damage = DAMAGE_DEFAULT;
        return;
    }
    this->damage = damage;
}
int Player::getHp(){
    return hp;
}
int Player::getMoney(){
    return money;
}
int Player::getPoints(){
    return points;
}
int Player::getDamage(){
    return damage;
}

