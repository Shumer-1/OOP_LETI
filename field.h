#ifndef field_h
#define field_h

#include <iostream>

#include "cell.h"
#include "coords.h"

#define MAX_BORDER 19
#define MAX_BORDER_X 39
#define MAX_BORDER_Y 19
#define MIN_BORDER 0
#define DEFAULT_SIZE_X 20
#define DEFAULT_SIZE_Y 10



enum Move{
    Up,
    Down,
    Left,
    Right
};


class Field{
        private:
        Cell ** field;
        int size_X;
        int size_Y;
        Coords start_coords;
        Coords final_coords;

        public:
        Field(int size_X=DEFAULT_SIZE_X, int size_Y=DEFAULT_SIZE_Y);

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