#include "./movement.hpp"
#include "./controller.h"


class MovementGivenWay: public Movement{
    Controller& contr;
    Field& field;
    Coords& coords;

    public:
    void move();
    MovementGivenWay(Coords& coords, Controller& contr, Field& field);
    Coords getCoords();
};