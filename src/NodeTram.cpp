
#include "../headers/NodeTram.h"
NodeTram::NodeTram(NodeStation *currentStation, double speed, Position pos):
    d_isAtStation{true} ,
    d_direction{true},
    d_timeLeftAtStation{20},
    d_speed{speed},
    d_pos{pos},
    d_safeDistance{100},
    d_currentStation{currentStation},
    d_next{nullptr},
    d_prev{nullptr}
{

}

Position NodeTram::getPosition() const
{
     return d_pos;
}

bool NodeTram::isAtStation()const
{
    return d_isAtStation;
}

void NodeTram::putOnStation(bool t)
{
    d_isAtStation=t;
}

void NodeTram::setTimeLeftAtStation(double t)
{
    d_timeLeftAtStation=t;
}

double NodeTram::getTimeLeftAtStation()const
{
    return d_timeLeftAtStation;
}

void NodeTram::advance()
{
    if(d_currentStation->d_next == nullptr)
    {
       d_direction=false;
    }
    if(d_currentStation->d_prev == nullptr)
    {
        d_direction=true;
    }

    if(d_direction==true)
    {
      double distanceBetweenStation = d_currentStation->d_pos.getDistance(d_currentStation->d_next->d_pos);
      double distanceTraveled = d_currentStation->d_pos.getDistance(d_pos);

      distanceTraveled+=d_speed;
      double portion = distanceTraveled/distanceBetweenStation;

      d_pos.setX((1-portion)*d_currentStation->d_pos.getX()+portion*d_currentStation->d_next->d_pos.getX());
      d_pos.setY((1-portion)*d_currentStation->d_pos.getY()+portion*d_currentStation->d_next->d_pos.getY());
    }
    else
    {
        double distanceBetweenStation = d_currentStation->d_pos.getDistance(d_currentStation->d_prev->d_pos);
        double distanceTraveled = d_currentStation->d_pos.getDistance(d_pos);

        distanceTraveled+=d_speed;
        double portion = distanceTraveled/distanceBetweenStation;

        d_pos.setX((1-portion)*d_currentStation->d_pos.getX()+portion*d_currentStation->d_prev->d_pos.getX());
        d_pos.setY((1-portion)*d_currentStation->d_pos.getY()+portion*d_currentStation->d_prev->d_pos.getY());
    }
}

void NodeTram::display() const
{
    if (d_direction == true)
    {
        setcolor(YELLOW);
    }
    else
    {
        setcolor(RED);
    }
    bar(d_pos.getX()-5, d_pos.getY()-5, d_pos.getX()+5, d_pos.getY()+5);
}

void NodeTram::eraseTram() const
{
   setcolor(BLACK);
   bar(d_pos.getX()-5, d_pos.getY()-5, d_pos.getX()+5, d_pos.getY()+5);
}



double NodeTram::getSpeed() const
{
    return d_speed;
}

bool NodeTram::getDirection()const
{
    return d_direction;
}

double NodeTram::getSafeDistance() const
{
    return d_safeDistance;
}

NodeTram* NodeTram::getNext()
{
   return d_next;
}

void NodeTram::setCurrentStation(NodeStation *a)
{
    d_currentStation=a;
}

NodeStation *NodeTram::getCurrentStation()
{
    return d_currentStation;
}
