#ifndef SHOWFIELD_H
#define SHOWFIELD_H

#include "field.h"
#include "../Controller/controller.h"
#include "../Events/heal.h"
#include "../Events/teleport.h"
#include "../Events/trap.h"
#include "../Events/event.h"
#include "../Controller/action.hpp"
#include "../Controller/movement.hpp"
#include "../Characters/enemy.hpp"
#include "../Controller/enemyController.hpp"

class Controller;
class Show{
    public:
    void static showField(Field& field, Controller& contr, EnemyController& enContr);
};
#endif