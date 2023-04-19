#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "initialisation.h"
#include "declaration.h"
#include "affichage.h"

void initialisation_generale (S_joueur jr[], S_pioche *p, int nb_j,int x,int y)
{
    initalisation_nb_cartes(p);

    //initialisation_carte_nombre(p);
    //initialisation_carte_action(p);
    initialisation_pioche_carte_action(p);
    initialisation_defausse_action(p);
    initialisation_defausse_nombre(p);
    initialisation_score(nb_j,jr);

    creation_profil_joueur(nb_j,jr,p,x,y);


}




void creation_profil_joueur(int nb_j, S_joueur jr[], S_pioche *p,int x, int y)
{
    int n;
    int i,j;

    //on va commencer par demander les prénoms des joueurs
    for(i=0; i<nb_j; i++)
    {


        do{

            Positionner_Curseur(x,y+i);
            printf("                                                                          ");
            Positionner_Curseur(x,y+i);
            printf("Veuillez entrez le prénom du joueur %d (max 10 caractères):",i+1); //conversationnel
            gets(jr[i].prenom); //l'utilisateur entre som prémon
        } while (strlen(jr[i].prenom)>10);

        jr[i].joueur_no=i+1; //le numéro du joueur prend la valeur de i+1 ex Joueur(1)->i=0+1

    }


    for(n=0; n<nb_j; n++)
    {
        //initialisation des cartes de jeu
        for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {
                jr[n].deck_nombre[i][j]=p->nombre[p->nombre_nb-1];  //prend une carte du paquet et la place dans le jeu du joueur
                p->nombre[p->nombre_nb-1]=30;                        //par sécurité, l'emplacement ou la carte a été prise récrécrit pour insinuer  "pas de carte"
                p->nombre_nb--;                                     //enlève 1 au nombre de cartes.
            }

        }

        for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {
                jr[n].deck_nombre_cache[i][j]=0; //on cache toutes les cartes
            }

        }

        //initialisation des deux cartes face montrée
        int rd_l=rand()%CARTE_JOUEUR_NOMBRE_L;
        int rd_c=rand()%CARTE_JOUEUR_NOMBRE_C;
        jr[n].deck_nombre_cache[rd_l][rd_c]=1;//on  retourne la première carte

        int rd_l2;
        int rd_c2;

        do
        {
            rd_l2=rand()%CARTE_JOUEUR_NOMBRE_L;
            rd_c2=rand()%CARTE_JOUEUR_NOMBRE_C;
        }
        while (rd_l==rd_l2&&rd_c==rd_c2); //permet que les 2 cartes levées soit les mêmes

        jr[n].deck_nombre_cache[rd_l2][rd_c2]=1; //on retourne la seconde carte

    }
}



void initalisation_nb_cartes(S_pioche *p) //initialise le nombre de cartes dans les paquets
{
    p->nombre_nb=120;
    p->action_nb=27;
}



void initialisation_pioche_carte_action( S_pioche *p)
{
    int i;
    for(i=0; i<3; i++)
    {
        p->action_visible[i]=p->action[(p->action_nb)-1];
        p->action_nb--;
    }
}


void initialisation_defausse_nombre(S_pioche *p)
{
    p->nombre_defausse[0]=30;//initilise juste la première carte de la défausse, pour ne pas faire bugger l'affichage
}
void initialisation_defausse_action(S_pioche *p)
{

    p->action_defausse[0]=30;//initilise juste la première carte de la défausse, pour ne pas faire bugger l'affichage
}

void initialisation_score(int nb_j,S_joueur jr[])
{
    int i;
    for(i=0;i<nb_j;i++)
       jr[i].score=0;
}
