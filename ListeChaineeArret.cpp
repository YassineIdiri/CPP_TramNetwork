#include "ListeChaineeArret.h"

//constructeur par défaut
ListeChaineeArret::ListeChaineeArret() : d_t{nullptr}
{

}

//déstructeur
ListeChaineeArret::~ListeChaineeArret()
{
    while(d_t)
    {
        ChainonArret *tmp=d_t->d_suiv;
        delete d_t;
        d_t=tmp;
    }
}

//Fonction permettant de récuperer la taille de la liste chainée (donc le nombre d'arret de la ligne)
int ListeChaineeArret::taille() const
{
    int i=0;
    ChainonArret *a = d_t;
    while(a!=nullptr)
    {
        a = a->d_suiv;
        i++;
    }
    return i;
}

//Permet d'inserer un arret dans la liste chainée
void ListeChaineeArret::inserer(ChainonArret *a)
{

   if(d_t==nullptr)//si la ligne n'existe pas
   {
       d_t=a;
   }
   else//si elle existe
   {
        ChainonArret *prec=nullptr, *c=d_t;
        while(c!=nullptr)
        {
            prec=c;
            c=c->d_suiv;
        }
        prec->d_suiv=a;
        a->d_prec = prec;
        a->d_suiv = c;
   }

}

//procédure qui affiche la liste chainée
void ListeChaineeArret::affiche(int i) const
{
    if(i==0)//chaine de if permettant de connaitre la couleur de la ligne a dessiner selon son numéro
        setcolor(CYAN);
    else if(i==1)
        setcolor(GREEN);
    else if(i==2)
        setcolor(WHITE);
    else if(i==3)
       setcolor(LIGHTMAGENTA);

    ChainonArret *a = d_t;
    while(a)//boucle permettant de dessiner la ligne
    {
        a->affiche();
        if(a->d_suiv!=nullptr)
        {
           line(a->renvoyerPosition().renvoyerX(),a->renvoyerPosition().renvoyerY(),a->d_suiv->renvoyerPosition().renvoyerX(),a->d_suiv->renvoyerPosition().renvoyerY());
        }
        a = a->d_suiv;
    }

}

//fonction qui permet de renvoyer un arret quand un tram se rapproche de ce dernier
ChainonArret *ListeChaineeArret::arretProcheTram(ChainonTram *t)
{
   ChainonArret *a = d_t;

   while(a)//tant qu'a existe
   {
       if(a->renvoyerPosition().renvoyerX() >
          t->renvoyerPositionT().renvoyerX() - (1.5*(t->renvoyerVitesse())) &&
          a->renvoyerPosition().renvoyerX() <
          t->renvoyerPositionT().renvoyerX() + (1.5*(t->renvoyerVitesse())) &&
          a->renvoyerPosition().renvoyerY() >
          t->renvoyerPositionT().renvoyerY() - (1.5*(t->renvoyerVitesse())) &&
          a->renvoyerPosition().renvoyerY() <
          t->renvoyerPositionT().renvoyerY() + (1.5*(t->renvoyerVitesse())))
       {
          return a;
       }
       else
       {
           a=a->d_suiv;
       }
   }
   return nullptr;
}
//fonction qui permet de recupperer la tete
ChainonArret *ListeChaineeArret::renvoyerTete()
{
    return d_t;
}
//fonction qui permet de trouver si il existe un arret correspondant a un nom
ChainonArret *ListeChaineeArret::chercherArret(string nomArr)
{
ChainonArret *tmp= d_t;
while(tmp !=nullptr && tmp->nomArret()!=nomArr)//tant qu'on ne trouve pas l'arret
{
tmp=tmp->d_suiv;
}
return tmp;//return l'arret, donc nullptr si il n'est pas trouvé
}
