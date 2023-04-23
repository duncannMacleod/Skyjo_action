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


void tri_score(int nb_jr, S_joueur jr[])
{
    qsort(jr,nb_jr,sizeof(S_joueur),fonct_compare_score);
}

int test_fin_partie(S_joueur jr[],int nb_jr)
{
    int i;
    for(i=0;i<nb_jr;i++)
    {
        if(jr[i].score>=100)
            return i+1;
    }
    return 0;
}

void comptage_score(S_joueur jr[],int nb_jr)
{
    int i,somme,a,b;
    for(i=0;i<nb_jr;i++)
    {
        somme=0;
        for(a=0; a<3; a++)
            for(b=0; b<4; b++)
            {
                if(jr[i].deck_nombre[a][b]!=30&&jr[i].deck_nombre[a][b]!=13)
                    somme+=jr[i].deck_nombre[a][b];
                somme+=(10*jr[i].nb_skyjo_colonne+15*jr[i].nb_skyjo_ligne);
            }

    }
}

int test_fin_manche(S_joueur jr[],int nb_jr) //renvoie le numéro du joueur qui a gagné
{
    return 0;
}
