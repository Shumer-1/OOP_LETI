#include "showField.h"

void Show::showField(Field& field, Controller& contr, EnemyController& enContr){
    std::cout << '\n';
    for (int i = 0; i < field.getSizeY(); i++){
        for (int j = 0; j < field.getSizeX(); j++){
            if (contr.getEndCoords().getX() == j && contr.getEndCoords().getY() == i)
                std::cout << 'E';
            if (contr.getCoords()->getX() == j && contr.getCoords()->getY() == i){
                std::cout << 'P';
            }
            else if (field.getCell(j, i).getEvent() != nullptr){
                TrapEvent *ev = dynamic_cast<TrapEvent*>(field.getCell(j, i).getEvent());
                if (ev != nullptr){
                    std::cout << 'W'; 
                    continue;
                }
                HealEvent *ev1 = dynamic_cast<HealEvent*>(field.getCell(j, i).getEvent());
                if (ev1 != nullptr){
                    std::cout << 'H'; 
                    continue;
                }
                TeleportEvent *ev2 = dynamic_cast<TeleportEvent*>(field.getCell(j, i).getEvent());
                if (ev2 != nullptr){
                    std::cout << 'T'; 
                    continue;
                }
                //std::cout << field.getCell(j, i).getEvent()->icon();
            }
            else if (field.getCell(j, i).getPassability()){
                std::cout << '.';
            }
            else {std::cout << '|';}
        }
        std::cout << '\n';
    }

    std::cout << contr.getPlayersParametrs(ParPlayer::HP) << " HP\n";
}