#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "affichage.h"
#include "declaration.h"
#include "suivi_score.h"

int fonct_compare_score(const void *a, const void *b)//fonction servant à faire fonctionner qsort();
{
    S_joueur* pa=(S_joueur*)a;
    S_joueur* pb=(S_joueur*)b;
    return pa->score - pb->score;
}


void tri_score(int nb_jr, S_joueur jr[]) //sert a trier les joueurs par leurs score pour ensuite afficher le classement
{
    qsort(jr,nb_jr,sizeof(S_joueur),fonct_compare_score);
}

int test_fin_partie(S_joueur jr[],int nb_jr) //si un joueur a plus de 100 pts, la fonction renvoie le numéro de celui ayant dépassé le score
{
    int i;
    for(i=0;i<nb_jr;i++)
    {
        if(jr[i].score>=100)
            return i+1;
    }
    return 0;
}

void comptage_score(S_joueur jr[],int nb_jr) //prend en compte les règles du skyjo pour compter les points de chaque participant
{
    int i,somme,a,b;
    for(i=0;i<nb_jr;i++)
    {
        somme=0;
        for(a=0; a<3; a++)
            for(b=0; b<4; b++)
            {
                if(jr[i].deck_nombre[a][b]!=30&&jr[i].deck_nombre[a][b]!=13)//la valeur 30 correspond a pas de cartes, et la valeur 13 a la carte etoile qui vaut 0.
                    somme+=jr[i].deck_nombre[a][b];
            }
		somme-=(10*jr[i].nb_skyjo_colonne+15*jr[i].nb_skyjo_ligne); //on soustrait a la somme globlale les bonus de skyjo (-10 pour une colonne et -15 pour une linge)
		somme+=(10*jr[i].nb_action); //incrémente 10 par nombre de carte action dans le jeu du joueur.
		jr[i].score_manche=somme;
		Positionner_Curseur(100,1+i);
		printf("%d %d", jr[i].score_manche, jr[i].score);


    }
}

int test_fin_manche(S_joueur jr[],int nb_jr,S_pioche p) //renvoie le numéro du joueur qui a gagné la manche
{
    int i,a,b,cpt;
    for(i=0;i<nb_jr;i++)
    {
        cpt=0;
        for(a=0;a<CARTE_JOUEUR_NOMBRE_L;a++)
            for(b=0;b<CARTE_JOUEUR_NOMBRE_C;b++)
                if(jr[i].deck_nombre_cache[a][b]==1||jr[i].deck_nombre_cache[a][b]==-1)
                    cpt++;
        if(cpt==12||p.premier_fin_manche==i+1)
        return i+1;
    }

    return 0;
}

S_joueur test_init_jr(S_joueur jr[],int nb_jr,S_pioche p)
{
    int no_jr_init=test_fin_manche(jr,nb_jr,p),i;
    for(i=0;i<nb_jr;i++)//boucle pour tout les joueurs
        if(i!=no_jr_init) //sauf le joueur ayant initié la fin de tour
            if(jr[no_jr_init-1].score_manche>jr[i].score_manche)//si le score du joueur i est supérieur a celui ayant lancé le dernier tour,
                {
                    jr[no_jr_init-1].init_fin_manche=-1;
                    Positionner_Curseur(100,8);
                    printf("%d %d double", jr[no_jr_init-1].score_manche,jr[i].score_manche );
                }

    return jr[no_jr_init-1];
}

void test_premier_fin_manche(S_joueur *jr,int nb_jr,S_pioche *p)
{
        int a,b,cpt=0;
        for(a=0;a<CARTE_JOUEUR_NOMBRE_L;a++)
            for(b=0;b<CARTE_JOUEUR_NOMBRE_C;b++)
                if(jr->deck_nombre_cache[a][b]==1||jr->deck_nombre_cache[a][b]==-1)
                    cpt++;
        if(cpt==12)
        {
            p->premier_fin_manche=jr->joueur_no-1;
            jr->init_fin_manche=1;
        }

}
