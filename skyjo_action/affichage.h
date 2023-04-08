#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

void afficher_menu_bienvenue (); //affiche le premier menu, affiché quand on lance le jeu.
void afficher_plateau_vide (); //affiche le squelette du plateau de jeu, identique pour chaque joueur
void afficher_actualiser_joueur (); //actualise les cartes du joueur, à faire à chaque modif de son jeu, ou bien à chaque changement de joueur
void afficher_actualiser_pioche (); //à acutualiser à chaque "piochage" de carte
void afficher_actualiser_infos (); //à acctualiser quand le score change ou que tour change

#endif // AFFICHAGE_H_INCLUDED
