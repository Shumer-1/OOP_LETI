#ifndef controller_h
#define controller_h

#include "player.h"
#include "field.h"
#include "cell.h"
#include "coords.h"


class Controller{
    private:
    
    Player& player;
    Coords* coords;
    Field& field;


    public:
    Controller(Player& player, int* coords, Field& field);
    void movePlayer(Move move, int value);
    void changePlayersParametrs(ParPlayer parametr, int value);
    int getPlayersParametrs(ParPlayer parametr);
    Coords* getCoords();
    ~Controller();

};

#endif