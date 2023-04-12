#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


#include "deroulement_tour.h"
#include "declaration.h"
#include "affichage.h"



void initalisation_debut_tour (S_joueur *jr, S_pioche *p, int x, int y)
{
    char choix;
    int cpt=0;
    afficher_actualiser_joueur(*jr); //affiche le prenom du joueur, et ces cartes.
    afficher_boite_dialogue();  //permet de réinitiliser la boite de dialogue, enlevant les anciens messages
    printf("C'est le tour de "); puts(jr->prenom);
    Positionner_Curseur(20+strlen(jr->prenom),y);
    printf("! Que voulez vous faire?");
    cpt+=2; Positionner_Curseur(x,y+cpt);
    printf("Voir le jeu des autres V, Piocher une carte nombre N, Piocher une carte Action A");
    cpt++;Positionner_Curseur(x,y+cpt);
    printf("et jouer une carte action J.");
    cpt+=2;Positionner_Curseur(x,y+cpt);

    do
    {
        printf("Réponse:");
        scanf("%s",&choix);
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'V':
            //regarder_jeu_des_autres();
            break;


        case 'N':
            //piocher_carte_nombre();
            break;

        case 'A':
            //piocher_carte_action();
            break;

        case 'J':
            //jouer_carte_action();
            break;

        default:
            printf("choix incorrect, veuillez recommencer");
            choix=0;
            break;
        }
        cpt++;
        Positionner_Curseur(x,y+cpt);
    }
    while (choix==0);
}
