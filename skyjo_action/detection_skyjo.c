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
    int cpt,c;

    do
    {
        cpt=0;
        Positionner_Curseur(x,y);
        printf("Bonne nouvelle! Vous venez de faire un Skyjo! Que voulez vous faire ?");
        cpt++; Positionner_Curseur(x,y+cpt);
        printf(" Supprimer les cartes S, Garder les cartes G");
        cpt++; Positionner_Curseur(x,y+cpt);

        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
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

}//choix garder->1; choix supprimer->0;



