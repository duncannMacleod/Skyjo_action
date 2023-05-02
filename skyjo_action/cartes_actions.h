#ifndef CARTES_ACTIONS_H_INCLUDED
#define CARTES_ACTIONS_H_INCLUDED

#include "declaration.h"

void choix_carte_a_jouer(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr,int x,int y);
void jouer_14(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_15(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_16(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_17(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_18(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_19(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_20(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_21(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);
void jouer_22(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);

int recup_du_deck(S_joueur jr[],int no_jr,int choix);
void voir_l_ou_c(S_joueur jr,int x,int y);
int verif_carte_def(S_joueur jr);




#endif // CARTES_ACTIONS_H_INCLUDED
