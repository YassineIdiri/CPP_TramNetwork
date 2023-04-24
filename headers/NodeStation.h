#ifndef NODESTATION_H_INCLUDED
#define NODESTATION_H_INCLUDED

#include <iostream>
#include <string>
#include "Position.h"
#include"graphics.h"

using namespace std;

class NodeStation
{
    public:
        NodeStation (string name, const Position& p,bool occupied);
        Position getPosition()const;
        string getStationName() const;
        void display() const;
        bool isOccupied() const;
        void setStationOccupied(bool t);
        NodeStation *getNext();

        friend class LinkedListStations;
        friend class NodeTram;
    private:
        string d_name;
        Position d_pos;
        bool d_occupied;
        NodeStation *d_next;
        NodeStation *d_prev;
};

#endif // NODESTATION_H_INCLUDED
