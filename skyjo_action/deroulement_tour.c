#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>


#include "deroulement_tour.h"
#include "declaration.h"
#include "affichage.h"
#include "deplacements_cartes.h"
#include "detection_skyjo.h"
#include "cartes_actions.h"
#include "suivi_score.h"


void debut_tour (S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y)
{
    char choix,c;
    int cpt;
    jr[no_jr-1].nb_coups=1; //permet de savoir si le joueur à déjà joué, et lui limiter alors qu'à regarder les cartes des autres ou terminer son tour



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
        afficher_coups(jr[no_jr-1]);
        afficher_dernier_tour(jr,nb_jr);




        cpt=0;
        Positionner_Curseur(x,y+cpt);
        printf("C'est le tour de "); puts(jr[no_jr-1].prenom); //affiche le nom du joueur 	1,2,3 ou 4
        Positionner_Curseur(20+strlen(jr[no_jr-1].prenom),y); //conversationnel
        printf("! Que voulez vous faire?");
        cpt+=2; Positionner_Curseur(x,y+cpt);
        printf("Voir le jeu des autres V, Piocher une carte nombre N, Piocher une carte Action A");
        cpt++;Positionner_Curseur(x,y+cpt);
        printf("Jouer d'une carte action J, Affecter un nbr à une étoile E, Terminer son tour T");
        cpt++;Positionner_Curseur(x,y+cpt);
        printf("Voir son deck de carte Action D ou voir le deck action des autres F.");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:"); //fin conversationnel
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);//permet d'effacer la mémoire tampon,
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix)) //toupper permet de metre le caractère en majuscule
        {
        case 'V':
                regarder_jeu_des_autres(jr,no_jr,nb_jr,x,y); //programme affiche le jeu des autres joueurs, il est donc impératif de savoir quel joueur execute le code pour ne pas l'afficher
                choix=0;
                system("pause");
            break;


        case 'D': //voir son deck de carte action
            voir_deck_action(jr[no_jr-1],x,y,1);
            choix=0;
            break;


        case 'N'://piocher une carte nombre
            if (jr[no_jr-1].nb_coups>0)//permet au joueur de ne pas jouer plusieurs fois
            {
                 piocher_carte_nombre(jr,no_jr,nb_jr,p,x,y);//progamme permetant de commencer le processus de pioche
                 jr[no_jr-1].nb_coups--; //pemet de ne pas rejouer
            }


            else if (jr[no_jr-1].nb_coups==0)
            {
                printf("vous avez déja joué");
                Positionner_Curseur(x,y+8);
            }
            system("pause");

            choix=0; //permet de rester dans la boucle (ne change pas de joueur)

            break;

        case 'A': //piocher une carte action
            cpt=0;
            if (jr[no_jr-1].nb_coups>0)
            {
                piocher_carte_action(jr,no_jr,nb_jr,p,x,y);
                //jr[no_jr-1].nb_coups--; //permet de ne pas rejouer
            }

            else if (jr[no_jr-1].nb_coups==0)
            {
                printf("vous avez déja joué");
                Positionner_Curseur(x,y+8);
                system("pause");
            }


            choix=0; //permet de rester dans la boucle (ne change pas de joueur)
            break;
        case 'J': //jouer carte action
            cpt=0;
            if (jr[no_jr-1].nb_coups>0)
            {
                if (jr[no_jr-1].nb_action>0)
                {
                    choix_carte_a_jouer(jr,p,no_jr,nb_jr,x,y);
                    jr[no_jr-1].nb_coups--;
                }
                else if(jr[no_jr-1].nb_action==0)
                    voir_deck_action(jr[no_jr-1],x,y,1);
            }

            else if (jr[no_jr-1].nb_coups==0)
            {
                printf("vous avez déja joué");
                Positionner_Curseur(x,y+8);
                system("pause");
            }

             //permet de ne pas rejouer
            choix=0; //permet de rester dans la boucle (ne change pas de joueur)
            break;

        case 'E': //permet de modifier la valeur d'une étoile

            atribuer_nbr_etoile(&jr[no_jr-1],p,x,y);//porgramme d'atribution
            cpt++;
            Positionner_Curseur(x,y+cpt);
            system("pause");
            choix=0; //permet de rester dans la boucle (ne change pas de joueur)
            break;

        case 'S':
            retourne_toutes_cartes(jr,nb_jr);
            choix=0;
            Positionner_Curseur(x,y+cpt);
            system("pause");
            break;
        case '&':
            met_toutes_cartes_0(&jr[no_jr-1]);
            choix=0;
            Positionner_Curseur(x,y+cpt);
            system("pause");
            break;
        case 'F':
            voir_deck_action_des_autres(jr,nb_jr,no_jr,x,y);
            choix=0;
            break;

        case 'T': //terminer son tour.

            break;

        default:
            cpt++;
            choix=0; //permet de rester dans la boucle (ne change pas de joueur)
            printf("choix incorrect, veuillez recommencer ");
            Positionner_Curseur(x,y+cpt);
            system("pause");
            break;
        }

    }
    while (choix==0);
    test_premier_fin_manche(&jr[no_jr-1],nb_jr,p);
    test_fin_pioche_n_et_a (p);



}

void regarder_jeu_des_autres(S_joueur jr[],int no_jr,int nb_jr, int x,int y)
{
    afficher_actualiser_jeu_des_autres(jr,no_jr,nb_jr); //affiche le jeu des autres joueurs
    afficher_boite_dialogue(); //réinitilise la boite de dialogue
    Positionner_Curseur(x,y);
    printf("Voici le jeu des autres joureurs");
    Positionner_Curseur(x,y+2);



}
void piocher_carte_nombre(S_joueur jr[],int no_jr,int nb_jr, S_pioche *p, int x, int y)
{
    char choix,c;
    do
    {

        int cpt=0;

        afficher_boite_dialogue(); //réinitilise la boite de dialogue
        printf("Piocher une carte nombre: ");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Piocher une carte de la pioche P ou piocher une carte de la défausse D");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix)) //permet de mettre la lettre en majuscule
        {
        case 'P'://piocher une carte de la pioche (cachée)
            recup_carte_nombre_pioche(&jr[no_jr-1],p,x,y); //deplacements_cartes.c
            choix=1;
            break;
        case 'D'://piocher une carte de la défausse (visible)
            if(p->nombre_defausse_nb==0)
                printf("il n'y a pas de carte dans la défausse");
            else
                recup_carte_nombre_defausse(&jr[no_jr-1],p,x,y); //deplacements_cartes.c
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

        afficher_boite_dialogue(); //réinitilise la boite de dialogue
        printf("Piocher une carte action: ");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Piocher une carte des 4 présentés P, ou piocher une carte de la défausse D.");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF); //efface la mémoire tampon
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix)) //met le caractère donnée en majuscule
        {
        case 'P'://piocher une carte parmis les 4 présentés
            recup_carte_action_presente(&jr[no_jr-1],p,x,y);
            choix=1;
            break;
        case 'D'://piocher une carte de la défausse
            recup_carte_action_pioche(&jr[no_jr-1],p,x,y);
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

    afficher_boite_dialogue(); //réinitialise l'affichage
    Positionner_Curseur(x,y);
    printf("Quelle est la coordonnée de l'étoile? (ligne 1à3 esp. colonne 1à4)"); //conversationnel
    cpt++;
    Positionner_Curseur(x,y+cpt);
    printf("Réponse:"); //fin conversationnel
    scanf("%d %d",&ligne,&colonne); //récupère les coordonnés donné par l'utilisateur
    if(jr->deck_nombre[ligne-1][colonne-1]==13) //si les coordonnés correspondent à une étoile pas encore enregistré (elle dispose encore de sa valeur 13)
    {
        cpt+=2;							//conversationnel
        Positionner_Curseur(x,y+cpt);
        printf("étoile trouvée, par quel nb. la remplacer?");
        cpt++;
        Positionner_Curseur(x,y+cpt); //fin conversationnel
       do{
                Positionner_Curseur(x,y+cpt);
                printf("                         ");//permet d'effacer ce qu'il avait été écrit sur la ligne avant
                Positionner_Curseur(x,y+cpt);
                printf("Réponse: ");
                scanf("%d",&reponse);
        }while(reponse>12||reponse<-2); //tant que le nombre qui va remplacer l'étoile est compris entre -2 et 12
        jr->deck_nombre[ligne-1][colonne-1]=reponse; //remplace le numéro 13 de l'étoile par le numéro entré par l'utilisateur
        jr->nb_etoile++; //incrémente 1 au nombre d'étoile dans le jeu du joueur
        jr->pos_etoile[jr->nb_etoile-1].ligne=ligne-1; //enregistre dans le tableau des etoiles la position de l'étoile
        jr->pos_etoile[jr->nb_etoile-1].colonne=colonne-1; //idem
    }
    else if(etoile_presente(*jr,ligne-1,colonne-1)) //si une étoile déja enregistré dans les données
    {
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("étoile trouvée, par quel nb. la remplacer?");
        cpt++;
        Positionner_Curseur(x,y+cpt);

        do{
                Positionner_Curseur(x,y+cpt);
                printf("                         ");
                Positionner_Curseur(x,y+cpt);
                printf("Réponse: ");
                scanf("%d",&reponse);
        }while(reponse>12||reponse<-2); //meme chose que ci-dessus

        jr->deck_nombre[ligne-1][colonne-1]=reponse; //enregiste la nouvelle valeur de la carte, n'enregistre pas une nouvelle etoile, car celle ci est deja enregisté

    }
    else
    {
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("Erreur, étoile non trouvé"); //conversationnel
    }
    getchar(); //permet d'effacer la mémoire tampon

}

void retourne_toutes_cartes(S_joueur jr[],int nb_jr) //progamme utilisé pour le décompte des points.
{
    int i,a,b;
    for(i=0;i<nb_jr;i++)
    {
        for(a=0;a<CARTE_JOUEUR_NOMBRE_L;a++)
            for(b=0;b<CARTE_JOUEUR_NOMBRE_C;b++)
        {
            jr[i].deck_nombre_cache[a][b]=1;
        }
    }
}



void met_toutes_cartes_0(S_joueur *jr)
{
    int a,b;


        for(a=0;a<CARTE_JOUEUR_NOMBRE_L;a++)
            for(b=0;b<CARTE_JOUEUR_NOMBRE_C;b++)
        {
            jr->deck_nombre[a][b]=rand()%4;
        }
}
