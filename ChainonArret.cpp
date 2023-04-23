#include "ChainonArret.h"
using namespace std;

ChainonArret::ChainonArret(string nom, const Position& p,bool occupe) : d_nom{nom}, d_pos{p},d_occupe{occupe}
{
    //construction d'un arret avec la position ou il se trouve, son nom et si l'arret est occupée
}

Position ChainonArret::renvoyerPosition() const
{
     return d_pos;//retourne la position de l'arret
}

string ChainonArret::nomArret() const
{
    return d_nom;//retourne le nom de l'arret
}


void ChainonArret::affiche() const
{
    bar(d_pos.renvoyerX()-13, d_pos.renvoyerY()-13, d_pos.renvoyerX()+13, d_pos.renvoyerY()+13);
     //affichage graphique du Tram avec la fonction bar
}


bool ChainonArret::estOccupe() const
{
    return d_occupe;//retourne vraie si l'arret est occupée
}

void ChainonArret::rendOccupe(bool t)
{
    d_occupe=t;//permet de rendre un arret occupable ou non
}

ChainonArret *ChainonArret::renvoyerSuivant()
{
    return d_suiv;//rentourne l'arret suivant
}
