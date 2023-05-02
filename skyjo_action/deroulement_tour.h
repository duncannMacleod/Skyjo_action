#ifndef DEROULEMENT_TOUR_H_INCLUDED
#define DEROULEMENT_TOUR_H_INCLUDED



#include "declaration.h"

void debut_tour (S_joueur jr[],int no_jr,int nb_jr, S_pioche *p,int x,int y);

void piocher_carte_nombre(S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y);
void piocher_carte_action(S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y);



void retourne_toutes_cartes(S_joueur jr[],int nb_jr);

void regarder_jeu_des_autres(S_joueur jr[],int no_jr, int nb_jr, int x,int y);


void atribuer_nbr_etoile(S_joueur *jr,S_pioche *p, int x, int y);


#endif // DEROULEMENT_TOUR_H_INCLUDED
