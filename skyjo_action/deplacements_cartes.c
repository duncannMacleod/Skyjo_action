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
    int cpt,ligne=0,colonne=0;
    char choix,c;


    int carte_pioche=p->nombre[p->nombre_nb-1]; //la variable carte pioch� prend la valeur de la premi�re carte sur le paquet
    p->nombre[p->nombre_nb-1]=30; //supprime la carte du paquet
    p->nombre_nb--; //enl�ve un au nombre de cartes

    do
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("Vous avez pioch� un %d! Que voulez vous faire? ",carte_pioche);

        cpt+=1;Positionner_Curseur(x,y+cpt);
        printf("La Placer P, ou la jeter dans la D�fausse D");
        cpt+=1;Positionner_Curseur(x,y+cpt);
        printf("R�ponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);
        cpt+=2;Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'P'://place la carte dans le jeu
            printf("entrez les coordonn�es de la nouvelle place pour la carte (ligne  espace colonne), ");
            cpt+=1;Positionner_Curseur(x,y+cpt);
            do{
                printf("Attention, ligne de 1 � 3 et colonne de 1 � 4:");
                scanf("%d %d",&ligne,&colonne);
                ligne--; colonne--;
            }while(ligne>3||ligne<0||colonne>4||colonne<0);
            p->nombre_defausse_nb++;
            p->nombre_defausse[p->nombre_defausse_nb]=jr->deck_nombre[ligne][colonne]; //�crit la valeur de la carte jet�e dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120


            carte_pioche=jr->deck_nombre[ligne][colonne];//pose la carte de la pioche dans le jeu
            jr->deck_nombre_cache[ligne][colonne]=1; //retourne la carte tout juste d�pos� (l'�tat pr�c�dant de la case n'est pas pris en compte)

            choix=1;
            break;


        case 'D'://jete la carte dans la d�fausse

            p->nombre_defausse_nb++;
            p->nombre_defausse[p->nombre_defausse_nb]=carte_pioche; //�crit la valeur de la carte pioch� dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120
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
