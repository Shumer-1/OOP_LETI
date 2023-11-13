#include "controller.h"


bool Controller::getGameOver(){
    return this->game_over;
}
void Controller::setGameOver(bool state){
    this->game_over = state;
}

Controller::Controller(Player& player, Field& field): player(player), field(field){
        game_over = false;
        this->coords = new Coords();
        this->coords->setX(1);
        this->coords->setY(1);
}

bool Controller::checkingEvents(){
    Event* event = field.getCell(coords->getX(), coords->getY()).getEvent();
    if (event != nullptr){
        event->action();
        return true;
    }
    else{
        return false;
    }
}

void Controller::movePlayer(Move move, int value){
    switch (move)
    {
    case Move::Down:
        {
        int i = 1;
        while (field.getCell(coords->getX(), coords->getY()-1).getPassability() && i <= value){
            coords->setY(coords->getY()-1);
            i++;
        }
        break;}
    case Move::Left:
        {
        int j = 1;
        while (field.getCell(coords->getX()-1, coords->getY()).getPassability() && j <= value){
            coords->setX(coords->getX()-j);
            j++;
        }
        break;}
    case Move::Right:
        {
        int k = 1;
        while (field.getCell(coords->getX()+1, coords->getY()).getPassability() && k <= value){
            coords->setX(coords->getX()+1);
            k++;
        }
        break;}
    case Move::Up:
        {
        int p = 1;
        while (field.getCell(coords->getX(), coords->getY()+1).getPassability() && p <= value){
            coords->setY(coords->getY()+1);
            p++;
        }
        break;}
    default:
        break;
    }
    Event* event = field.getCell(coords->getX(), coords->getY()).getEvent();
    if (event != nullptr){
        event->action();
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

void Controller::setPlayersCoords(Coords& coords){
    delete this->coords;
    this->coords = new Coords(coords);
}

Coords* Controller::getCoords(){
    return coords;
}
Controller::~Controller(){
    delete coords;
}
void Controller::setEndCoords(int x, int y){
    end.setX(x);
    end.setY(y);
}
Coords Controller::getEndCoords(){
    return end;
}