#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include"graphics.h"
#include "Position.h"
#include "ChainonArret.h"
#include "ChainonTram.h"
#include "ListeChaineeArret.h"
#include"ListeChaineeTram.h"
#include <windows.h>
#include <time.h>
#include "Ligne.h"
const int Larg = 1300;
const int Haut = 700;

using namespace std;


void chargerDonnee(vector <Ligne> &donnee) //charger les données a partir du fichier txt
{
    ifstream fichier("Lignes.txt");
    if(!fichier)
    {
        cout<<"Le fichier n'a pas pu s'ouvrir."<<endl;
    }
    else
    {
        string nomTram,nomArret,nomLigne,n;
        char c;
        int x,y,v,nbLignes,nbArrets;

        fichier>>n>>nbLignes;

        donnee.resize(nbLignes);
        for(int i=0; i<nbLignes ; i++)
        {
            ListeChaineeArret *l = new ListeChaineeArret;
            ListeChaineeTram *t = new ListeChaineeTram;
            fichier>>nomLigne>>n>>nbArrets;

                for(int j = 0; j < nbArrets; j++)
                {
                    fichier>>nomArret>>c>>x>>c>>y>>c;
                    Position p{x,y};
                    fichier>>nomTram;
                    if(nomTram!="PasDeTram")
                    {
                       ChainonArret *a = new ChainonArret{nomArret,p,true};
                       l->inserer(a);
                       fichier>>c>>v>>c;
                       ChainonTram *tr = new ChainonTram{a,v,p};
                       t->insererTram(tr);
                    }
                    else
                    {
                       ChainonArret *a = new ChainonArret{nomArret,p,false};
                       l->inserer(a);
                    }
               }
               Ligne b{l,t};
               donnee[i]=b;
        }

    }
}

bool prochainArretLibre(ChainonTram *t,ChainonArret *prochainArret,vector<Ligne> donnee) //verifie si cet arret est libre (utilisé par le tram d'une
{                                                                                        //autre ligne ou pas) , permet de gérer les croisements de lignes
    bool m=false;
    int i=0;
    while(i<donnee.size() && m==false)
    {
        ChainonArret *a=donnee[i].renvoyerLCA()->renvoyerTete();
        while(a && m==false)
        {
            if(a->nomArret()==prochainArret->nomArret() && a->estOccupe()==true) //si cet arret est en commun avec una autre ligne (croisement)
            {                                                                    //et qu'il est occupé
                m=true;
            }
            else
            {
                a=a->renvoyerSuivant();
            }
        }
        if(m==false)
        {
            i++;
        }
    }

    return m;
}

void avancerReseau(ListeChaineeArret *l, ListeChaineeTram *tr,vector<Ligne> donnee) //fait avancer l'ensemble des trams
{
   ChainonTram *t = tr->renvoyerTete();
   while(t)
   {
       if(!(t->estSurArret()))    //si le tram est en marche (n'est pas sur un arret)
       {
         if(tr->respecteDistance(t))  //s'il respecte la distance de sécurité
         {
           if(l->arretProcheTram(t)) //s'il s'apprcohe d'un arret
           {
               if(l->arretProcheTram(t)->estOccupe()==false)  //si l'arret n'est pas occupé par un tram de la ligne de la ligne courante
               {
                     ChainonArret *prochainArret= l->arretProcheTram(t);
                     if(prochainArretLibre(t,prochainArret,donnee)==false) //si l'arret n'est pas occupé par un tram d'une autre ligne
                     {
                         t->modifierArretActuel(l->arretProcheTram(t));  //on le met sur cet arret
                         t->arretActuel()->rendOccupe(true);
                         t->mettreSurArret(true);
                         t->modifierTempsRestant(2);
                     }
               }
           }
             t->avance(); //on le fait avancer
        }
       }
       else
       {
           if(t->tempsRestant()>0)
           {
               double nt=t->tempsRestant();
               nt--;                                  //on decremente le temps restant a l'arret
               t->modifierTempsRestant(nt);
           }
           else
           {
               t->mettreSurArret(false);
               t->arretActuel()->rendOccupe(false);
           }
       }
        t=t->renvoyerSuiv();
   }
}



void affiche(vector <Ligne> donnee)
{
            for(int i=0; i<donnee.size(); i++)
            {
                donnee[i].renvoyerLCT()->efface();
                avancerReseau(donnee[i].renvoyerLCA(),donnee[i].renvoyerLCT(),donnee);
                donnee[i].renvoyerLCA()->affiche(i);
                donnee[i].renvoyerLCT()->affiche();
            }
}

int main()
{
   opengraphsize(Larg,Haut);
   vector <Ligne> donne;
   chargerDonnee(donne);

   int i=0;
   while(i<500)
   {
       i++;
       affiche(donne);
       Sleep(100);
   }
    getch();
}
