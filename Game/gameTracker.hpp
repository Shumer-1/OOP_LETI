#ifndef GAMETRACKER_HPP
#define GAMETRACKER_HPP

#include "../Field/showField.h"
#include "./CoordsObs.hpp"
#include "./HPObserver.h"

class GameTracker{
    Controller& contr;
    Field& field;
    HPObserver hp_obs;
    CoordsObs coords_obs;

    public:
    void gameTracking();
    GameTracker(HPObserver hp_obs, CoordsObs coords_obs, Controller& contr, Field& field);
};
#endif