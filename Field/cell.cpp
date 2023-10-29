#include "cell.h"

// сделать норм копирование? Тогда новые объекты каждый раз

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

Cell::Cell(const Cell& other): passability(other.passability){
    if (other.event) {
        event = other.event->copy();
    }
}

Cell& Cell::operator=(const Cell& other){
    if (this != &other){
        Cell temp(other);
        std::swap(passability, temp.passability);
        if (other.event) {
            event = other.event->copy();
        }
    }
    return *this;
}

Cell::Cell(Cell&& other): passability(true), event(nullptr){
    std::swap(passability, other.passability);
    if (other.event) {
        event = other.event->copy();
    }
}

Cell& Cell::operator=(Cell&& other){
    if (this != &other){
        std::swap(passability, other.passability);
        if (other.event) {
            event = other.event->copy();
        }
    }
    return *this;
}

Cell::~Cell(){
    if (event != nullptr){
        //delete event;
    }
}