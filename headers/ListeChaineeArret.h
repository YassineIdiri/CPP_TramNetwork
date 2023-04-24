#ifndef LISTECHAINEEARRET_H_INCLUDED
#define LISTECHAINEEARRET_H_INCLUDED
#include <iostream>

#include"ChainonArret.h"
#include "ChainonTram.h"

class ListeChaineeArret
{
    public:
        ListeChaineeArret();
        ~ListeChaineeArret();
        int taille() const;
        void inserer(ChainonArret *a);
        void affiche(int i) const;
        ChainonArret *renvoyerTete();
        ChainonArret *arretProcheTram(ChainonTram *t);
        ChainonArret *chercherArret(string nomArr);
    private:
        ChainonArret *d_t;
};

#endif // LISTECHAINEEARRET_H_INCLUDED

