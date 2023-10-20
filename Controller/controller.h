#ifndef controller_h
#define controller_h

#include "../Characters/player.h"
#include "../Field/field.h"
#include "../Field/cell.h"
#include "../Field/coords.h"
#include "../Events/event.h"
#include "../Events/heal.h"


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