#ifndef POSITION_H
#define POSITION_H
#include<cmath>

class Position
{
    public:
        Position(int x=0,int y=0);
        double renvoyerX()const;
        double renvoyerY()const;
        void modifierX(double x);
        void modifierY(double y);
        double renvoyerDistance(const Position& p)const;

    private:
        double d_x;
        double d_y;
};

#endif // POSITION_H
