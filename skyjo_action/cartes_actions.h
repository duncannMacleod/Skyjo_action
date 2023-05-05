#ifndef CARTES_ACTIONS_H_INCLUDED
#define CARTES_ACTIONS_H_INCLUDED

#include "declaration.h"

void choix_carte_a_jouer(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr,int x,int y);//conversationnel permetant de demander quelle carte le joueur veut jouer dans son deck, puis l'enlève du deck du joueur


void jouer_14(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//joue la carte 14
void jouer_15(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//joue la carte 15
void jouer_16(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//
void jouer_17(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//
void jouer_18(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//
void jouer_19(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//
void jouer_20(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//
void jouer_21(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//
void jouer_22(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y);//idem

int recup_du_deck(S_joueur jr[],int no_jr,int choix);//supprime la carte du deck et renvoie la valeur de la carte
void voir_l_ou_c(S_joueur jr,int x,int y);//permet de voir une ligne ou une colonne d'un joueur en particulier
int verif_carte_def(S_joueur jr);//vérifie qu'un joueur posède une carte défense, et ci cela est le cas renvoie sa postion dans le tableau des cartes actions du joueur, sinon elle renvoie 0.




#endif // CARTES_ACTIONS_H_INCLUDED
