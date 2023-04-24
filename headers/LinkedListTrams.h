#ifndef LINKEDLISTTRAMS_H_INCLUDED
#define LINKEDLISTTRAMS_H_INCLUDED
#include <iostream>
#include <vector>
#include "Position.h"
#include "NodeTram.h"
#include "LinkedListStations.h"



class LinkedListTrams
{
  public :
      LinkedListTrams();
      ~LinkedListTrams();
      void inserertTram(NodeTram *t);
      int length() const;
      void display() const;
      void eraseListTrams() const;
      bool respectDistance(NodeTram *tram) const;
      NodeTram *getHead();

      friend class NodeTram;
  private:
     NodeTram *d_head;

};

#endif // LINKEDLISTTRAMS_H_INCLUDED
