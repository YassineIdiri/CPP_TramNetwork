#include "Ligne.h"

Ligne::Ligne(ListeChaineeArret *LCA,ListeChaineeTram *LCT): d_LCA{LCA},d_LCT{LCT}
{

}

Ligne::Ligne(): d_LCA{nullptr} , d_LCT{nullptr}
{

}

ListeChaineeArret *Ligne::renvoyerLCA() const
{
    return d_LCA;
}
ListeChaineeTram *Ligne::renvoyerLCT() const
{
    return d_LCT;
}

void Ligne::modifierLCA(ListeChaineeArret *A)
{
   d_LCA=A;
}

void Ligne::modifierLCT(ListeChaineeTram *T)
{
    d_LCT=T;
}

