#ifndef COORDSOBS_HPP
#define COORDSOBS_HPP

#include "../Controller/controller.h"
#include "./Observer.hpp"


class CoordsObs: public IObserver{
    Controller& contr;
    Coords coords;

    public:
    bool update() override;
    CoordsObs(Controller& contr);
};
#endif
