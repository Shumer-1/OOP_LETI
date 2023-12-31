#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Characters/player.h"
#include "../Field/coords.h"
#include "../Field/cell.h"
#include "../Field/field.h"
#include "../Events/event.h"


class Field;

enum Move{
    Up,
    Down,
    Left,
    Right
};

class Controller{
    private:
    bool game_over;
    Player& player;
    Coords* coords;
    Field& field;
    Coords end;

    public:
    bool getGameOver();
    void setGameOver(bool state);
    Controller(Player& player, Field& field);
    void movePlayer(Move move, int value);
    void changePlayersParametrs(ParPlayer parametr, int value);
    int getPlayersParametrs(ParPlayer parametr);
    Coords* getCoords();
    void setPlayersCoords(Coords& coords);
    bool checkingEvents();
    ~Controller();
    void setEndCoords(int x, int y);
    Coords getEndCoords();

};

#endif