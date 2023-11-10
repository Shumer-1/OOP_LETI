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

Cell::Cell(const Cell &cell) : passability(cell.passability), event(cell.event == nullptr ? nullptr : cell.event->copy()) {
}

Cell &Cell::operator=(const Cell &cell) {
    if (this != &cell) {
        passability = cell.passability;
        delete event;
        event = cell.event == nullptr ? nullptr : cell.event->copy();
    }
    return *this;
}

Cell::Cell(Cell &&cell): passability(true), event(nullptr) {
    std::swap(passability, cell.passability);
    std::swap(event, cell.event);
}

Cell &Cell::operator=(Cell &&cell) {
    if (this != &cell) {
        std::swap(passability, cell.passability);
        std::swap(event, cell.event);
    }
    return *this;
}

Cell::~Cell(){
    delete event;
}