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
    int a=129; //depart de la dernière case du tab des pioche.nombre
    int a2=0;  //depart de la première case du tab des pioche.nombre_defausse
    int b=26;  //depar à la dernière case du tab de pioche.action
    int b2=0;  //depart à la première case du tab de pioche.action_def


    S_joueur jr[nb_joueurs];
    S_pioche p;
    afficher_plateau_vide(nb_joueurs);

    Positionner_Curseur(0,25);

    system("PAUSE");

    afficher_plateau_des_autres(nb_joueurs);

    Positionner_Curseur(0,25);

    system("PAUSE");



}


