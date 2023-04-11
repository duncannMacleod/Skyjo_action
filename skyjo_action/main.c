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


    S_joueur jr[nb_joueurs];
    S_pioche p;

    p.nombre_nb=130;
    p.action_nb=27;


    afficher_plateau_vide(nb_joueurs);

    Positionner_Curseur(0,25);

    system("PAUSE");

    afficher_plateau_des_autres(nb_joueurs);

    Positionner_Curseur(0,25);

    system("PAUSE");



}


