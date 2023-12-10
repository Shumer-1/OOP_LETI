#ifndef MOVEMENTGIVENWAY
#define MOVEMENTGIVENWAY
#include "./movement.hpp"
#include "./controller.h"


class MovementGivenWay: public Movement{
    Controller& contr; // coords player
    Field& field;
    Coords& coords; // coords me

    public:
    void move();
    MovementGivenWay(Coords& coords, Controller& contr, Field& field);
    Coords getCoords();
};
#endif