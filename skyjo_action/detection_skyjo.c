#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


#include "declaration.h"
#include "affichage.h"


int choix_skyjo (int x, int y) //si le joueur fait un skyjo sur son jeu, il peut chosir quoi faire
{
    char choix;
    Positionner_Curseur(x,y);
    printf("Bonne nouvelle! Vous venez de faire un Skyjo! Que voulez vous faire ");
    Positionner_Curseur(x,y+1);
    printf("( Supprimer les cartes:S, Garder les cartes:G )");
    Positionner_Curseur(x,y+1);
    do
    {
        //Positionner_Curseur(x,y+2);
        scanf("%s",&choix);
        switch(toupper(choix))
        {
            case 'G':
                return 0;
                break;


            case 'S':
                return 1;
                break;

            default:
                printf("choix incorrect, veuillez recommencer");
                system("PAUSE");
                choix=0;
                break;

        }
    }
    while (choix==0);
    return 0;

}



