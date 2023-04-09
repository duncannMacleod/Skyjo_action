#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "initialisation.h"
#include "declaration.h"

void creation_profil_joueur(int nb_j, S_joueur jr[], S_pioche p,int *a)
{
    //on va commencer par demander les prénoms des joueurs
    for(int i=0;i<nb_j;i++)
    {
        printf("entrez le prénom du joueur %d:",nb_j-1);
        scanf("%s",jr[i].prenom);
    }


    int n;
    int i,j;


    for(n=0; n<nb_j; n++)
    {
        //initialisation des cartes de jeu
        for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {
                jr[n].deck_nombre[i][j]=p.nombre[*a];
                (*a)--;
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

        //initialisation du score
        jr[n].score=0;
    }
}







void initialisation_pioche_carte_action(int *b, S_pioche *p)
{
    for(int i=0; i<3;i++)
    {
        p->action_visible[i]=p->action[*b];
        (*b)--;
    }
}


void initialisation_defausse_nombre(S_pioche *p)
{
    p->nombre_defausse[0]=30;//initilise juste la première carte de la défausse, pour ne pas faire bugger l'affichage
}
