#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

void afficher_menu_bienvenue (); //affiche le premier menu, affich� quand on lance le jeu.
void afficher_plateau_vide (); //affiche le squelette du plateau de jeu, identique pour chaque joueur
void afficher_actualiser_joueur (); //actualise les cartes du joueur, � faire � chaque modif de son jeu, ou bien � chaque changement de joueur
void afficher_actualiser_pioche (); //� acutualiser � chaque "piochage" de carte
void afficher_actualiser_infos (); //� acctualiser quand le score change ou que tour change

#endif // AFFICHAGE_H_INCLUDED
