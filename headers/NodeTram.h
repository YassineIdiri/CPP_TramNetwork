#ifndef NODETRAM_H_INCLUDED
#define NODETRAM_H_INCLUDED

#include <iostream>
#include "Position.h"
#include "nodeStation.h"
#include "graphics.h"

class NodeTram
{
    public:
        NodeTram(NodeStation *currentStation, double speed, Position pos);
        void advance();
        void display()const;
        void eraseTram() const;
        bool isAtStation() const;
        double getTimeLeftAtStation() const;
        void setTimeLeftAtStation(double t);
        void putOnStation(bool t);
        bool getDirection() const;
        Position getPosition()const;
        double getSpeed() const;
        double getSafeDistance() const;
        NodeTram* getNext();
        void setCurrentStation(NodeStation *a);
        NodeStation *getCurrentStation();

        friend class NodeStation;
        friend class LinkedListStations;
         friend class LinkedListTrams;
   private:
        bool d_isAtStation;
        bool d_direction;
        double d_timeLeftAtStation;
        double d_speed;
        Position d_pos;
        double d_safeDistance;
        NodeStation *d_currentStation;
        NodeTram *d_next;
        NodeTram *d_prev;
};










#endif // CHAINONTRAM_H_INCLUDED
