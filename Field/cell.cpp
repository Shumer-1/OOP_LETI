#include "cell.h"


Event* Cell::getEvent(){
    return event;
}
void Cell::setEvent(Event* event){
    this->event = event;
}
Cell::Cell(bool passability, Event* event){
    this->passability = passability;
    this->event = event;
}
void Cell::setPassability(bool passability){
    this->passability = passability;
}
bool Cell::getPassability(){
    return passability;
}

Cell::Cell(const Cell& other): passability(other.passability), event(other.event){}

Cell& Cell::operator = (const Cell& other){
    if (this != &other){
        passability = other.passability;
        delete event;
        event = other.event;
    }
    return *this;
}

Cell::Cell(Cell&& other): passability(false), event(nullptr){
    std::swap(passability, other.passability);
    std::swap(event, other.event);
}

Cell& Cell::operator = (Cell&& other){
    if (this != &other){
        std::swap(event, other.event);
        std::swap(passability, other.passability);

    }
    return *this;
}

Cell::~Cell(){}