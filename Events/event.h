#ifndef EVENT_H
#define EVENT_H

#include "../Controller/controller.h"

class Event {
    // это интерфейс игрового события на поле
    // три типа событий должны быть (пока что):
    // лечение, ловушка (уменьшение хп при попадании), телепортация (на другую клетку - фиксированная)
    public: 
    virtual void action(Controller& controller) = 0;
};

#endif