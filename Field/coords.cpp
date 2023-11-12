#include "coords.h"


void Coords::setX(int x){
    if (x > DEFAULT_SIZE_X || x < MIN_BORDER){
        this->x = 0;
    }
    this->x = x;
}
void Coords::setY(int y){
    if (y > DEFAULT_SIZE_Y || y < MIN_BORDER){
        this->y = 0;
    }
    this->y = y;
}
int Coords::getX() const{
    return x;
}
int Coords::getY() const{
    return y;
}
Coords::Coords(int x, int y){
    if (x > DEFAULT_SIZE_X || x < MIN_BORDER){
        this->x = 0;
    }
    else this->x = x;
    if (y > DEFAULT_SIZE_Y || y < MIN_BORDER){
        this->y = 0;
    }
    else this->y = y;
}