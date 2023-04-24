#ifndef LISTECHAINEETRAM_H_INCLUDED
#define LISTECHAINEETRAM_H_INCLUDED
#include <iostream>
#include <vector>
#include "Position.h"
#include"ChainonTram.h"
#include "ListeChaineeArret.h"



class ListeChaineeTram
{
  public :
      ListeChaineeTram();
      ~ListeChaineeTram();
      void insererTram(ChainonTram *t);
      int taille() const;
      void affiche() const;
      void efface() const;
      bool respecteDistance(ChainonTram *tram) const;
      ChainonTram *renvoyerTete();
      friend class ChainonTram;
  private:
      ChainonTram *d_tete;

};

#endif // LISTECHAINEETRAM_H_INCLUDED
