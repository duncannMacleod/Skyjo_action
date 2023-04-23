#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "initialisation.h"
#include "declaration.h"
#include "affichage.h"

void initialisation_profil (S_joueur jr[], S_pioche *p, int nb_jr,int x,int y) //ces variables doivent être initialisés qu'une seule fois
{

    initialisation_score(nb_jr,jr);
    creation_profil_joueur(nb_jr,jr,p,x,y);


}

void initialisation_manche (S_joueur jr[], S_pioche *p, int nb_jr,int x,int y) //ces variables doivent etre initialisés à chaque debut de manche
{

    initalisation_nb_cartes(p); //I. des variables références des paquets ex: nombre_nb

    initialisation_carte_nombre(p); //I. les valeurs des cartes dans le paquet des nombres
    melanger_paquet_nombre(p);//mélange le paquet des nombres

    initialisation_carte_action(p); //I. les valeurs des cartes dans le paquet des cartes actions
    melanger_paquet_action(p);//melange les cartes actions

    initalisation_nb_cartes(p);//pour éviter des bugs, les valeurs de référence sont de nouveau initialsées 


    initalisation_joueur_deck(nb_jr,jr,p,x,y); //les cartes nombres et actions sont distribuées aux joueurs

    //initialisation_carte_action(p);
    initialisation_pioche_carte_action(p); // les 4 cartes actions sont présentés
    initialisation_defausse_action(p);//la defausse des cartes action est initialisé (pour rendre l'affichage plus joli)
    initialisation_defausse_nombre(p);//on place une carte face montrée pour faire la défausse des cartes nombre
    initalisation_nb_etoile(jr,nb_jr);//I. de tous variables relatives aux étoiles
    initalisation_nb_skyjo(jr,nb_jr);//idem

}


void initialisation_carte_nombre(S_pioche*p) //crée le paquet de carte nombre non mélangé
{
    int i,cpt=0;
    for(i=0;i<3;i++)
    {
        p->nombre[cpt]=-2;cpt++;
    }
    for(i=0;i<11;i++)
    {
        p->nombre[cpt]=0;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=-1;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=1;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=2;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=3;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=4;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=5;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=6;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=7;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=8;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=9;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=10;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=11;cpt++;
    }
    for(i=0;i<7;i++)
    {
        p->nombre[cpt]=12;cpt++;
    }
    for(i=0;i<15;i++)
    {
        p->nombre[cpt]=13;cpt++;
    }
}

void initialisation_carte_action(S_pioche*p) //crée le paquet de carte action non mélangé
{
    int i,cpt=0;
    for(i=0;i<3;i++)
    {
        p->action[cpt]=14;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=15;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=16;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=17;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=18;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=19;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=20;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=21;cpt++;
    }
    for(i=0;i<3;i++)
    {
        p->action[cpt]=22;cpt++;
    }

}




void melanger_paquet_nombre(S_pioche*p) //utilise l'algorithme de Fisher-Yates pour mélanger les cartes nombre
{
    int i,j,tampon;
    for(i=p->nombre_nb;i >= 1; i--)
    {
        j = rand() % (i + 1);
        tampon=p->nombre[i];
        p->nombre[i]=p->nombre[j];
        p->nombre[j]=tampon;
    }
}

void melanger_paquet_action(S_pioche*p) //utilise l'algorithme de Fisher-Yates pour mélanger les cartes nombre
{
    int i,j,tampon;
    for(i=p->action_nb;i >= 1; i--)
    {
        j = rand() % (i + 1);
        tampon=p->action[i];
        p->action[i]=p->action[j];
        p->action[j]=tampon;
    }
}

void creation_profil_joueur(int nb_jr, S_joueur jr[], S_pioche *p,int x, int y) //les données relative au joueur (ce programme n'est pas très peuplé, car les autres fonctions d'I. doivent etre réutilisé apres chaque manche. Celle ci n'est ulitisé qu'une seule fois
{
    int i;

    //on va commencer par demander les prénoms des joueurs
    for(i=0; i<nb_jr; i++)
    {


        do{

            Positionner_Curseur(x,y+i);
            printf("                                                                          ");//permet d'éffacer la ligne ou l'on va écrire le message (utlise si on a rentré un nom de plus de 10 caractères
            Positionner_Curseur(x,y+i);
            printf("Veuillez entrez le prénom du joueur %d (max 10 caractères):",i+1); //conversationnel
            gets(jr[i].prenom); //l'utilisateur entre som prémon
        } while (strlen(jr[i].prenom)>10); //pas plus de 10 car sinon le nom+score dépasserai la boite de dialogue

        jr[i].joueur_no=i+1; //le numéro du joueur prend la valeur de i+1 ex Joueur(1)->i=0+1

    }



}

void initalisation_joueur_deck(int nb_jr, S_joueur jr[], S_pioche *p,int x, int y)
{
   int n,j,i;
   for(n=0; n<nb_jr; n++)
    {
        //initialisation des cartes de jeu
        for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {
                jr[n].deck_nombre[i][j]=p->nombre[p->nombre_nb-1];  //prend une carte du paquet et la place dans le jeu du joueur
                p->nombre[p->nombre_nb-1]=30;                        //par sécurité, l'emplacement ou la carte a été prise récrécrit pour insinuer  "pas de carte"
                p->nombre_nb--;                                     //enlève 1 au nombre de cartes.
            }

        }

        for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {
                jr[n].deck_nombre_cache[i][j]=0; //on cache toutes les cartes
            }

        }

        //initialisation des deux cartes face montrée
        int rd_l=rand()%CARTE_JOUEUR_NOMBRE_L;
        int rd_c=rand()%CARTE_JOUEUR_NOMBRE_C;
        jr[n].deck_nombre_cache[rd_l][rd_c]=1;//on  retourne la première carte

        int rd_l2;
        int rd_c2;

        do
        {
            rd_l2=rand()%CARTE_JOUEUR_NOMBRE_L;
            rd_c2=rand()%CARTE_JOUEUR_NOMBRE_C;
        }
        while (rd_l==rd_l2&&rd_c==rd_c2); //permet que les 2 cartes levées ne soit pas les mêmes

        jr[n].deck_nombre_cache[rd_l2][rd_c2]=1; //on retourne la seconde carte

    }
}

void initalisation_nb_cartes(S_pioche *p) //initialise le nombre de cartes dans les paquets
{
    p->nombre_nb=CARTE_PIOCHE_NOMBRE_NB; //120
    p->nombre_defausse_nb=0;
    p->nombre_defausse_dessous_nb=0;
    p->action_nb=CARTE_PIOCHE_ACTION_NB; //27
    p->action_defausse_nb=0;
}

void initalisation_nb_etoile(S_joueur jr[],int nb_jr)
{
    int i;
    for(i=0;i<nb_jr;i++)
        jr[i].nb_etoile=0; //I. à zéro le nombre d'étoile du joueur
}

void initialisation_pioche_carte_action( S_pioche *p)//I. la pioche des cartes
{
    int i;
    for(i=0; i<CARTE_PIOCHE_ACTION_FACE_VISIBLE; i++) //effectue 4 fois la manipulation
    {
        p->action_visible[i]=p->action[(p->action_nb)-1];//dispose une carte de la pioche d'action dans la i eme case du tableau des cartes visibles (que 4 cases) 
        p->action_nb--; //retire un du compteur des cartes actions
    }
}


void initialisation_defausse_nombre(S_pioche *p)
{
    p->nombre_defausse[0]=p->nombre[p->nombre_nb-1]; //pioche une carte du paquet et la pose comme première carte de la défausse
    p->nombre[p->nombre_nb-1]=30;                    //par sécurité, l'emplacement ou la carte a été prise récrécrit pour insinuer  "pas de carte"
    p->nombre_nb--; //enlève 1 du compeuteur de carte nombre
    p->nombre_defausse_nb++;
}
void initialisation_defausse_action(S_pioche *p)
{
    p->action_defausse[0]=30;//initilise juste la première carte de la défausse, pour ne pas faire bugger l'affichage
}

void initialisation_score(int nb_jr,S_joueur jr[])
{
    int i;
    for(i=0;i<nb_jr;i++)
       jr[i].score=0; //initialise les scores des joueurs à 0
}

void initalisation_nb_skyjo(S_joueur jr[],int nb_jr)
{
    int i;
    for(i=0;i<nb_jr;i++)
    {
        jr[i].nb_skyjo_ligne=0; //I. les compteurs de skyjo a 0
        jr[i].nb_skyjo_colonne=0;//idem
    }
}
