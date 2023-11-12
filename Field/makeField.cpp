#include "makeField.h"
#include "../Events/heal.h"
#include "../Events/trap.h"
#include "../Events/teleport.h"
#include "../Controller/controller.h"
#include "field.h"
#include <vector>
#define FREQUENCY 3

Field MakeField::generateNew(Controller& contr){
    std::random_device rand;
    Field field = Field();
    mazemake(field);
    for (int i = 0; i < DEFAULT_SIZE_Y; i++){
        for (int j = 0; j < DEFAULT_SIZE_X; j++){
            if (i == 0 || i == DEFAULT_SIZE_Y-1 || j == 0 || j == DEFAULT_SIZE_X-1){
                field.getCell(j, i).setPassability(false);
            }
        }
    }
    int flag_heal = 0;
    int flag_trap = 0;
    int flag_tel = 0;
    int k = 0;
    while (true){
        int a = rand() % DEFAULT_SIZE_X;
        int b = rand() % DEFAULT_SIZE_Y;
        if (field.getCell(a, b).getPassability() == true && field.getCell(a, b).getEvent() == nullptr && flag_heal == 0){
            field.getCell(a, b).setEvent(new TrapEvent(15, contr));
            flag_heal = 1;
        }
        if (field.getCell(a, b).getPassability() == true && field.getCell(a, b).getEvent() == nullptr && flag_trap == 0){
            field.getCell(a, b).setEvent(new HealEvent(10, contr));
            flag_trap = 1;
        }
        if (field.getCell(a, b).getPassability() == true && field.getCell(a, b).getEvent() == nullptr && flag_tel == 0){
            Coords coords = Coords(1, 1);
            field.getCell(a, b).setEvent(new TeleportEvent(contr, coords));
            flag_tel = 1;
        }
        if (flag_heal + flag_tel + flag_trap == 3){
            break;
        }
    }
    return field;
}

void mazemake(Field& field){
    int x, y, c, a; 
    bool b;
    int height = DEFAULT_SIZE_Y;
    int width = DEFAULT_SIZE_X;
    for(int i = 0; i < height; i++) // Массив заполняется землей-ноликами
        for(int j = 0; j < width; j++)
            field.getCell(j, i).setPassability(false);

    x = 3; y = 3; a = 0; // Точка приземления крота и счетчик
    while(a < 10000){ // Да, простите, костыль, иначе есть как, но лень
        field.getCell(y, x).setPassability(true); a++;
        while(1){ // Бесконечный цикл, который прерывается только тупиком
            c = rand()%4; // Напоминаю, что крот прорывает
            switch(c){  // по две клетки в одном направлении за прыжок
                case 0: if(y != 1)
                    if(field.getCell(x, y-2).getPassability() == false){ // Вверх
                        field.getCell(x, y-1).setPassability(true);
                    field.getCell(x, y-2).setPassability(true);
                    y-=2;
                }
                case 1: if(y != height-2)      
                    if(field.getCell(x, y+2).getPassability() == false){ // Вниз
                    field.getCell(x, y+1).setPassability(true);
                    field.getCell(x, y+2).setPassability(true);
                    y+=2;
                }
                case 2: if(x != 1)
                    if(field.getCell(x-2, y).getPassability() == false){ // Налево
                    field.getCell(x-1, y).setPassability(true);
                    field.getCell(x-2, y).setPassability(true);
                    x-=2;
                }
                case 3: if(x != width-2)
                    if(field.getCell(x+2, y).getPassability() == false){ // Направо
                    field.getCell(x+1, y).setPassability(true);
                    field.getCell(x+2, y).setPassability(true);
                    x+=2;
                }
            }
            if(deadend(x,y,field))
                break;
        }
        
        if(deadend(x,y,field)) // Вытаскиваем крота из тупика
            do{
                x = 2*(rand()%((width-1)/2))+1;
                y = 2*(rand()%((height-1)/2))+1;
            }
            while(field.getCell(x, y).getPassability() != true);
    }
} // На этом и все.

bool deadend(int x, int y, Field& field){
	int a = 0;
	int height = DEFAULT_SIZE_Y;
    int width = DEFAULT_SIZE_X;
	if(x != 1){
		if(field.getCell(x-2, y).getPassability() == true)
			a+=1;
		}
	else a+=1;
	
	if(y != 1){
		if(field.getCell(x, y-2).getPassability() == true)
			a+=1;
		}
	else a+=1;
	
	if(x != width-2){
		if(field.getCell(x+2, y).getPassability() == true)
			a+=1;
		}
	else a+=1;
	
	if(y != height-2){
		if(field.getCell(x, y+2).getPassability() == true)
			a+=1;
		}
	else a+=1;
	
	if(a == 4)
		return true;
	else
		return false;
}

Field MakeField::generateLevel(Controller& contr){
    std::vector<std::pair<int, int>> events;
    while (true){
        std::random_device rand_wall;
        std::random_device rand_event;

        Field field = Field();
       
        HealEvent *heal = new HealEvent(10, contr);
        TrapEvent *trap = new TrapEvent(20, contr);
        Coords coords = Coords(0, 0);
        TeleportEvent *tel = new TeleportEvent(contr, coords);
        //field.getCell(rand_event() % DEFAULT_SIZE_X, rand_event() % DEFAULT_SIZE_Y).setEvent(tel);
        long rand = rand_event();
        if (field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).getEvent() == nullptr){
            field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).setEvent(tel);
        }
        rand = rand_event();
        if (field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).getEvent() == nullptr){
            field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).setEvent(heal);
        }
        rand = rand_event();
        if (field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).getEvent() == nullptr){
            field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).setEvent(trap);
        }

        for (int i = 0; i < DEFAULT_SIZE_Y; i++){
            for (int j = 0; j < DEFAULT_SIZE_X; j++){
                rand = rand_wall();
                if (rand % FREQUENCY == 0 && field.getCell(j, i).getEvent() == nullptr){
                    field.getCell(j, i).setPassability(false);
                }
            }
        }
        if (checkPassability(field, field.getStartCoords().getX(), field.getStartCoords().getY())){
            return field;
            break;
        }
    }
}

bool MakeField::checkPassability(Field& field, int x, int y){
    if (field.getCell(field.getFinalCoords().getX(), field.getFinalCoords().getY()).getPassability() == false){
        return false;
    }
    if (field.getCell(x, y).getPassability() == false){
        return false;
    }
    if (x == field.getSizeX()-1 && y == field.getSizeY()-1)
        return true;
    return checkPassability(field, x+1, y) + checkPassability(field, x, y + 1);
}


// void MakeField::showField(Field& field){
//     for (int i = 0; i < field.getSizeY(); i++){
//         for (int j = 0; j < field.getSizeX(); j++){
//             if (field.getCell(j, i).getEvent() != nullptr){
//                 std::cout << '0';
//             }
//             else if (field.getCell(j, i).getPassability()){
//                 std::cout << '.';
//             }
//             else {std::cout << '|';}
//         }
//         std::cout << '\n';
//     }
// }