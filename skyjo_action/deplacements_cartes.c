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
    int cpt,ligne=0,colonne=0,reponse,etoile_recuperee=0;
;
    char choix,c;


    int carte_pioche=p->nombre[p->nombre_nb-1]; //la variable carte pioch� prend la valeur de la premi�re carte sur le paquet
    p->nombre[p->nombre_nb-1]=30; //supprime la carte du paquet
    p->nombre_nb--; //enl�ve un au nombre de cartes

    if(carte_pioche==13)
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de piocher une carte �toile,");
        printf("quelle est la valeur que vous voulez lui donner?");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("R�ponse:");
        scanf("%d",&reponse);
        carte_pioche=reponse;
        etoile_recuperee=1;

    }

    do
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("Vous avez pioch� une carte %d! Que voulez vous faire? ",carte_pioche);

        cpt+=1;
        Positionner_Curseur(x,y+cpt);
        printf("La Placer P, ou la jeter dans la D�fausse D");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("R�ponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'P'://place la carte dans le jeu
            printf("entrez les coordonn�es de la nouvelle place pour la carte (ligne  espace colonne), ");
            cpt+=1;
            Positionner_Curseur(x,y+cpt);
            do
            {
                Positionner_Curseur(x,y+cpt);
                printf("Attention, ligne de 1 � 3 et colonne de 1 � 4:              ");
                Positionner_Curseur(x+46,y+cpt);
                scanf("%d %d",&ligne,&colonne);
                ligne--;
                colonne--;
            }
            while(ligne>3||ligne<0||colonne>4||colonne<0);
            if(etoile_presente(&jr,colonne,ligne)==1)//si la carte qui va etre jet� est une ancienne carte �toile, elle reprend son �tat initial "13"
                jr->deck_nombre[ligne][colonne]=13;
            if(etoile_recuperee==1)
            {
                jr->nb_etoile++;
                jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;
                jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;
            }
            p->nombre_defausse_nb++;
            p->nombre_defausse[p->nombre_defausse_nb-1]=jr->deck_nombre[ligne][colonne]; //�crit la valeur de la carte jet�e dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120


            jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
            jr->deck_nombre_cache[ligne][colonne]=1; //retourne la carte tout juste d�pos� (l'�tat pr�c�dant de la case n'est pas pris en compte)


            choix=1;
            break;


        case 'D'://jete la carte dans la d�fausse
            printf("vous devez tout de m�me rerourner une carte. entrez les coordon�es pour la carte");
            cpt+=1;
            Positionner_Curseur(x,y+cpt);
            do
            {
                Positionner_Curseur(x,y+cpt);
                printf("Attention, ligne de 1 � 3 et colonne de 1 � 4:              ");
                Positionner_Curseur(x+46,y+cpt);
                scanf("%d %d",&ligne,&colonne);
                ligne--;
                colonne--;
            }
            while(ligne>3||ligne<0||colonne>4||colonne<0);
            if(jr->deck_nombre[ligne][colonne]==13)
            {
                cpt=0;
                afficher_boite_dialogue();
                Positionner_Curseur(x,y);
                printf("vous venez de retourner une carte �toile, quelle est la valeur que vous voulez lui donner?");
                cpt++;
                Positionner_Curseur(x,y+cpt);
                printf("quelle est la valeur que vous voulez lui donner?");
                cpt+=2;
                Positionner_Curseur(x,y+cpt);
                printf("R�ponse:");
                scanf("%d",&reponse);
                jr->deck_nombre[ligne][colonne]=reponse;
                jr->nb_etoile++;
                jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;
                jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;
            }
            jr->deck_nombre_cache[ligne][colonne]=1;
            p->nombre_defausse_nb++;
            p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche; //�crit la valeur de la carte pioch� dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120
            choix=1;
            break;
        default:
            choix=0;
            cpt++;
            Positionner_Curseur(x,y+cpt);
            printf("choix incorrect, veuillez recommencer");
            cpt++;
            Positionner_Curseur(x,y+cpt);
            system("pause");
            break;
        }


    }
    while (choix==0);


}

void recup_carte_nombre_defausse(S_joueur *jr,S_pioche *p,int x,int y)
{
    int cpt,carte_pioche,ligne,colonne,reponse,etoile_recuperee=0;
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
        printf("vous venez de r�cup�rer une carte �toile,");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf(" quelle est la valeur que vous voulez lui donner?");
        printf("R�ponse:");
        scanf("%d",&reponse);
        carte_pioche=reponse;
        etoile_recuperee=1;
    }

    cpt=0;
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Vous avez r�cup�r� une carte %d! Que voulez vous faire ",carte_pioche);
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    printf("entrez les coordonn�es de la nouvelle place pour la carte (ligne  espace colonne), ");
    cpt+=1;
    Positionner_Curseur(x,y+cpt);
    do
    {
        Positionner_Curseur(x,y+cpt);
        printf("Attention, ligne de 1 � 3 et colonne de 1 � 4:              ");
        Positionner_Curseur(x+46,y+cpt);
        scanf("%d %d",&ligne,&colonne);
        ligne--;
        colonne--;
    }
    while(ligne>3||ligne<0||colonne>4||colonne<0);
    if(etoile_recuperee==1)
    {
        jr->nb_etoile++;
        jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;
        jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;
    }


    if(jr->pos_etoile->colonne==colonne&&jr->pos_etoile->ligne==ligne)//si la carte qui va etre jet� est une ancienne carte �toile, elle reprend son �tat initial "13"
        jr->deck_nombre[ligne][colonne]=13;

    p->nombre_defausse_nb++;
    p->nombre_defausse[p->nombre_defausse_nb-1]=jr->deck_nombre[ligne][colonne]; //�crit la valeur de la carte jet�e dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120


    jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
    jr->deck_nombre_cache[ligne][colonne]=1; //retourne la carte tout juste d�pos� (l'�tat pr�c�dant de la case n'est pas pris en compte)
}
int etoile_presente(S_joueur jr,int ligne, int colonne)
{
    int i;
    for(i=0; i<jr.nb_etoile; i++)
        if(jr.pos_etoile[i].ligne==ligne&&jr.pos_etoile[i].colonne==colonne)
            return 1;

    return 0;
}
