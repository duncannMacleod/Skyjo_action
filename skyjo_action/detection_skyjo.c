#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


#include "affichage.h"
#include "declaration.h"
#include "suivi_score.h"
#include "initialisation.h"
#include "deroulement_tour.h"
#include "detection_skyjo.h"


void detection_skyjo (int nb_jr, S_joueur jr[])
{


    int i,k;


    for(i=0;i<nb_jr;i++)
    {
        for(k=0;k<3;k++) //verifie les lignes
        {
            if((jr[i].deck_nombre[k][0])==(jr[i].deck_nombre[k][1])&&(jr[i].deck_nombre[k][1])==(jr[i].deck_nombre[k][2])&&(jr[i].deck_nombre[k][2])==(jr[i].deck_nombre[k][3])&&jr[i].deck_nombre_cache[k][0]==1&&jr[i].deck_nombre_cache[k][1]==1&&jr[i].deck_nombre_cache[k][2]==1&&jr[i].deck_nombre_cache[k][3]==1)
            { //si touts les nombres sont les memes sur la ligne k, alors elle remplace toutes les nombres par 30, et fait disparaitre les cases du tableau par mettre deck a -1
                jr[i].deck_nombre[k][0]=30; jr[i].deck_nombre[k][1]=30; jr[i].deck_nombre[k][2]=30; jr[i].deck_nombre[k][3]=30;
                jr[i].deck_nombre_cache[k][0]=-1; jr[i].deck_nombre_cache[k][1]=-1; jr[i].deck_nombre_cache[k][2]=-1; jr[i].deck_nombre_cache[k][3]=-1;
                jr[i].nb_skyjo_ligne++;
            }
        }
        for(k=0;k<4;k++) //verifie les colonnes
        { 
            if((jr[i].deck_nombre[0][k])==(jr[i].deck_nombre[1][k])&&(jr[i].deck_nombre[1][k])==(jr[i].deck_nombre[2][k])&&jr[i].deck_nombre_cache[0][k]==1&&jr[i].deck_nombre_cache[1][k]==1&&jr[i].deck_nombre_cache[2][k]==1)
            { //si touts les nombres sont les memes sur la colonne k, alors elle remplace toutes les nombres par 30, et fait disparaitre les cases du tableau par mettre deck a -1
                jr[i].deck_nombre_cache[0][k]=30; jr[i].deck_nombre_cache[1][k]=30; jr[i].deck_nombre_cache[2][k]=30;
                jr[i].deck_nombre_cache[0][k]=-1; jr[i].deck_nombre_cache[1][k]=-1; jr[i].deck_nombre_cache[2][k]=-1;
                jr[i].nb_skyjo_colonne++;
            }
        }
    }
}



