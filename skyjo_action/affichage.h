#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "declaration.h"

int afficher_menu_bienvenue ();                             //affiche le premier menu, affiché quand on lance le jeu.
void afficher_plateau_vide (int nb_j);                     //affiche le squelette du plateau de jeu, identique pour chaque joueur
void afficher_boite_dialogue();
void afficher_plateau_des_autres(int nb_j);        //pour savoir quelles sont les cartes des autres

void afficher_actualiser_joueur (S_joueur jr,int x,int y);        //actualise les cartes du joueur, à faire à chaque modif de son jeu, ou bien à chaque changement de joueur
void afficher_actualiser_score (int nb_j, S_joueur jr[]);       //à acctualiser quand le score change ou que tour change
void afficher_actualiser_pioche_action (S_pioche p);
void afficher_actualiser_jeu_des_autres(S_joueur jr[], int no_observateur,int nb_jr);


void afficher_actualiser_defausse_action (S_pioche p);
void afficher_actualiser_defausse_nombre (S_pioche p);  ///attention jr et jr[] pas la m chose //à acutualiser à chaque "piochage" de carte



void color (int couleurDuTexte, int couleurDuFond);
void Positionner_Curseur(int x, int y);
void plein_ecran();
#endif // AFFICHAGE_H_INCLUDED
