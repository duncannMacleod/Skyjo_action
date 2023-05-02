#ifndef SUIVI_SCORE_H_INCLUDED
#define SUIVI_SCORE_H_INCLUDED

#include "declaration.h"

void tri_score(int nb_j, S_joueur jr[]);
int fonct_compare_score(const void *a, const void *b);
int test_fin_manche(S_joueur jr[],int nb_jr); //renvoie le num�ro du joueur qui a gagn�
int test_fin_partie(S_joueur jr[],int nb_jr); //renvoie le num�ro du joueur qui a gagn�
void comptage_score(S_joueur jr[],int nb_jr);
S_joueur test_init_jr(S_joueur jr[],int nb_jr);//teste pour savoir si celui qui a initi� le dernier tour est le gagnant de la manche


#endif // SUIVI_SCORE_H_INCLUDED
