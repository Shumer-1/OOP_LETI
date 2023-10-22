#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include "coords.h"
#include "cell.h"


#define MIN_BORDER 0
#define DEFAULT_SIZE_X 20
#define DEFAULT_SIZE_Y 10

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