#ifndef EVENT_H
#define EVENT_H

#include "../Controller/controller.h"


class Event {
    // это интерфейс игрового события на поле
    // три типа событий должны быть (пока что):
    // лечение, ловушка (уменьшение хп при попадании), телепортация (на другую клетку - фиксированная)
    public: 
    virtual void action() = 0; // он пустой
    virtual Event* copy() = 0;
    // а в событиях через конструктор
    // здесь только action

};

#endif