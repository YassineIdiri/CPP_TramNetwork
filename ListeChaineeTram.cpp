#include "ListeChaineeTram.h"
ListeChaineeTram::ListeChaineeTram(): d_tete{nullptr}//constructeur par défaut
{

}

ListeChaineeTram::~ListeChaineeTram()//destructeur
{
    while(d_tete)//tant que d_tete, le chainon qui parcours la liste chainée, existe
    {
		ChainonTram *tmp=d_tete->d_suivant;
		delete d_tete;
		d_tete=tmp;
	}
}

void ListeChaineeTram::insererTram(ChainonTram *t)//insertion d'un tram dans une ligne de tram
{
	if (d_tete==nullptr)//si la ligne n'existe pas
    {
		d_tete=t;
		return;
	}
	ChainonTram *prec=nullptr,*c=d_tete;
	while(c)//si elle existe
	{
		prec=c;
		c=c->d_suivant;
	}
	prec->d_suivant=t;
	t->d_suivant=c;
}

int ListeChaineeTram::taille() const//recupperer la taille d'une ligne
{
    ChainonTram *t = d_tete;
    int i = 0;
    while(t)
    {
        i++;
        t=t->d_suivant;
    }
    return i;
}

void ListeChaineeTram::affiche() const//fonction qui affiche chaque tram de la liste chainée
{
    ChainonTram *t = d_tete;
    while(t)
    {
        t->affiche();
        t = t->d_suivant;
    }

}

void ListeChaineeTram::efface() const//fonction qui efface chaque tram d'une liste chainée
{
    ChainonTram *t = d_tete;
    while(t)
    {
        t->efface();
        t = t->d_suivant;
    }
}


bool ListeChaineeTram::respecteDistance(ChainonTram *tram) const//fonction qui verifie que chaque tram respecte la distance de sécurité avec celui placé en paramètre
{

  ChainonTram *t;
  if(tram->d_suivant==nullptr)
  {
      t=d_tete;
  }
  else
  {
      t=tram->d_suivant;
  }

  if(tram->renvoyerSens()==t->renvoyerSens())
  {
      if(tram->renvoyerPositionT().renvoyerDistance(t->renvoyerPositionT()) < tram->renvoyerDistanceSecurite())
      {
          return false;
      }
  }

  return true;
}

ChainonTram *ListeChaineeTram::renvoyerTete()
{
    return d_tete;
}
