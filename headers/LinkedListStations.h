#ifndef LINKEDLISTSTATIONS_H_INCLUDED
#define LINKEDLISTSTATIONS_H_INCLUDED
#include <iostream>

#include "NodeStation.h"
#include "NodeTram.h"

class LinkedListStations
{
    public:
        LinkedListStations();
        ~LinkedListStations();
        int length() const;
        void insertStation(NodeStation *a);
        void display(int i) const;
        NodeStation *getHead();
        NodeStation *getStationNear(NodeTram *t);
        NodeStation *searchStation(string stationName);
    private:
        NodeStation *d_head;
};

#endif // LINKEDLISTSTATIONS_H_INCLUDED

