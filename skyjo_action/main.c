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
#include "deroulement_tour.h"




int main()
{
    srand(time(NULL));
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    //plein_ecran();
    int nb_joueurs;
    nb_joueurs= afficher_menu_bienvenue();
    if (nb_joueurs==0)
        return 0;


    S_joueur jr[nb_joueurs];
    S_pioche p;




    afficher_plateau_vide(nb_joueurs);
    afficher_boite_dialogue();
    initialisation_generale (jr,&p,nb_joueurs,3,23);
    initalisation_debut_tour (&jr,&p,3,23);



    system("PAUSE");



}


