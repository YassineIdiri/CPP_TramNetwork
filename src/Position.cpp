
#include "../headers/Position.h"
Position::Position(int x,int y):
    d_x{x},
    d_y{y}
{
}

void Position::setX(double x)
{
    d_x=x;
}

void Position::setY(double y)
{
     d_y=y;
}

double Position::getX()const
{
  return d_x;
}

double Position::getY()const
{
   return d_y;
}

double Position::getDistance(const Position& p)const
{
    return sqrt(  ( (d_x-p.getX()) * (d_x-p.getX()) ) + ( (d_y-p.getY()) * (d_y-p.getY()) )   );
}
