#include "ChainonTram.h"

ChainonTram::ChainonTram(ChainonArret *actuel, double vitesse, Position pos):
    d_estSurUnArret{true} ,
    d_sens{true},
    d_tempsRestantArret{20},
    d_vitesse{vitesse},
    d_pos{pos},
    d_distanceSecurite{100},
    d_actuel{actuel},
    d_suivant{nullptr},
    d_precedent{nullptr}

    //construction d'un Tram avec:
    //-si le tram est a un arret(true) ou en marche(false)
    //-si le tram est dans l'aller(true) ou dans le retour de son trajet(false)
    //-temps qu'il met lors d'un arret qui est de 2sec pour tout les trams
    //-la vitesse du tram que l'on donne alors en parametre car tout les trams n'ont pas forcement la meme vitesse
    //-la position du tram qui est donner en parametre , c'est l'endroit ou le tram va etre initialiser
    //-distance de sécurité entre les Trams
    //-actuel c'est l'arret sur lequel le tram est situé.(l'arret est donner en parametre)
    //-le tram devant pour constituer une liste chainée
    //-le tram derriere pour constituer une liste doublement chainée

{

}

Position ChainonTram::renvoyerPositionT() const
{
     return d_pos;//retourne la position du Tram
}

bool ChainonTram::estSurArret()const
{
    return d_estSurUnArret;//retourne vraie si le Tram est située sur un arret et depose donc les voyageurs
}

void ChainonTram::mettreSurArret(bool t)
{
  d_estSurUnArret=t;// methode permettant de positionner le tram sur un arret
}

void ChainonTram::modifierTempsRestant(double t)
{
    d_tempsRestantArret=t;//methode permettant au Tram de modifier le temps sur un arret (pour décrémenter)

}

double ChainonTram::tempsRestant()const
{
    return d_tempsRestantArret;//retourne le temps qu'il reste au Tram
}

void ChainonTram::avance()
{
    if(d_actuel->d_suiv == nullptr)
    {
       d_sens=false;
    }
    if(d_actuel->d_prec == nullptr)
    {
        d_sens=true;
    }

    if(d_sens==true)
        //1er cas : l'aller
    {
      double distanceArrets = d_actuel->d_pos.renvoyerDistance(d_actuel->d_suiv->d_pos);  //la distance entre l'arret ou se situe le Tram et l'arret suivant
      double distanceParcouru = d_actuel->d_pos.renvoyerDistance(d_pos);                  //la distance entre l'arret et ou se situe le Tram

      distanceParcouru+=d_vitesse;
      double portion = distanceParcouru/distanceArrets;//a defaut d'utiliser la distance restante

      d_pos.modifierX((1-portion)*d_actuel->d_pos.renvoyerX()+portion*d_actuel->d_suiv->d_pos.renvoyerX());  //Pour modifier la position du Tram
      d_pos.modifierY((1-portion)*d_actuel->d_pos.renvoyerY()+portion*d_actuel->d_suiv->d_pos.renvoyerY());  //Pour modifier la position du Tram
    }
    else
        //2eme cas : retour
        // on utilisera alors l'arret precedent puisque lorsque l'on change de sens l'arret precedent devient l'arret suivant
    {
        double distanceArrets = d_actuel->d_pos.renvoyerDistance(d_actuel->d_prec->d_pos);
        double distanceParcouru = d_actuel->d_pos.renvoyerDistance(d_pos);

        distanceParcouru+=d_vitesse;
        double portion = distanceParcouru/distanceArrets;

        d_pos.modifierX((1-portion)*d_actuel->d_pos.renvoyerX()+portion*d_actuel->d_prec->d_pos.renvoyerX());
        d_pos.modifierY((1-portion)*d_actuel->d_pos.renvoyerY()+portion*d_actuel->d_prec->d_pos.renvoyerY());
    }
}

void ChainonTram::affiche() const
{
    if (d_sens == true)
    {
        setcolor(YELLOW);  // jaune pour les Trams circulant a l'aller
    }
    else
    {
        setcolor(RED);     // rouge pour les Trams circulant au retour
    }
    bar(d_pos.renvoyerX()-5, d_pos.renvoyerY()-5, d_pos.renvoyerX()+5, d_pos.renvoyerY()+5);
    //affichage graphique du Tram avec la fonction bar
    //on renvoie les position X et Y avec -5 pour permettre d'afficher un carré plus petit que l'arret afin de toujours voir l'arret
}

void ChainonTram::efface() const
{
   setcolor(BLACK);//couleur de l'interface graphique
   //en réalité affiche en noir les coordonnée actuel(meme couleur que l'interphace)
   bar(d_pos.renvoyerX()-5, d_pos.renvoyerY()-5, d_pos.renvoyerX()+5, d_pos.renvoyerY()+5);
   //affichage graphique du Tram avec la fonction bar
}



double ChainonTram::renvoyerVitesse() const
{
    return d_vitesse;//retourne la vitesse du Tram
}

bool ChainonTram::renvoyerSens()const
{
    return d_sens;// retourne vraie si le Tram circulent a l'aller ou faux si il circule au retour
}

double ChainonTram::renvoyerDistanceSecurite() const
{
    return d_distanceSecurite;// retourne la distance de securite entre ce Tram et celui qui le précède ainsi que celui devant
}

ChainonTram* ChainonTram::renvoyerSuiv()
{
   return d_suivant;//retourne le prochain tram
}

void ChainonTram::modifierArretActuel(ChainonArret *a)
{
    d_actuel=a;//modifie l'arret du Tram avec l'arret passer en parametre
}

ChainonArret *ChainonTram::arretActuel()
{
    return d_actuel;// retourne l'arret actuel du tram
}
