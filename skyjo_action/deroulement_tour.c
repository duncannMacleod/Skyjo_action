#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


#include "deroulement_tour.h"
#include "declaration.h"
#include "affichage.h"

void initalisation_debut_tour (S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y)
{
    char choix,c;
    int cpt;
    int action=0; //permet de savoir si le joueur à déjà joué, et lui limiter alors qu'à regarder les cartes des autres ou terminer son tour



    do
    {
        afficher_plateau_vide(nb_jr);
        afficher_actualiser_joueur(jr[no_jr],12,3); //affiche le prenom du joueur, et ces cartes.
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
                //piocher_carte_nombre();
                printf("pas encore codé");
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

    int cpt=0,c;
    char rep;
    afficher_actualiser_jeu_des_autres(jr,no_jr,nb_jr);
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Voici le jeu des autres joureurs, pour revenir, entrez R."); cpt++;
    Positionner_Curseur(x,y+cpt);
    do{
        printf("Réponse:");
        scanf("%c",&rep);
        while ((c = getchar()) != '\n' && c != EOF);
        toupper(rep);
    }while(rep!='R');


}
