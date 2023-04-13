#ifndef DEROULEMENT_TOUR_H_INCLUDED
#define DEROULEMENT_TOUR_H_INCLUDED



#include "declaration.h"

void initalisation_debut_tour (S_joueur jr[],int no_jr,int nb_jr, S_pioche *p,int x,int y);
void piocher_carte_nombre();
void piocher_carte_action();
void jouer_carte_action();
void regarder_jeu_des_autres(S_joueur jr[],int no_jr, int nb_jr, int x,int y);
#endif // DEROULEMENT_TOUR_H_INCLUDED
