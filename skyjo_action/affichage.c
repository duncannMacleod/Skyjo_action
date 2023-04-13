#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "affichage.h"
#include "declaration.h"
#include "suivi_score.h"

void plein_ecran()
{
    keybd_event(VK_MENU,0x38,0,0); //Appuie sur ALT
    keybd_event(VK_RETURN,0x1c,0,0); //Appuie ENTREE
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); // Relache ENTREE
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); //Relache ALT
}

void color (int couleurDuTexte, int couleurDuFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}

void Positionner_Curseur(int x, int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//permet de déclarer la variable "hstdout" qui fait référénce à la console
    COORD pos; // COORD est un type structuré défini dans la bibliothèque windows.h
    pos.X=x;// numéro de la colonne
    pos.Y=y;// numéro de la ligne
    SetConsoleCursorPosition(hStdout, pos); //on positionne le curseur aux coordonnées "pos"
}

int afficher_menu_bienvenue ()
{
        char menu[5][86]= {"      2 joueurs                                                                      ",
                           "      3 joueurs                                                                      ",
                           "      4 joueurs                                                                      ",
                           "                                                                                     ",
                           "      Quitter                                                                        ",
                           };
    int choix=0; // numéro de l'option choisie dans le menu
    int frappe=0; //permet de stocker le code de la touche clavier
    int i;
    while (choix!=4)
    {


        system("cls");
        printf(" ________         Skyjo Action     ___________     Créé par les Boudet          _______\n");
        printf("|                                                                                     |\n");
        printf("|   Bienvenue dans le jeu Skyjo Action, veuillez sélectionner le nombre de joueurs    |\n");
        printf("|                                                                                     |\n");


        for(i=0; i<5; i++)
        {
            printf("|%s|\n",menu[i]);
        }

        printf("|                                                                                     |\n");
        printf("|                                                                                     |\n");
        printf("|_____________________________________________________________________________________|\n");

        Positionner_Curseur(0,4);
        color(0,15);
        printf("|%s|\n",menu[0]);
        color(15,0);
        Positionner_Curseur(0,12);
        printf("\n");

        while(frappe!=13) // tant qu'on a pas appuyer sur la touche ECHAP
        {
            if (kbhit()) //si on a appuyer sur une touche du clavier
            {


                frappe=getch(); // on récupère le code de la touche sur laquelle on a appuyée


                if(frappe==72) //75 est le code de la flèche directionnelle vers le haut
                {

                    Positionner_Curseur(0,choix+4); // positionne le curseur au choix courant
                    color(15,0); // met la couleur du texte en blanc et celle du fond en noir
                    printf("|%s|",menu[choix]); // On réaffiche le choix courant avec les couleurs préalablement choisies, une manière de le désélectionner
                    choix--; // on décrémebte le numéro de l'option
                    if (choix ==-1) choix =4; // les options sont numérotées de 0 à 11
                    Positionner_Curseur(0,choix+4);// positionne le curseur au choix juste dessus du précédent
                    color(0,15);// met la couleur du texte en noir et celle du fond en blanc
                    printf("|%s|\n",menu[choix]);// On réaffiche le nouveau choix  avec les couleurs préalablement choisies, une manière de le séléctionner
                    color(15,0);
                }
                if(frappe==80) //80 est le code de la flèche directionnelle vers le bas
                {

                    Positionner_Curseur(0,choix+4);
                    color(15,0);
                    printf("|%s|",menu[choix]);
                    choix++;
                    if (choix ==5) choix =0;
                    Positionner_Curseur(0,choix+4);
                    color(0,15);
                    printf("|%s|",menu[choix]);
                    color(15,0);
                }

            }
            Positionner_Curseur(0,12);

        }
        choix++;
        switch (choix)
        {
        case 1 :// 2 joueurs
            return 2;
            break;

        case 2 ://3 joueurs
            return 3;
            break;

        case 3://4 joueurs
            return 4;
            break;

        case 4:// case tampon

            break;

        case 5 : //Quiter
            printf("\n\n\n ******************    Au revoir    ******************\n\n");
            return 0;
            break;

        }
        choix=0;frappe=0;

    }


    return 0;
}

void afficher_boite_dialogue()
{
        Positionner_Curseur(0,21);
        printf(" ___________________________      Boite de dialogue     _______________________________\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" ______________________________________________________________________________________\n");
        Positionner_Curseur(3,23);

}






void afficher_plateau_vide (int nb_j)
{
        system("cls");
        printf(" ________         Skyjo Action     ___________     Créé par les Boudet          _______\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |  Tour de:                                                                          |\n");
        printf(" |                                                                                    |\n");
        if(nb_j==2)
        {
            printf(" |                                                  Score: 1er-                       |\n");
            printf(" |       Votre Jeu:                                        2nd-                       |\n");
            printf(" |                                                                                    |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |                                                                                    |\n");
        }
        else if (nb_j==3)
        {
            printf(" |                                                  Score: 1er-                       |\n");
            printf(" |       Votre Jeu:                                        2nd-                       |\n");
            printf(" |                                                         3me-                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |                                                                                    |\n");
        }
        else if (nb_j==4)
        {
            printf(" |                                                  Score: 1er-                       |\n");
            printf(" |       Votre Jeu:                                        2nd-                       |\n");
            printf(" |                                                         3me-                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                            4me-                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |                                                                                    |\n");


        }
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" | Défausse des cartes nombres: [  ]                                                  |\n");
        printf(" |                                                                                    |\n");
        printf(" | Cartes actions:[              ] [              ] [              ] [              ] |\n");
        printf(" |                                                                                    |\n");
        printf(" | Défausse des cartes actions: [              ]                                      |\n");
        printf(" |                                                                                    |\n");
        printf(" ______________________________________________________________________________________\n");


}


void afficher_plateau_des_autres(int nb_j)
{
    Positionner_Curseur(0,0);
    system("cls");
        printf(" ________         Skyjo Action     ___________     Créé par les Boudet          _______\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        if(nb_j==2)
        {
            printf(" |                                                                                    |\n");
            printf(" |        Jeu de:                                                                     |\n");
            printf(" |                                                                                    |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
        }
        if(nb_j==3)
        {
            printf(" |                                                                                    |\n");
            printf(" |        Jeu de:                         Jeu de:                                     |\n");
            printf(" |                                                                                    |\n");
            printf(" |          [  ] [  ] [  ] [  ]              [  ] [  ] [  ] [  ]                      |\n");
            printf(" |          [  ] [  ] [  ] [  ]              [  ] [  ] [  ] [  ]                      |\n");
            printf(" |          [  ] [  ] [  ] [  ]              [  ] [  ] [  ] [  ]                      |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
            printf(" |                                                                                    |\n");
        }
        if(nb_j==4)
        {
            printf(" |                                                                                    |\n");
            printf(" |        Jeu de:                         Jeu de:                                     |\n");
            printf(" |                                                                                    |\n");
            printf(" |          [  ] [  ] [  ] [  ]              [  ] [  ] [  ] [  ]                      |\n");
            printf(" |          [  ] [  ] [  ] [  ]              [  ] [  ] [  ] [  ]                      |\n");
            printf(" |          [  ] [  ] [  ] [  ]              [  ] [  ] [  ] [  ]                      |\n");
            printf(" |                                                                                    |\n");
            printf(" |        Jeu de:                                                                     |\n");
            printf(" |                                                                                    |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |                                                                                    |\n");

        }
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" ______________________________________________________________________________________\n");

}






void afficher_actualiser_joueur (S_joueur jr,int x,int y) //actualise les cartes du joueur, à faire à chaque modif de son jeu, ou bien à chaque changement de joueur
{


	int i;
	int j;

	Positionner_Curseur(x,y);
	puts(jr.prenom); //affiche le prénom du joueur

	for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
        {
            for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
            {
                Positionner_Curseur(x+j*5,y+i+5);
				if (jr.deck_nombre_cache[i][j]==1)          //carte face découverte
                    printf("[%-2d] ",jr.deck_nombre[i][j]);
                else if (jr.deck_nombre_cache[i][j]==0)     //carte face caché
                    printf("[%-2s] ","X");
                else if (jr.deck_nombre_cache[i][j]==-1) //plus de carte
                    printf("     ");



            }

        }
}
void afficher_actualiser_score (int nb_j, S_joueur jr[])
{
    int i;
    //tri_score(nb_j,jr);
    for (i=0;i<nb_j;i++)
    {
        Positionner_Curseur(64,5+i);
        puts(jr[i].prenom); //affiche le prenom du joueur (tableau jr préalablement trié)
        Positionner_Curseur(65+strlen(jr[i].prenom),5+i);
        printf("avec %d pts",jr[i].score); //affiche le score


    }
}

void afficher_actualiser_defausse_nombre (S_pioche p)
{
    Positionner_Curseur(32,14);
    if (p.nombre_defausse[CARTE_PIOCHE_NOMBRE_NB-p.nombre_nb]==30)//ne numéro 30 signifie pas de carte, la defausse est actualisé comme cela
        printf("    ");
    else
        printf("[%-2.2d]",p.nombre_defausse[CARTE_PIOCHE_NOMBRE_NB-p.nombre_nb]); //CARTE_PIOCHE_NOMBRE_NB-p.nombre_nb correspond au rang de la dernière carte nombre dans la pioche
}

void afficher_actualiser_pioche_action (S_pioche p)
{
    int i;
    for(i=0;i<CARTE_PIOCHE_ACTION_FACE_VISIBLE;i++)
    {
        Positionner_Curseur(19+17*i,16);
        if(p.action_visible[i]==14)
            printf("Force à Jeter");
        if(p.action_visible[i]==15)
            printf("Bouge tes C");
        if(p.action_visible[i]==16)
            printf("2 Tours supp");
        if(p.action_visible[i]==17)
            printf("Pioche 3 C.");
        if(p.action_visible[i]==18)
            printf("Look 1 L ou C");
        if(p.action_visible[i]==19)
            printf("Def + 1 tour");
        if(p.action_visible[i]==20)
            printf("Rejoue la C.AC");
        if(p.action_visible[i]==21)
            printf("Vole C.ACT");
        if(p.action_visible[i]==22)
            printf("Echange de C.");
    }
}


void afficher_actualiser_defausse_action (S_pioche p)
{
    Positionner_Curseur(33,18);
    if (p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==30)//ne numéro 30 signifie pas de carte, la defausse est actualisé comme cela
    {
        Positionner_Curseur(32,18);
        printf("                ");//n'imprime rien
    }
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==14) //CARTE_PIOCHE_ACTION_NB-p.action_nb définit le rang de la dernière carte jouée
        printf("Force à Jeter");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==15)
        printf("Bouge tes C");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==16)
        printf("2 Tours supp");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==17)
        printf("Pioche 3 C.");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==18)
        printf("Look 1 L ou C");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==19)
        printf("Def + 1 tour");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==20)
        printf("Rejoue la C.AC");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==21)
        printf("Vole C.AC");
    else if(p.action_defausse[CARTE_PIOCHE_ACTION_NB-p.action_nb]==22)
        printf("Echange de C.");
}




void afficher_actualiser_jeu_des_autres(S_joueur jr[],int no_observateur,int nb_j)
{
    afficher_plateau_des_autres(nb_j);
}




