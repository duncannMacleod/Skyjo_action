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


void tri_score(int nb_j, S_joueur jr[])
{
    qsort(jr,nb_j,sizeof(S_joueur),fonct_compare_score);
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

