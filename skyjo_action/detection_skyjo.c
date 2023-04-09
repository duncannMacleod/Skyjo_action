#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


#include "declaration.h"
#include "affichage.h"


void choix_skyjo () //si le joueur fait un skyjo sur son jeu, il peut chosir quoi faire
{
    char choix;
    //Positionner_Curseur(x,y);
    printf("Bonne nouvelle! Vous venez de faire un Skyjo! Que voulez vous faire ");
    //Positionner_Curseur(x,y+1);
    printf("( Supprimer les cartes:S, Garder les cartes:G )");
    //Positionner_Curseur(x,y+1);
    do
    {
        //Positionner_Curseur(x,y+2);
        scanf("%s",&choix);
        switch(toupper(choix))
        {
            case 'G':



            case 'S':


            default:
                printf("choix incorrect, veuillez recommencer");
                system("PAUSE");
                choix=0;

        }
    }
    while (choix==0);

}



