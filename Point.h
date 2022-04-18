#ifndef POINT_H
#define POINT_H

#include "headers.h"

class Point{
    private:
        int x;
        int y;
    public:
        Point();
        Point(int,int);
        void setX(int);
        void setY(int);
        int getX();
        int getY();
};

#endif // POINT_H