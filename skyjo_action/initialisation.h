#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED


#include "declaration.h"


void initialisation_carte_nombre(S_pioche carte);//ici, il n'y a pas "tableau" cartes, carte comme variable est juste suffisant
void initialisation_carte_action(S_pioche carte);



void creation_profil_joueur(int nb_j, S_joueur jr[], S_pioche *p, int *a); //j'ai choisi jr car sinon sa fout la merde dans les boucles
void initilalisation_pioche_carte_action(int *b, S_pioche *p); //positionne les 4 cartes actions
void initialisation_defausse_nombre(S_pioche *p);



#endif // INITIALISATION_H_INCLUDED
