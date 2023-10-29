#include "showField.h"

void Show::showField(Field& field){
    for (int i = 0; i < field.getSizeY(); i++){
        for (int j = 0; j < field.getSizeX(); j++){
            if (field.getCell(j, i).getEvent() != nullptr){
                std::cout << '0';
            }
            else if (field.getCell(j, i).getPassability()){
                std::cout << '.';
            }
            else {std::cout << '|';}
        }
        std::cout << '\n';
    }
}