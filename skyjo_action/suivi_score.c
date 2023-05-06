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
    S_class* pa=(S_class*)a;
    S_class* pb=(S_class*)b;
    return pa->score - pb->score;
}


void tri_score(int nb_jr, S_joueur jr[]) //sert a trier les joueurs par leurs score pour ensuite afficher le classement
{
    int i;
    S_class tab[nb_jr];//déclaration d'un tableau du type structuré S_class, utilisé seulement pour le calssmement des joueurs
    for(i=0;i<nb_jr;i++)
    {
        tab[i].classement=jr[i].classement;
        tab[i].score=jr[i].score;
    }
    qsort(tab,nb_jr,sizeof(S_class),fonct_compare_score);//trie le tableau de S_class, conteant seulement le score des joueurs et leur classement
    for(i=0;i<nb_jr;i++)
    {
        jr[i].classement=tab[i].classement;//cette approche permet de seulement modifier jr.classement et non l'ordre entier du tableau jr . Cela permet d'affiermer que le joueur 2 joura toujours apres le joueur 1 (malgré son score).
    }
}

int test_fin_partie(S_joueur jr[],int nb_jr) //si un joueur a plus de 100 pts, la fonction renvoie le numéro de celui ayant dépassé le score
{
    int i;
    for(i=0;i<nb_jr;i++)
    {
        if(jr[i].score>=100)//vérifie si l'un des joueurs à dépassé la barre des 100pts
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
		jr[i].score_manche=somme;//le score de la manche du joueur est actualisé

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
        if(cpt==12||p.premier_fin_manche==i+1)//si le joueur à relevé toutes ces cartes et qu'il est le premier de la partie à avoir fini
        return i+1;
    }

    return 0;
}

void test_init_jr(S_joueur jr[],int nb_jr,S_pioche p) //savoir si il a été le premier joueur de la
{
    int i;
    for(i=0;i<nb_jr;i++)//boucle pour tout les joueurs
        if(i!=(p.premier_fin_manche-1)) //sauf le joueur ayant initié la fin de tour
            if(jr[p.premier_fin_manche-1].score_manche>jr[i].score_manche)//si le score du joueur i est supérieur a celui ayant lancé le dernier tour,
                {
                    jr[p.premier_fin_manche-1].init_fin_manche=-1;//n'a pas réussi à avoir le moins de pts
                }
}

void test_premier_fin_manche(S_joueur *jr,int nb_jr,S_pioche *p) //a chaque fin de manche
{
        int a,b,cpt=0;
        for(a=0;a<CARTE_JOUEUR_NOMBRE_L;a++)
            for(b=0;b<CARTE_JOUEUR_NOMBRE_C;b++)
                if(jr->deck_nombre_cache[a][b]==1||jr->deck_nombre_cache[a][b]==-1)//vérifie une par une si les cartes des joueurs sont relevées (1 face nombre et -1 sorties du jeu)
                    cpt++;
        if(cpt==12&&p->premier_fin_manche==-1)//si toutes les cartes du joueur sont relevées, et que personne n'a pas encore initité une fin de manche.
        {
            p->premier_fin_manche=jr->joueur_no;//le no du joueur est enregistré comme celui ayant fini en premier
            jr->init_fin_manche=1;//le statut personnel du joueur passe au "j'ai terminé en premier"
            p->tour_restant=nb_jr-1;//le nombre de tour resant est initialisé pour que tout le monde finisse son tour
        }

}
