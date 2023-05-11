#ifndef DEROULEMENT_TOUR_H_INCLUDED
#define DEROULEMENT_TOUR_H_INCLUDED



#include "declaration.h"

void debut_tour (S_joueur jr[],int no_jr,int nb_jr, S_pioche *p,int x,int y);//initilalise le tour et propose les différents choix de jeu au joueur

void piocher_carte_nombre(S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y);//programme débutant les actions pour piocher une carte nombre
void piocher_carte_action(S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y);//programme débutant les actions pour piocher une carte nombre



void retourne_toutes_cartes(S_joueur jr[],int nb_jr);//progamme utilisé pour le debug
void met_toutes_cartes_0(S_joueur *jr);//progamme utilisé pour le debug


void regarder_jeu_des_autres(S_joueur jr[],int no_jr, int nb_jr, int x,int y,int parametre);//permet de voir un autre jeu que le sien


void atribuer_nbr_etoile(S_joueur *jr,S_pioche *p, int x, int y);//permet de modifier la valeur d'une carte etoile



#endif // DEROULEMENT_TOUR_H_INCLUDED
