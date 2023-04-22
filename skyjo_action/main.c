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
    int nb_joueurs,i;
    nb_joueurs= afficher_menu_bienvenue();
    if (nb_joueurs==0)
        return 0;


    S_joueur jr[nb_joueurs];
    S_pioche p;




    afficher_plateau_vide(nb_joueurs);
    afficher_boite_dialogue();
    initialisation_generale (jr,&p,nb_joueurs,3,23);
    do{
    for(i=1;i<nb_joueurs+1;i++)
        initalisation_debut_tour (jr,i,nb_joueurs,&p,3,23);
    }while(test_fin_partie(jr,nb_joueurs)==0);




    system("PAUSE");



}


