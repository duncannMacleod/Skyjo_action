#ifndef DEPLACEMENTS_CARTES_H_INCLUDED
#define DEPLACEMENTS_CARTES_H_INCLUDED

#include "declaration.h"
//ces fonctions ont du convertiationnel � l'int�rieur pour permettre de savoir quelle carte va o�...
void recup_carte_nombre_pioche(S_joueur *jr,S_pioche *p,int x,int y);  //s'occupe de d�placer la carte du dessus de la pioche vers le jeu du joueur et la retourne.
void recup_carte_nombre_defausse(S_joueur *jr,S_pioche *p,int x,int y);//s'occupe de d�placer la carte du dessus de la d�fausse vers le jeu du joueur et la retourne.
void recup_carte_action_presente(S_joueur *jr,S_pioche *p,int x,int y);//s'occupe de d�placer une des cartes parmis les 4 pr�sent�s vers le jeu du joueur et la retourne.
void recup_carte_action_pioche(S_joueur *jr,S_pioche *p,int x,int y);//s'occupe de d�placer la carte du dessus de la pioche des cartes actions vers le jeu du joueur et la retourne.
void recup_carte_action_defausse(S_joueur *jr,S_pioche *p,int x,int y);//s'occupe de d�placer la carte du dessus de la d�fausse des cartes actions vers le jeu du joueur et la retourne.
//fin fonctions convertiationnelles

int etoile_presente(S_joueur jr,int ligne, int colonne); //renvoie 1 si une �toile est pr�sente � une coordonn�e. attention ici les lignes vont de 0�2 et les colonnes de 0�3


void retourne_carte(S_joueur *jr,S_pioche *p,int x ,int y,int parametre,int carte_pioche1,int carte_pioche2,int carte_pioche3);//permet de retourner une carte dans le jeu du joueur, et de renvoyer 1,2ou3 carte dans la pioche
int tirer_carte(S_pioche *p);//permet de tirer une carte de la pioche des cartes nombres et de renvoyer la valeur de celle-ci
void demande_l_c (int *ligne,int *colonne,int x,int y);//fonction de conversation pemetant de renvoyer par adresse des valeurs (lignes et colonne)
void swap_carte(S_joueur *jr, S_pioche *p,int carte_pioche,int ligne,int colonne);//jette la carte remplac�e et la remplace dans le jeu du joueur par carte_pioche
void supprimer_pos_etoile (S_joueur *jr,int ligne,int colonne);//si une carte est pr�sente aux cordonn�es entr�es, le programme supprime cette information





void placer_carte_piochee(S_joueur *jr,S_pioche *p,int ligne, int colonne,int parametre); //param.=2 place les cartes sous la pioche
void deplacer_carte_jeu(S_joueur *j1,S_joueur *j2,int x1,int y1,int x2,int y2);
#endif // DEPLACEMENTS_CARTES_H_INCLUDED
