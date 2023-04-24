#ifndef CHAINONTRAM_H_INCLUDED
#define CHAINONTRAM_H_INCLUDED
#include <iostream>
#include "Position.h"
#include "ChainonArret.h"
#include "graphics.h"

class ChainonTram
{
    public:
        ChainonTram(ChainonArret* actuel, double vitesse ,Position pos);
        void avance();
        void affiche()const;
        void efface() const;
        bool estSurArret() const;                  //retourne vraie si le tram est situé sur un arret et depose donc les voyageurs
        double tempsRestant()const;                //retourne le temps qu'il reste au Tram
        void modifierTempsRestant(double t);
        void mettreSurArret(bool t);               // methode permetant de positionner le tram sur un arret
        bool renvoyerSens() const;                 //retourne vraie si le Tram circulent a l'aller ou faux si il circule au retour
        Position renvoyerPositionT()const;         // retourne la position du Tram
        double renvoyerVitesse() const;            //retourne la vitesse du Tram
        double renvoyerDistanceSecurite() const;   // retourne la distance de securite entre ce Tram et et celui qui est devant
        ChainonTram* renvoyerSuiv();
        void modifierArretActuel(ChainonArret *a);
        ChainonArret *arretActuel();
        friend class ChainonArret;
        friend class ListeChaineeTram;
   private:
        bool d_estSurUnArret;
        bool d_sens;
        double d_tempsRestantArret;
        double d_vitesse;
        Position d_pos;
        double d_distanceSecurite;
        ChainonArret *d_actuel;
        ChainonTram *d_suivant;
        ChainonTram *d_precedent;
        //chainon precedent et suivant pour pouvoir creer une liste doublement chainée de Tram
};










#endif // CHAINONTRAM_H_INCLUDED
