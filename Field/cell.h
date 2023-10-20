#ifndef cell_h
#define cell_h

#include <iostream>
#include "../Events/event.h"

class Cell{
        private:
        bool passability;
        Event* event;
        // указатель на интерфейс события

        public:
        Cell(bool passability=true, Event* event); 
        Event* getEvent();
        // копирование
        Cell& operator = (const Cell& other);
        Cell(const Cell& other);
        //перемещение
        Cell(Cell&& other);
        Cell& operator = (Cell&& other);

        void setPassability(bool passability);
        bool getPassability();

        ~Cell();
};
#endif