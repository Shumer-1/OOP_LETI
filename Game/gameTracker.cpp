#include "./gameTracker.hpp"

void GameTracker::gameTracking(){
    if (hp_obs.update() || coords_obs.update()){
        Show::showField(field, contr, enContr);
    }
}

GameTracker::GameTracker(HPObserver hp_obs, CoordsObs coords_obs, Controller& contr, Field& field, EnemyController& enContr): hp_obs(hp_obs), coords_obs(coords_obs), contr(contr), field(field), enContr(enContr){}