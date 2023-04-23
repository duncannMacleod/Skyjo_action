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
#include "detection_skyjo.h"




int main()
{
    srand(time(NULL));
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    plein_ecran(); //passe la console en plein écran
    int nb_joueurs,i,test;
    nb_joueurs= afficher_menu_bienvenue(); //le programme execute la fonction afficher_menu_bienvenue() , qui revoie de nombre de joueurs
    if (nb_joueurs==0)
        return 0;


    S_joueur jr[nb_joueurs]; //le nombre de case du tableau en fonction du nombre de joueurs
    S_pioche p; //la variable gérant toutes les données des pioches est crée




    afficher_plateau_vide(nb_joueurs); //permet a l'utilisateur de visulaliser son environement de jeu pendant l'initialisation des profils
    afficher_boite_dialogue(); //cette fonction permet d'afficher un large rectangle ou le conversationnel sera fait.
    initialisation_profil (jr,&p,nb_joueurs,3,23);//initalise les variables qui ne n'auront pas a etre réinitialisé à chaque manche
    do
    {
        initialisation_manche(jr,&p,nb_joueurs,3,23);//initalise les variables pour commencer la manche
        do
        {
            for(i=1; i<nb_joueurs+1; i++) //!!!!!! attention compteur allant de 1 à nb_jr+1 !!!!!!
                debut_tour (jr,i,nb_joueurs,&p,3,23);//engendre le début véritable de la partie
            test=test_fin_manche(jr,nb_joueurs);
        }
        while((test)==0);
    }
    while(test_fin_partie(jr,nb_joueurs)==0);




    system("PAUSE");



}


