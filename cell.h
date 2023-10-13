#ifndef cell_h
#define cell_h

#include <iostream>

class Cell{
        private:
        bool passability;
        // указатель на интерфейс события

        public:
        Cell(bool passability=true); 
        // копирование
        Cell& operator = (const Cell& other);
        Cell(const Cell& other);
        //перемещение
        Cell(Cell&& other);
        Cell& operator = (Cell&& other);

        void setPassability(bool passability);
        bool getPassability();
};
#endif