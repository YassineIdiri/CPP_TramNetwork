
#include "../headers/NodeStation.h"
using namespace std;

NodeStation::NodeStation(string name, const Position& p,bool occupied) : d_name{name}, d_pos{p},d_occupied{occupied}
{

}

Position NodeStation::getPosition() const
{
     return d_pos;
}

string NodeStation::getStationName() const
{
    return d_name;
}


void NodeStation::display() const
{
    bar(d_pos.getX()-13, d_pos.getY()-13, d_pos.getX()+13, d_pos.getY()+13);
}


bool NodeStation::isOccupied() const
{
    return d_occupied;
}

void NodeStation::setStationOccupied(bool t)
{
    d_occupied=t;
}

NodeStation *NodeStation::getNext()
{
    return d_next;
}
