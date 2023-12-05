#include "../Controller/controller.h"
#include "./movement.hpp"

class MovementToPlayer: public Movement{
    Controller& contr;
    Field& field;
    Coords& coords;

    public:
    void move();
    MovementToPlayer(Coords& coords, Controller& contr, Field& field);
    Coords getCoords();
};