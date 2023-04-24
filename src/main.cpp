#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../headers/graphics.h"
#include "../headers/Position.h"
#include "../headers/NodeStation.h"
#include "../headers/NodeTram.h"
#include "../headers/LinkedListStations.h"
#include "../headers/LinkedListTrams.h"
#include <windows.h>
#include <time.h>
#include "../headers/Line.h"
const int Larg = 1300;
const int Haut = 700;

using namespace std;


void loadData(vector <Line> &data)
{
    ifstream file("Lines.txt");
    if(!file)
    {
        cout<<"File can't be open"<<endl;
    }
    else
    {
        string tramName,stationName,lineName,n;
        char c;
        int x,y,v,linesNumber,stationsNumber;

        file>>n>>linesNumber;

        data.resize(linesNumber);
        for(int i=0; i<linesNumber ; i++)
        {
            LinkedListStations *l = new LinkedListStations;
            LinkedListTrams *t = new LinkedListTrams;
            file>>lineName>>n>>stationsNumber;

                for(int j = 0; j < stationsNumber; j++)
                {
                    file>>stationName>>c>>x>>c>>y>>c;
                    Position p{x,y};
                    file>>tramName;
                    if(tramName!="NoTram")
                    {
                       NodeStation *a = new NodeStation{stationName,p,true};
                       l->insertStation(a);
                       file>>c>>v>>c;
                       NodeTram *tr = new NodeTram{a,v,p};
                       t->inserertTram(tr);
                    }
                    else
                    {
                       NodeStation *a = new NodeStation{stationName,p,false};
                       l->insertStation(a);
                    }
               }
               Line b{l,t};
               data[i]=b;
        }

    }
}

bool nextFreeStatin(NodeTram *t,NodeStation *nextStation,vector<Line> data)
{
    bool m=false;
    int i=0;
    while(i<data.size() && m==false)
    {
        NodeStation *a=data[i].getLLS()->getHead();
        while(a && m==false)
        {
            if(a->getStationName()==nextStation->getStationName() && a->isOccupied()==true)
            {
                m=true;
            }
            else
            {
                a=a->getNext();
            }
        }
        if(m==false)
        {
            i++;
        }
    }

    return m;
}

void advanceNetwork(LinkedListStations *l, LinkedListTrams *tr,vector<Line> data)
{
   NodeTram *t = tr->getHead();
   while(t)
   {
       if(!(t->isAtStation()))
       {
         if(tr->respectDistance(t))
         {
           if(l->getStationNear(t))
           {
               if(l->getStationNear(t)->isOccupied()==false)
               {
                     NodeStation *nextStation= l->getStationNear(t);

                     if(nextFreeStatin(t,nextStation,data)==false)
                     {
                         t->setCurrentStation(l->getStationNear(t));
                         t->getCurrentStation()->setStationOccupied(true);
                         t->putOnStation(true);
                         t->setTimeLeftAtStation(2);
                     }
               }
           }
             t->advance();
        }
       }
       else
       {
           if(t->getTimeLeftAtStation()>0)
           {
               double nt=t->getTimeLeftAtStation();
               nt--;
               t->setTimeLeftAtStation(nt);
           }
           else
           {
               t->putOnStation(false);
               t->getCurrentStation()->setStationOccupied(false);
           }
       }
        t=t->getNext();
   }
}



void display(vector <Line> data)
{
            for(int i=0; i<data.size(); i++)
            {
                data[i].getLLT()->eraseListTrams();
                advanceNetwork(data[i].getLLS(),data[i].getLLT(),data);
                data[i].getLLS()->display(i);
                data[i].getLLT()->display();
            }
}

int main()
{
   opengraphsize(Larg,Haut);
   vector <Line> data;
   loadData(data);

   int i=0;
   while(i<500)
   {
       i++;
       display(data);
       Sleep(100);
   }
    getch();
}
