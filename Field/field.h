#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include "coords.h"
#include "cell.h"


class Cell;

class Field{
        private:
        Cell ** field;
        int size_X;
        int size_Y;
        Coords start_coords;
        Coords final_coords;

        public:
        Field();

        Field(const Field& other); // копирование
        Field& operator = (const Field& other);

        Field(Field&& other); // перемещение
        Field& operator = (Field&& other);

        Cell& getCell(int x, int y);
        Coords getStartCoords();
        Coords getFinalCoords();
        int getSizeX();
        int getSizeY();
        ~Field();
};


#endif