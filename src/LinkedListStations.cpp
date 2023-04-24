#include "../headers/LinkedListStations.h"
LinkedListStations::LinkedListStations() : d_head{nullptr}
{

}

LinkedListStations::~LinkedListStations()
{
    while(d_head)
    {
        NodeStation *tmp=d_head->d_next;
        delete d_head;
        d_head=tmp;
    }
}


int LinkedListStations::length() const
{
    int i=0;
    NodeStation *a = d_head;
    while(a!=nullptr)
    {
        a = a->d_next;
        i++;
    }
    return i;
}


void LinkedListStations::insertStation(NodeStation *a)
{

   if(d_head==nullptr)
   {
       d_head=a;
   }
   else
   {
        NodeStation *prev=nullptr, *c=d_head;
        while(c!=nullptr)
        {
            prev=c;
            c=c->d_next;
        }
        prev->d_next=a;
        a->d_prev = prev;
        a->d_next = c;
   }

}

void LinkedListStations::display(int i) const
{
    if(i==0)
        setcolor(CYAN);
    else if(i==1)
        setcolor(GREEN);
    else if(i==2)
        setcolor(WHITE);
    else if(i==3)
       setcolor(LIGHTMAGENTA);

    NodeStation *a = d_head;
    while(a)
    {
        a->display();
        if(a->d_next!=nullptr)
        {
           line(a->getPosition().getX(),a->getPosition().getY(),a->d_next->getPosition().getX(),a->d_next->getPosition().getY());
        }
        a = a->d_next;
    }

}

NodeStation *LinkedListStations::getStationNear(NodeTram *t)
{
   NodeStation *a = d_head;

   while(a)
   {
       if(a->getPosition().getX() >
          t->getPosition().getX() - (1.5*(t->getSpeed())) &&
          a->getPosition().getX() <
          t->getPosition().getX() + (1.5*(t->getSpeed())) &&
          a->getPosition().getY() >
          t->getPosition().getY() - (1.5*(t->getSpeed())) &&
          a->getPosition().getY() <
          t->getPosition().getY() + (1.5*(t->getSpeed())))
       {
          return a;
       }
       else
       {
           a=a->d_next;
       }
   }
   return nullptr;
}

NodeStation *LinkedListStations::getHead()
{
    return d_head;
}

NodeStation *LinkedListStations::searchStation(string stationName)
{
    NodeStation *tmp= d_head;
    while(tmp !=nullptr && tmp->getStationName()!=stationName)
    {
        tmp=tmp->d_next;
    }
    return tmp;
}
