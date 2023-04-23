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

void recup_carte_nombre_pioche(S_joueur *jr,S_pioche *p,int x,int y)
{
    int cpt,ligne=0,colonne=0,reponse;
    char choix,c;


    int carte_pioche=p->nombre[p->nombre_nb-1]; //la variable carte pioché prend la valeur de la première carte sur le paquet
    p->nombre[p->nombre_nb-1]=30; //supprime la carte du paquet
    p->nombre_nb--; //enlève un au nombre de cartes

    if(carte_pioche==13)
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de piocher une carte étoile, quelle est la valeur que vous voulez lui donner?");
        cpt+=2;
        printf("Réponse:"); scanf("%d",&reponse);
        carte_pioche=reponse;
    }

    do
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("Vous avez pioché une carte %d! Que voulez vous faire? ",carte_pioche);

        cpt+=1;Positionner_Curseur(x,y+cpt);
        printf("La Placer P, ou la jeter dans la Défausse D");
        cpt+=2;Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
        cpt+=2;Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'P'://place la carte dans le jeu
            printf("entrez les coordonnées de la nouvelle place pour la carte (ligne  espace colonne), ");
            cpt+=1;Positionner_Curseur(x,y+cpt);
            do{
                Positionner_Curseur(x,y+cpt);
                printf("Attention, ligne de 1 à 3 et colonne de 1 à 4:              ");
                Positionner_Curseur(x+46,y+cpt);
                scanf("%d %d",&ligne,&colonne);
                ligne--; colonne--;
            }while(ligne>3||ligne<0||colonne>4||colonne<0);
            p->nombre_defausse_nb++;
            p->nombre_defausse[p->nombre_defausse_nb-1]=jr->deck_nombre[ligne][colonne]; //écrit la valeur de la carte jetée dans la n-ième case de la défausse ici elles sont ajoutées de 0 à 120


            jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
            jr->deck_nombre_cache[ligne][colonne]=1; //retourne la carte tout juste déposé (l'état précédant de la case n'est pas pris en compte)

            choix=1;
            break;


        case 'D'://jete la carte dans la défausse
            printf("vous devez tout de même rerourner une carte. entrez les coordonées pour la carte");
            cpt+=1;Positionner_Curseur(x,y+cpt);
            do{
                Positionner_Curseur(x,y+cpt);
                printf("Attention, ligne de 1 à 3 et colonne de 1 à 4:              ");
                Positionner_Curseur(x+46,y+cpt);
                scanf("%d %d",&ligne,&colonne);
                ligne--;
                colonne--;
            } while(ligne>3||ligne<0||colonne>4||colonne<0);
            if(jr->deck_nombre[ligne][colonne]==13)
            {
                cpt=0;
                afficher_boite_dialogue();
                Positionner_Curseur(x,y);
                printf("vous venez de retourner une carte étoile, quelle est la valeur que vous voulez lui donner?");
                cpt++;
                Positionner_Curseur(x,y+cpt);
                printf("quelle est la valeur que vous voulez lui donner?");
                cpt+=2;
                Positionner_Curseur(x,y+cpt);
                printf("Réponse:");
                scanf("%d",&reponse);
                jr->deck_nombre[ligne][colonne]=reponse;
                jr->pos_etoile->ligne=ligne;
                jr->pos_etoile->colonne=colonne;

            }
            jr->deck_nombre_cache[ligne][colonne]=1;
            p->nombre_defausse_nb++;
            p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche; //écrit la valeur de la carte pioché dans la n-ième case de la défausse ici elles sont ajoutées de 0 à 120
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


    }while (choix==0);


}

void recup_carte_nombre_defausse(S_joueur *jr,S_pioche *p,int x,int y)
{
    int cpt,carte_pioche,ligne,colonne,reponse;
    carte_pioche=p->nombre_defausse[p->nombre_defausse_nb-1];

    p->nombre_defausse_nb--;
    if(p->nombre_defausse_nb==0)
        p->nombre_defausse[0]=30;
    afficher_actualiser_defausse_nombre(*p);

    if(carte_pioche==13)
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de récupérer une carte étoile, quelle est la valeur que vous voulez lui donner?");
        cpt+=2;
        printf("Réponse:"); scanf("%d",&reponse);
        carte_pioche=reponse;
    }

    cpt=0;
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Vous avez récupéré une carte %d! Que voulez vous faire ",carte_pioche);
    cpt+=2; Positionner_Curseur(x,y+cpt);
    printf("entrez les coordonnées de la nouvelle place pour la carte (ligne  espace colonne), ");
    cpt+=1;
    Positionner_Curseur(x,y+cpt);
    do
    {
        Positionner_Curseur(x,y+cpt);
        printf("Attention, ligne de 1 à 3 et colonne de 1 à 4:              ");
        Positionner_Curseur(x+46,y+cpt);
        scanf("%d %d",&ligne,&colonne);
        ligne--;
        colonne--;
    }
    while(ligne>3||ligne<0||colonne>4||colonne<0);
    p->nombre_defausse_nb++;
    p->nombre_defausse[p->nombre_defausse_nb-1]=jr->deck_nombre[ligne][colonne]; //écrit la valeur de la carte jetée dans la n-ième case de la défausse ici elles sont ajoutées de 0 à 120


    jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
    jr->deck_nombre_cache[ligne][colonne]=1; //retourne la carte tout juste déposé (l'état précédant de la case n'est pas pris en compte)
}
