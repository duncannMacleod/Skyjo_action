#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED


#include "declaration.h"

void creation_profil_joueur(int nb_j, S_joueur jr[], S_pioche p); //j'ai choisi jr car sinon sa fout la merde dans les boucles
void initialisation_carte_nombre(S_pioche carte);
void initialisation_carte_action(S_pioche carte);
void initialisation_carte_pioche(S_pioche carte);


#endif // INITIALISATION_H_INCLUDED
