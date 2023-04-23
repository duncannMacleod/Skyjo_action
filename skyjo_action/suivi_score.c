#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "affichage.h"
#include "declaration.h"
#include "suivi_score.h"

int fonct_compare_score(const void *a, const void *b)//fonction servant à faire fonctionner qsort();
{
    S_joueur* pa=(S_joueur*)a;
    S_joueur* pb=(S_joueur*)b;
    return pb->score - pa->score;
}


void tri_score(int nb_jr, S_joueur jr[]) //sert a trier les joueurs par leurs score pour ensuite afficher le classement
{
    qsort(jr,nb_jr,sizeof(S_joueur),fonct_compare_score);
}

int test_fin_partie(S_joueur jr[],int nb_jr) //si un joueur a plus de 100 pts, la fonction renvoie le numéro de celui ayant dépassé le score
{
    int i;
    for(i=0;i<nb_jr;i++)
    {
        if(jr[i].score>=100)
            return i+1;
    }
    return 0;
}

void comptage_score(S_joueur jr[],int nb_jr) //prend en compte les règles du skyjo pour compter les points de chaque participant
{
    int i,somme,a,b;
    for(i=0;i<nb_jr;i++)
    {
        somme=0;
        for(a=0; a<3; a++)
            for(b=0; b<4; b++)
            {
                if(jr[i].deck_nombre[a][b]!=30&&jr[i].deck_nombre[a][b]!=13)//la valeur 30 correspond a pas de cartes, et la valeur 13 a la carte etoile qui vaut 0.
                    somme+=jr[i].deck_nombre[a][b];
            }
		somme-=(10*jr[i].nb_skyjo_colonne+15*jr[i].nb_skyjo_ligne); //on soustrait a la somme globlale les bonus de skyjo (-10 pour une colonne et -15 pour une linge)
		jr[i].score+=somme; //on incrémente la somme au score du joueur.

    }
}

int test_fin_manche(S_joueur jr[],int nb_jr) //renvoie le numéro du joueur qui a gagné la manche
{
    int i,a,b,cpt;
    for(i=0;i<nb_jr;i++)
    {
        cpt=0;
        for(a=0;a<CARTE_JOUEUR_NOMBRE_C;a++)
            for(b=0;b<CARTE_JOUEUR_NOMBRE_L;b++)
                if(jr[i].deck_nombre_cache[a][b]==1)
                    cpt++;
        if(cpt==15)
        return 1;
    }

    return 0;
}
