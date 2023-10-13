#ifndef controller_cpp
#define controller_cpp

#include "controller.h"


Controller::Controller(Player& player, int* coords, Field& field): player(player), field(field){
        if (!(coords[0] >= MIN_BORDER && coords[0] <= MAX_BORDER && coords[1] >= MIN_BORDER && coords[1] <= MAX_BORDER)){
            this->coords->setX(MAX_BORDER/2);
            this->coords->setY(MAX_BORDER/2);
            return;
        }
        this->coords = new Coords();
        this->coords->setX(coords[0]);
        this->coords->setY(coords[1]);
}
void Controller::movePlayer(Move move, int value){
    switch (move)
    {
    case Move::Down:
        {
        int i = 1;
        while (field.getCell(coords->getX(), coords->getY()-i).getPassability() && i <= value){
            coords->setY(coords->getY()-1);
            i++;
        }
        break;}
    case Move::Left:
        {
        int j = 1;
        while (field.getCell(coords->getX()-j, coords->getY()).getPassability() && j <= value){
            coords->setX(coords->getX()-j);
            j++;
        }
        break;}
    case Move::Right:
        {
        int k = 1;
        while (field.getCell(coords->getX()+k, coords->getY()).getPassability() && k <= value){
            coords->setX(coords->getX()+1);
            k++;
        }
        break;}
    case Move::Up:
        {
        int p = 1;
        while (field.getCell(coords->getX(), coords->getY()+p).getPassability() && p <= value){
            coords->setY(coords->getY()+1);
            p++;
        }
        break;}
    default:
        break;
    }
}

void Controller::changePlayersParametrs(ParPlayer parametr, int value){
    switch (parametr)
    {
    case ParPlayer::Damage:
        player.setDamage(player.getDamage()+value);
        break;
    case ParPlayer::HP:
        player.setHp(player.getHp()+value);
        break;
    case ParPlayer::Money:
        player.setMoney(player.getMoney()+value);
        break;
    case ParPlayer::Points:
        player.setPoints(player.getPoints()+value);
        break;
    default:
        break;
    }
}

int Controller::getPlayersParametrs(ParPlayer parametr){
    switch (parametr)
    {
    case ParPlayer::Damage:
        return(player.getDamage());
    case ParPlayer::HP:
        return(player.getHp());
    case ParPlayer::Money:
        return(player.getMoney());
    case ParPlayer::Points:
        return(player.getPoints());
    default:
        return 0;
    }
}

Coords* Controller::getCoords(){
    return coords;
}
Controller::~Controller(){
    delete coords;
}

#endif