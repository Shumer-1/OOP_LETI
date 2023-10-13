#ifndef COORDS_H
#define COORDS_H


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