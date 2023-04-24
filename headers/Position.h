#ifndef POSITION_H
#define POSITION_H
#include<cmath>

class Position
{
    public:
        Position(int x=0,int y=0);
        double getX()const;
        double getY()const;
        void setX(double x);
        void setY(double y);
        double getDistance(const Position& p)const;

    private:
        double d_x;
        double d_y;
};

#endif // POSITION_H
