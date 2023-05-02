#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "declaration.h"

int afficher_menu_bienvenue ();                             //affiche le premier menu, affiché quand on lance le jeu.
void afficher_plateau_vide (int nb_jr);                     //affiche le squelette du plateau de jeu, identique pour chaque joueur
void afficher_boite_dialogue();
void afficher_plateau_des_autres(int nb_jr);        //pour savoir quelles sont les cartes des autres

void afficher_actualiser_joueur (S_joueur jr,int x,int y);        //actualise les cartes du joueur, à faire à chaque modif de son jeu, ou bien à chaque changement de joueur
void surligner_etoile(S_joueur jr,int x,int y);
void surligner_etoile_des_autres(S_joueur jr,int x,int y);


void afficher_actualiser_joueur_vision (S_joueur jr,int x,int y); //quasiment la même mais l'affichage est adapté pour "voir le jeu des autres"
void afficher_actualiser_score (int nb_jr, S_joueur jr[]);       //à acctualiser quand le score change ou que tour change
void afficher_actualiser_pioche_action (S_pioche p);
void afficher_actualiser_jeu_des_autres(S_joueur jr[],int no_observateur,int nb_jr);
void afficher_coups(S_joueur jr);

void recap_manche(S_joueur jr[], S_pioche p,int nb_jr,int x,int y,int parametre);
void afficher_dernier_tour(S_joueur jr[],int nb_jr);



void afficher_jeu_duo (S_joueur jr1,S_joueur jr2);
void afficher_haut_duo();


void afficher_actualiser_defausse_action (S_pioche p);
void afficher_actualiser_defausse_nombre (S_pioche p);  ///attention jr et jr[] pas la m chose //à acutualiser à chaque "piochage" de carte

void afficher_action(int nb);

void voir_deck_action(S_joueur jr,int x,int y,int parametre);


void color (int couleurDuTexte, int couleurDuFond);
void Positionner_Curseur(int x, int y);
void plein_ecran();
#endif // AFFICHAGE_H_INCLUDED
