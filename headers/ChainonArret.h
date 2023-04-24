#ifndef CHAINONARRET_H_INCLUDED
#define CHAINONARRET_H_INCLUDED
#include <iostream>
#include<string>
#include "Position.h"
#include"graphics.h"
using namespace std;

class ChainonArret
{
    public:
        ChainonArret (string nom , const Position &p,bool occupe);  // construction d'un arret avec la position ou il se trouve ainsi que son nom
        Position renvoyerPosition()const;               // retourne la position de l'arret
        string nomArret() const;                        // retourne le nom de l'arret
        void affiche() const;
        bool estOccupe() const;
        void rendOccupe(bool t);
        ChainonArret *renvoyerSuivant();
        friend class ListeChaineeArret;
        friend class ChainonTram;
    private:
        string d_nom;
        Position d_pos;
        bool d_occupe;
        ChainonArret *d_suiv;
        ChainonArret *d_prec;
        //chainon precedent et suivant pour pouvoir creer une liste doublement chainée d'arret
};

#endif // CHAINONARRET_H_INCLUDED
