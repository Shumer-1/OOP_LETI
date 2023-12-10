#include "./movementGivenWay.hpp"
#include <random>


void MovementGivenWay::move(){
    std::random_device rand;
    int step = rand() % 4;
    std::cout << step << "\n";
    int counter = 0;
    while (counter < 4){
        //UP
        if (step == 0 && coords.getY() + 1 > 0 && coords.getY() + 1 < field.getSizeY() && field.getCell(coords.getX(), coords.getY()+1).getPassability()){
            coords.setY(coords.getY()+1);
            break;
        }
        //DOWN
        if (step == 1 && coords.getY() - 1 > 0 && coords.getY() - 1 < field.getSizeY() && field.getCell(coords.getX(), coords.getY()-1).getPassability()){
            coords.setY(coords.getY()-1);
            break;
        }
        //RIGHT
        if (step == 2 && coords.getX() + 1 > 0 && coords.getX() + 1 < field.getSizeY() && field.getCell(coords.getX()+1, coords.getY()).getPassability()){
            coords.setY(coords.getY()+1);
            break;
        }
        //LEFT
        if (step == 3 && coords.getX() - 1 > 0 && coords.getX() - 1 < field.getSizeY() && field.getCell(coords.getX()-1, coords.getY()).getPassability()){
            coords.setY(coords.getX()-1);
            break;
        }
        step = rand()%4;
        counter++;
    }

}

MovementGivenWay::MovementGivenWay(Coords& coords, Controller& contr, Field& field): coords(coords), contr(contr), field(field){}

Coords MovementGivenWay::getCoords(){
    return coords;
}