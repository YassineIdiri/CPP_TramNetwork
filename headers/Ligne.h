#ifndef LIGNE_H
#define LIGNE_H
#include <vector>

#include "ListeChaineeTram.h"
#include "ListeChaineeArret.h"
#include "ChainonTram.h"
#include "ChainonArret.h"



class Ligne
{
    public:
        Ligne();
        Ligne(ListeChaineeArret *LCA,ListeChaineeTram *LCT);
        ListeChaineeArret *renvoyerLCA() const;
        ListeChaineeTram *renvoyerLCT() const;
        void modifierLCA(ListeChaineeArret *A);
        void modifierLCT(ListeChaineeTram *T);
    private:
        ListeChaineeArret *d_LCA;
        ListeChaineeTram *d_LCT;
};

#endif // LIGNE_H
