#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "affichage.h"
#include "declaration.h"




int main()
{
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    int nb_joueurs;
    nb_joueurs= afficher_menu_bienvenue();
    if (nb_joueurs==0)
        return 0;
    S_joueur j[nb_joueurs];
    //initilalisation des cartes
     afficher_plateau_vide (nb_joueurs);
     system("PAUSE");

}


