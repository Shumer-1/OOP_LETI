#ifndef cell_cpp
#define cell_cpp

#include "cell.h"

Cell::Cell(bool passability){
    // проверки не нужны по идее - тип bool
    this->passability = passability;
}
void Cell::setPassability(bool passability){
    this->passability = passability;
}
bool Cell::getPassability(){
    return passability;
}

Cell::Cell(const Cell& other): passability(other.passability){}

Cell& Cell::operator = (const Cell& other){
    if (this != &other){
        passability = other.passability;
        
    }
    return *this;
}

Cell::Cell(Cell&& other): passability(false){
    std::swap(passability, other.passability);
}

Cell& Cell::operator = (Cell&& other){
    if (this != &other){
        passability = false;
        std::swap(passability, other.passability);
    }
    return *this;
}

#endif