#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED


#include "declaration.h"

void initialisation_profil (S_joueur jr[], S_pioche *p, int nb_jr,int x,int y); //initialise les profils+les parametres initaux restant les memes suivant les manches
void initialisation_manche (S_joueur jr[], S_pioche *p, int nb_jr,int x,int y); //(ré)initialise le jeu pour une nouvelle manche

void initalisation_nb_cartes(S_pioche *p); //initialise le nombre de cartes dans les paquets

void initialisation_carte_nombre(S_pioche *p);//ici, il n'y a pas "tableau" cartes, carte comme variable est juste suffisant
void melanger_paquet_nombre(S_pioche*p);

void initialisation_carte_action(S_pioche*p);
void melanger_paquet_action(S_pioche*p);


void initalisation_joueur_deck(int nb_jr, S_joueur jr[], S_pioche *p,int x, int y); //initialise les decks des joueurs
void initalisation_tour_restant(S_pioche *p);//initialise le nb de tours restant a une valeur inoffensive



void creation_profil_joueur(int nb_jr, S_joueur jr[], S_pioche *p,int x, int y); //j'ai choisi jr car "j" fout la merde dans les boucles
void initalisation_nb_etoile(S_joueur jr[],int nb_jr);
void initalisation_nb_skyjo(S_joueur jr[],int nb_jr);
void initialisation_deck_nb_action(S_joueur jr[],int nb_jr);


void initialisation_score(int nb_jr,S_joueur jr[]);
void initialisation_pioche_carte_action( S_pioche *p); //positionne les 4 cartes actions
void initialisation_defausse_nombre(S_pioche *p);
void initialisation_defausse_action(S_pioche *p);
void initalisation_init_fin_manche(S_joueur jr[],int nb_jr);

void test_fin_pioche_n_et_a (S_pioche *p);

void remelange_carte_nombre(S_pioche *p);
void remelange_carte_action(S_pioche *p);


void premier_fin_manche(S_pioche *p);



#endif // INITIALISATION_H_INCLUDED
