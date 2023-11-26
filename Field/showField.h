#ifndef SHOWFIELD_H
#define SHOWFIELD_H

#include "field.h"
#include "../Controller/controller.h"
#include "../Events/heal.h"
#include "../Events/teleport.h"
#include "../Events/trap.h"
#include "../Events/event.h"

class Controller;
class Show{
    public:
    void static showField(Field& field, Controller& contr);
};
#endif