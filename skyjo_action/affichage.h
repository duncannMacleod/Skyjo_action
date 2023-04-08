#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "declaration.h"

int afficher_menu_bienvenue (); //affiche le premier menu, affiché quand on lance le jeu.
void afficher_plateau_vide (int nb_j); //affiche le squelette du plateau de jeu, identique pour chaque joueur
void afficher_actualiser_joueur (int nb_j, S_joueur jr); //actualise les cartes du joueur, à faire à chaque modif de son jeu, ou bien à chaque changement de joueur
void afficher_actualiser_pioche ();///attention jr et jr[] pas la m chose //à acutualiser à chaque "piochage" de carte
void afficher_actualiser_score (int nb_j, S_joueur jr[]); //à acctualiser quand le score change ou que tour change
void color (int couleurDuTexte, int couleurDuFond);
void Positionner_Curseur(int x, int y);
#endif // AFFICHAGE_H_INCLUDED
