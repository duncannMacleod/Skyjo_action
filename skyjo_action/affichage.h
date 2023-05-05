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
void afficher_actualiser_pioche_action (S_pioche p); //affiche la pioche des cartes actions
void afficher_actualiser_jeu_des_autres(S_joueur jr[],int no_observateur,int nb_jr);//affiche le jeu des autres (en appuyant sur v)
void afficher_coups(S_joueur jr);//affiche les coups restants au joueur

void recap_manche(S_joueur jr[], S_pioche p,int nb_jr,int x,int y,int parametre); //permet d'afficher les principales informations de fin de manche et permet d'actualistion des profils des joueurs
void afficher_dernier_tour(S_pioche p,int nb_jr);//affiche un en surbrillance le fait qu'il ne reste d'un seul tour de plateau
void recap_fin_partie(S_joueur jr[],int nb_jr,int x,int y);//permet d'afficher les principales informations de fin de partie



void afficher_haut_duo();//permet d'initilialiser d'affichage de la portion haute de la console
void afficher_jeu_duo (S_joueur jr1,S_joueur jr2);//affiche le jeu d'un joueur(jr1) et d'un autre (jr2)



void afficher_actualiser_defausse_action (S_pioche p); 	//affiche le défausse des cartes actions
void afficher_actualiser_defausse_nombre (S_pioche p);  //affiche le défausse des cartes nombre ///attention jr et jr[] pas la m chose 

void afficher_action(int nb);//permet de convertir le numéro de la carte action en texte (l'affiche directement)

void voir_deck_action(S_joueur jr,int x,int y,int parametre); //permet de voir son deck de carte action
void voir_deck_action_des_autres(S_joueur jr[],int nb_jr,int no_jr,int x,int y);//permet de voir le deck action des autres joueurs


void color (int couleurDuTexte, int couleurDuFond);//permet de modifier la couleur du texte
void Positionner_Curseur(int x, int y);//postionne le curseur au cordonnées entrées
void plein_ecran();//passe la console en plein écran
#endif // AFFICHAGE_H_INCLUDED
