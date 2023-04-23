#ifndef SUIVI_SCORE_H_INCLUDED
#define SUIVI_SCORE_H_INCLUDED

#include "declaration.h"

void tri_score(int nb_j, S_joueur jr[]);
int fonct_compare_score(const void *a, const void *b);
int test_fin_manche(S_joueur jr[],int nb_jr); //renvoie le numéro du joueur qui a gagné
int test_fin_partie(S_joueur jr[],int nb_jr); //renvoie le numéro du joueur qui a gagné
void comptage_score(S_joueur jr[],int nb_jr);

#endif // SUIVI_SCORE_H_INCLUDED
