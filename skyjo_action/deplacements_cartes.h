#ifndef DEPLACEMENTS_CARTES_H_INCLUDED
#define DEPLACEMENTS_CARTES_H_INCLUDED

#include "declaration.h"

void recup_carte_nombre_pioche(S_joueur *jr,S_pioche *p,int x,int y);  //s'occupe de déplacer la carte du dessus de la pioche vers le jeu du joueur et la retourne.
void recup_carte_nombre_defausse(S_joueur *jr,S_pioche *p,int x,int y);
int etoile_presente(S_joueur jr,int ligne, int colonne);

void recup_carte_action_presente(S_joueur *jr,S_pioche *p,int x,int y);
void recup_carte_action_pioche(S_joueur *jr,S_pioche *p,int x,int y);
void recup_carte_action_defausse(S_joueur *jr,S_pioche *p,int x,int y);

void retourne_carte(S_joueur *jr,S_pioche *p,int x ,int y,int parametre,int carte_pioche1,int carte_pioche2,int carte_pioche3);
int tirer_carte(S_pioche *p);
void demande_l_c (int *ligne,int *colonne,int x,int y);
void swap_carte(S_joueur *jr, S_pioche *p,int carte_pioche,int ligne,int colonne);
void supprimer_pos_etoile (S_joueur *jr,int ligne,int colonne);





void placer_carte_piochee(S_joueur *jr,S_pioche *p,int ligne, int colonne,int parametre); //param.=2 place les cartes sous la pioche
void deplacer_carte_jeu(S_joueur *j1,S_joueur *j2,int x1,int y1,int x2,int y2);
#endif // DEPLACEMENTS_CARTES_H_INCLUDED
