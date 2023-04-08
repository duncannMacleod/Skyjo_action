#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

int afficher_menu_bienvenue (); //affiche le premier menu, affich� quand on lance le jeu.
void afficher_plateau_vide (int nb_j); //affiche le squelette du plateau de jeu, identique pour chaque joueur
void afficher_actualiser_joueur (); //actualise les cartes du joueur, � faire � chaque modif de son jeu, ou bien � chaque changement de joueur
void afficher_actualiser_pioche (); //� acutualiser � chaque "piochage" de carte
void afficher_actualiser_infos (); //� acctualiser quand le score change ou que tour change
void color (int couleurDuTexte, int couleurDuFond);
void Positionner_Curseur(int x, int y);
#endif // AFFICHAGE_H_INCLUDED
