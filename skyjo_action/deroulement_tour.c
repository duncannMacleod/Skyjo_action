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
#include "detection_skyjo.h"

void debut_tour (S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y)
{
    char choix,c, cache[5];
    int cpt;
    int action=0; //permet de savoir si le joueur à déjà joué, et lui limiter alors qu'à regarder les cartes des autres ou terminer son tour



    do
    {
        detection_skyjo(nb_jr,jr);
        afficher_plateau_vide(nb_jr);
        afficher_actualiser_joueur(jr[no_jr-1],12,3); //affiche le prenom du joueur, et ces cartes.
        afficher_boite_dialogue();  //permet de réinitiliser la boite de dialogue, enlevant les anciens messages
        afficher_actualiser_score(nb_jr,jr); //A. (actualise) le score
        afficher_actualiser_defausse_action(*p); //A. les défausses
        afficher_actualiser_defausse_nombre(*p);//idem
        afficher_actualiser_pioche_action(*p); //réaffiche les cartes actions



        cpt=0;
        Positionner_Curseur(x,y+cpt);
        printf("C'est le tour de "); puts(jr[no_jr-1].prenom); //affiche le nom du joueur 	1,2,3 ou 4
        Positionner_Curseur(20+strlen(jr[no_jr-1].prenom),y); //conversationnel
        printf("! Que voulez vous faire?");
        cpt+=2; Positionner_Curseur(x,y+cpt);
        printf("Voir le jeu des autres V, Piocher une carte nombre N, Piocher une carte Action A");
        cpt++;Positionner_Curseur(x,y+cpt);
        printf("et jouer une carte action J, Affecter un nbr à une étoile E, Terminer son tour T.");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:"); //fin conversationnel
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);//permet d'effacer la mémoire tampon,
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'V':
                regarder_jeu_des_autres(jr,no_jr,nb_jr,x,y);
                choix=0;
            break;



        case 'N':
            if (action==0)
                piocher_carte_nombre(jr,no_jr,nb_jr,p,3,23);
            else if (action>0)
                printf("vous avez déja joué");
            cpt+=2;
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

        case 'E':

            atribuer_nbr_etoile(&jr[no_jr-1],p,x,y);
            cpt++;
            Positionner_Curseur(x,y+cpt);
            system("pause");
            choix=0;
            break;
        case 'T': //terminer son tour.

            break;
        case 10:
            choix=0;
            break;

        default:
            cpt++;
            choix=0;
            printf("choix incorrect, veuillez recommencer ");
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
            if(p->nombre_defausse_nb==0)
                printf("il n'y a pas de carte dans la défausse");
            else
                recup_carte_nombre_defausse(&jr[no_jr-1],p,x,y);
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
    getchar();

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
        getchar();


}

void atribuer_nbr_etoile(S_joueur *jr,S_pioche *p, int x, int y)
{

    int cpt=0,ligne,colonne,reponse;

    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Quelle est la coordonnée de l'étoile? (ligne 1à3 esp. colonne 1à4)");
    cpt++;
    Positionner_Curseur(x,y+cpt);
    printf("Réponse:");
    scanf("%d %d",&ligne,&colonne);
    if(jr->deck_nombre[ligne-1][colonne-1]==13)
    {
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("étoile trouvée, par quel nb. la remplacer?");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("Réponse: ");
        scanf("%d",&reponse);
        jr->deck_nombre[ligne-1][colonne-1]=reponse;
        jr->nb_etoile++;
        jr->pos_etoile->ligne=ligne-1;
        jr->pos_etoile->colonne=colonne-1;
    }
    else
    {
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("Erreur, étoile non trouvé");
    }
    getchar();

}

void retourne_toutes_cartes(S_joueur jr[],int nb_jr)
{
    int i,a,b;
    for(i=0;i<nb_jr;i++)
    {
        for(a=0;a<CARTE_JOUEUR_NOMBRE_L;a++)
            for(b=0;b<CARTE_JOUEUR_NOMBRE_C;b++)
        {
            jr[i].deck_nombre[a][b]=1;
        }
    }
}
