#ifndef COORDS_H
#define COORDS_H

#define MAX_BORDER 19
#define MAX_BORDER_X 39
#define MAX_BORDER_Y 19
#define MIN_BORDER 0
#define DEFAULT_SIZE_X 30
#define DEFAULT_SIZE_Y 20

class Coords{
        private:
        int x;
        int y;
        public:
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
        Coords(int x=0, int y=0);
};
#endif