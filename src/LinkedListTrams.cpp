#include "../headers/LinkedListTrams.h"
LinkedListTrams::LinkedListTrams(): d_head{nullptr}
{

}

LinkedListTrams::~LinkedListTrams()
{
    while(d_head)
    {
		NodeTram *tmp=d_head->getNext();
		delete d_head;
		d_head=tmp;
	}
}

void LinkedListTrams::inserertTram(NodeTram *t)
{
	if (d_head==nullptr)
    {
		d_head=t;
		return;
	}
	NodeTram *prev=nullptr,*c=d_head;
	while(c)
	{
		prev=c;
		c=c->getNext();
	}
	prev->d_next=t;
	t->d_next=c;
}

int LinkedListTrams::length() const
{
    NodeTram *t = d_head;
    int i = 0;
    while(t)
    {
        i++;
        t=t->d_next;
    }
    return i;
}

void LinkedListTrams::display() const
{
    NodeTram *t = d_head;
    while(t)
    {
        t->display();
        t = t->d_next;
    }

}

void LinkedListTrams::eraseListTrams() const
{
    NodeTram *t = d_head;
    while(t)
    {
        t->eraseTram();
        t = t->d_next;
    }
}


bool LinkedListTrams::respectDistance(NodeTram *tram) const
{

  NodeTram *t;
  if(tram->d_next==nullptr)
  {
      t=d_head;
  }
  else
  {
      t=tram->d_next;
  }

  if(tram->getDirection()==t->getDirection())
  {
      if(tram->getPosition().getDistance(t->getPosition()) < tram->getSafeDistance())
      {
          return false;
      }
  }

  return true;
}

NodeTram *LinkedListTrams::getHead()
{
    return d_head;
}
