#include "field.h"



Field::Field(): size_X(DEFAULT_SIZE_X), size_Y(DEFAULT_SIZE_Y), start_coords(Coords()), final_coords(Coords(size_X-1, size_X-1)){
    field = new Cell* [size_Y];

    for (int i = 0; i < size_Y; i++){
        field[i] = new Cell[size_X];
    }
}


Field::Field(const Field& other): size_X(other.size_X), size_Y(other.size_Y){
    start_coords.setX(other.start_coords.getX());
    start_coords.setY(other.start_coords.getY());

    final_coords.setX(other.final_coords.getX());
    final_coords.setY(other.final_coords.getY());

    field = new Cell*[size_Y];
    for (int i=0; i<size_Y; i++){
        field[i] = new Cell[size_X];
        for (int j=0; j<size_X; j++){
            field[i][j] = other.field[i][j];
        }
    }
}


Field& Field::operator = (const Field& other){
    if (this != &other){
        for (int i = 0; i < size_Y; i++){
            delete [] field[i];
        }
        delete [] field;

        size_X = other.size_X;
        size_Y = other.size_Y;
        start_coords = other.start_coords;
        final_coords = other.final_coords;
        
        field = new Cell*[size_Y];
        for (int i = 0; i < size_Y; i++){
            field[i] = new Cell[size_X];
            for (int j = 0; j < size_X; j++){
                field[i][j] = other.field[i][j];
            }
        }
    }
    return *this;
}

Field::Field(Field&& other): size_X(0), size_Y(0), start_coords(Coords(0,0)), final_coords(Coords(0,0)), field(nullptr){
    
    std::swap(size_X, other.size_X);
    std::swap(size_Y, other.size_Y);
    std::swap(start_coords, other.start_coords);
    std::swap(final_coords, other.final_coords);
    std::swap(field, other.field);
}

Field& Field::operator = (Field&& other){
    if (this != &other){
        start_coords = Coords(0,0);
        final_coords = Coords(0,0);
        std::swap(size_X, other.size_X);
        std::swap(size_Y, other.size_Y);
        std::swap(start_coords, other.start_coords);
        std::swap(final_coords, other.final_coords);
        std::swap(field, other.field);
    }
    return *this;
}

Coords Field::getStartCoords(){
    return this->start_coords;
}

Coords Field::getFinalCoords(){
    return this->final_coords;
}

Cell& Field::getCell(int x, int y){
    if (x >= 0 && x < size_X && y >= 0 && y < size_Y){
        return field[x][y];
    }
    else{
        static Cell cell = Cell(false, nullptr);
        return cell;
    }
}

int Field::getSizeX(){
    return size_X;
}
int Field::getSizeY(){
    return size_Y;
}

Field::~Field(){
    
    for (int i = 0; i < size_Y; i++){
        delete[] field[i];
    }
    delete[] field;
}
