#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "affichage.h"
#include "declaration.h"
#include "suivi_score.h"
#include "initialisation.h"




int main()
{
    srand(time(NULL));
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    int nb_joueurs;
    nb_joueurs= afficher_menu_bienvenue();
    if (nb_joueurs==0)
        return 0;
    int a=129; //depart de la derni�re case du tab des pioche.nombre
    int a2=0;  //depart de la premi�re case du tab des pioche.nombre_defausse
    int b=26;  //depar � la derni�re case du tab de pioche.action
    int b2=0;  //depart � la premi�re case du tab de pioche.action_def


    S_joueur jr[nb_joueurs];
    S_pioche p;
    afficher_plateau_vide(nb_joueurs);
    //initialisation_defausse_nombre(&p);
    //afficher_actualiser_defausse_nombre(p,a2);

    system("PAUSE");




}


