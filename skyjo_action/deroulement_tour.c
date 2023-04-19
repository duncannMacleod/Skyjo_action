#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


#include "deroulement_tour.h"
#include "declaration.h"
#include "affichage.h"
#include "deplacements_cartes.h"

void initalisation_debut_tour (S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y)
{
    char choix,c;
    int cpt;
    int action=0; //permet de savoir si le joueur à déjà joué, et lui limiter alors qu'à regarder les cartes des autres ou terminer son tour



    do
    {
        afficher_plateau_vide(nb_jr);
        afficher_actualiser_joueur(jr[no_jr-1],12,3); //affiche le prenom du joueur, et ces cartes.
        afficher_boite_dialogue();  //permet de réinitiliser la boite de dialogue, enlevant les anciens messages
        afficher_actualiser_score(nb_jr,jr);
        afficher_actualiser_defausse_action(*p);
        afficher_actualiser_defausse_nombre(*p);
        afficher_actualiser_pioche_action(*p);


        cpt=0;
        Positionner_Curseur(x,y+cpt);
        printf("C'est le tour de "); puts(jr[no_jr-1].prenom);
        Positionner_Curseur(20+strlen(jr[no_jr-1].prenom),y);
        printf("! Que voulez vous faire?");
        cpt+=2; Positionner_Curseur(x,y+cpt);
        printf("Voir le jeu des autres V, Piocher une carte nombre N, Piocher une carte Action A");
        cpt++;Positionner_Curseur(x,y+cpt);
        printf("et jouer une carte action J, Terminer son tour T.");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'V':
                regarder_jeu_des_autres(jr,no_jr,nb_jr,x,y);
                choix=0;
            break;


        case 'N':
            if (action==0)
                piocher_carte_nombre(jr,no_jr,nb_jr,*p,3,23);
            else if (action>0)
                printf("vous avez déja joué");
            cpt++;
            Positionner_Curseur(x,y+cpt);
            system("pause");

            action++;
            choix=0;
            break;

        case 'A':
            if (action==0)
                //piocher_carte_action();
                printf("pas encore codé");
            else if (action>0)
                printf("vous avez déja joué");
            cpt++;
            Positionner_Curseur(x,y+cpt);
            system("pause");
            action++;
            choix=0;
            break;

        case 'J':
            if (action==0)
                //jouer_carte_action();
                printf("pas encore codé");
            else if (action>0)
                printf("vous avez déja joué");
            cpt++;
            Positionner_Curseur(x,y+cpt);
            system("pause");
            action++;
            choix=0;
            break;

        case 'T': //terminer son tour.

            break;


        default:
            cpt++;
            choix=0;
            printf("choix incorrect, veuillez recommencer");
            Positionner_Curseur(x,y+cpt);
            system("pause");
            break;
        }

    }
    while (choix==0);

}

void regarder_jeu_des_autres(S_joueur jr[],int no_jr,int nb_jr, int x,int y)
{
    afficher_actualiser_jeu_des_autres(jr,no_jr,nb_jr);
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Voici le jeu des autres joureurs");
    Positionner_Curseur(x,y+2);
    system("pause");


}
void piocher_carte_nombre(S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y)
{
    char choix,c;
    do
    {

        int cpt=0;

        afficher_boite_dialogue();
        printf("Piocher une carte nombre: ");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Piocher une carte de la pioche P ou piocher une carte de la défausse D");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'P'://piocher une carte de la pioche (cachée)
            recup_carte_nombre_pioche(&jr[no_jr-1],p,x,y);
            choix=1;
            break;


        case 'D'://piocher une carte de la défausse (visible)
            // void recup_carte_nombre_défausse
            choix=1;
            break;
        default:
            choix=0;
            cpt++; Positionner_Curseur(x,y+cpt);
            printf("choix incorrect, veuillez recommencer");
            cpt++; Positionner_Curseur(x,y+cpt);
            system("pause");
            break;
        }

    }
    while (choix==0);

}

void piocher_carte_action(S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y)
{
    char choix,c;
    do
    {

        int cpt=0;

        afficher_boite_dialogue();
        printf("Piocher une carte action: ");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Piocher une carte des 4 présentés P. ou piocher une carte de la défausse D.");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'P'://piocher une carte parmis les 4 présentés
            // int recup_carte_defausse
            choix=1;
            break;


        case 'D'://piocher une carte de la défausse
            // int recup_carte_defausse
            choix=1;
            break;
        default:
            choix=0;
            cpt++; Positionner_Curseur(x,y+cpt);
            printf("choix incorrect, veuillez recommencer");
            cpt++; Positionner_Curseur(x,y+cpt);
            system("pause");
            break;
        }

    }
    while (choix==0);

}
