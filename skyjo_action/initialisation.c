#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "initialisation.h"
#include "declaration.h"

void creation_profil_joueur(int nb_j, S_joueur jr[], S_pioche p)
{
    //on va commencer par demander les prénoms des joueurs
    for(int i=0;i<nb_j;i++)
    {
        printf("entrez le prénom du joueur %d",nb_j-1);
        scanf("%s",jr[i].prenom);
    }


    int n;
    int i,j;
    int a=129; //depart de la dernière case du tab des S_cartes nombre

    for(n=0; n<nb_j; n++)
    {
        //initialisation des cartes de jeu
        for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {
                jr[n].deck_nombre[i][j]=p.nombre[a];
                a--;
            }

        }

        for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {

            }

        }

        //initialisation du score
        jr[n].score=0;
    }

}
