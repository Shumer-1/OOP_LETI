#include "../Controller/controller.h"

class MakeField{
    // статик класс, в котором есть только заполнение поля
    public:
    void makeWall(Coords& first, Coords& second, Field& field);
    void firstLevel(Controller& contr, Field& field);
    void generateLevel(Controller& contr, Field& field);

};