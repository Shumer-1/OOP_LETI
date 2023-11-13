#include "showField.h"

void Show::showField(Field& field, Controller& contr){
    for (int i = 0; i < field.getSizeY(); i++){
        for (int j = 0; j < field.getSizeX(); j++){
            if (contr.getEndCoords().getX() == j && contr.getEndCoords().getY() == i)
                std::cout << 'E';
            if (contr.getCoords()->getX() == j && contr.getCoords()->getY() == i){
                std::cout << 'P';
            }
            else if (field.getCell(j, i).getEvent() != nullptr){
                std::cout << field.getCell(j, i).getEvent()->icon();
            }
            else if (field.getCell(j, i).getPassability()){
                std::cout << '.';
            }
            else {std::cout << '|';}
        }
        std::cout << '\n';
    }
}