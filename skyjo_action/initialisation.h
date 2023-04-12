#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED


#include "declaration.h"

 void initialisation_generale (S_joueur jr[], S_pioche *p, int nb_j,int x,int y); //reprend tout les progammes en séquence
 void initalisation_nb_cartes(S_pioche *p); //initialise le nombre de cartes dans les paquets



 void initialisation_carte_nombre(S_pioche carte);//ici, il n'y a pas "tableau" cartes, carte comme variable est juste suffisant
 void initialisation_carte_action(S_pioche carte);



 void creation_profil_joueur(int nb_j, S_joueur jr[], S_pioche *p,int x, int y); //j'ai choisi jr car sinon sa fout la merde dans les boucles
 void initialisation_pioche_carte_action( S_pioche *p); //positionne les 4 cartes actions
 void initialisation_defausse_nombre(S_pioche *p);
void initialisation_defausse_action(S_pioche *p);



#endif // INITIALISATION_H_INCLUDED
