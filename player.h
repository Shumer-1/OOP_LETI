#ifndef player_h
#define player_h

#define HP_DOWN 0
#define HP_UP 100
#define MONEY_DOWN 0
#define MONEY_UP 100
#define DAMAGE_DOWN 0
#define DAMAGE_UP 20
#define POINTS_DOWN 0
#define POINTS_UP 1000
#define HP_DEFAULT 20
#define MONEY_DEFAULT 0
#define DAMAGE_DEFAULT 5
#define POINTS_DEFAULT 0
#include <iostream>

enum ParPlayer{
        HP,
        Points,
        Damage,
        Money
};

class Player{
    private:
        int hp;
        int money;
        int points;
        int damage;

    public:
        Player(int hp, int money, int points, int damage);
        Player();
        void setHp(int hp);
        void setMoney(int money);
        void setPoints(int points);
        void setDamage(int damage);
        int getHp();
        int getMoney();
        int getPoints();
        int getDamage();
};
#endif