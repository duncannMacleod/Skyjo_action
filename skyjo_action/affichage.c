#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "affichage.h"


void color (int couleurDuTexte, int couleurDuFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}

void Positionner_Curseur(int x, int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//permet de d�clarer la variable "hstdout" qui fait r�f�r�nce � la console
    COORD pos; // COORD est un type structur� d�fini dans la biblioth�que windows.h
    pos.X=x;// num�ro de la colonne
    pos.Y=y;// num�ro de la ligne
    SetConsoleCursorPosition(hStdout, pos); //on positionne le curseur aux coordonn�es "pos"
}

int afficher_menu_bienvenue ()
{
        char menu[5][86]= {"      2 joueurs                                                                      ",
                           "      3 joueurs                                                                      ",
                           "      4 joueurs                                                                      ",
                           "                                                                                     ",
                           "      Quitter                                                                        ",
                           };
    int choix=0; // num�ro de l'option choisie dans le menu
    int frappe=0; //permet de stocker le code de la touche clavier
    int i;
    while (choix!=4)
    {


        system("cls");
        printf(" ________         Skyjo Action     ___________     Cr�� par les Boudet          _______\n");
        printf("|                                                                                     |\n");
        printf("|   Bienvenue dans le jeu Skyjo Action, veuillez s�lectionner le nombre de joueurs    |\n");
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


                frappe=getch(); // on r�cup�re le code de la touche sur laquelle on a appuy�e


                if(frappe==72) //75 est le code de la fl�che directionnelle vers le haut
                {

                    Positionner_Curseur(0,choix+4); // positionne le curseur au choix courant
                    color(15,0); // met la couleur du texte en blanc et celle du fond en noir
                    printf("|%s|",menu[choix]); // On r�affiche le choix courant avec les couleurs pr�alablement choisies, une mani�re de le d�s�lectionner
                    choix--; // on d�cr�mebte le num�ro de l'option
                    if (choix ==-1) choix =4; // les options sont num�rot�es de 0 � 11
                    Positionner_Curseur(0,choix+4);// positionne le curseur au choix juste dessus du pr�c�dent
                    color(0,15);// met la couleur du texte en noir et celle du fond en blanc
                    printf("|%s|\n",menu[choix]);// On r�affiche le nouveau choix  avec les couleurs pr�alablement choisies, une mani�re de le s�l�ctionner
                    color(15,0);
                }
                if(frappe==80) //80 est le code de la fl�che directionnelle vers le bas
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
void afficher_plateau_vide (int nb_j)
{
        system("cls");
        printf(" ________         Skyjo Action     ___________     Cr�� par les Boudet          _______\n");
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" |  Tour de:                                                                          |\n");
        printf(" |                                                                                    |\n");
        if(nb_j==2)
        {
            printf(" |                                                    Score: 1er-                     |\n");
            printf(" |       Votre Jeu:                                          2nd-                     |\n");
            printf(" |                                                                                    |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        }
        else if (nb_j==3)
        {
            printf(" |                                                    Score: 1er-                     |\n");
            printf(" |       Votre Jeu:                                          2nd-                     |\n");
            printf(" |                                                           3me-                     |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        }
        else if (nb_j==4)
        {
            printf(" |                                                    Score: 1er-                     |\n");
            printf(" |       Votre Jeu:                                          2nd-                     |\n");
            printf(" |                                                           3me-                     |\n");
            printf(" |          [  ] [  ] [  ] [  ]                              4me-                     |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
            printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");


        }
        printf(" |                                                                                    |\n");
        printf(" |                                                                                    |\n");
        printf(" | D�fausse des cartes nombres: [  ]                                                  |\n");
        printf(" |                                                                                    |\n");
        printf(" | Cartes actions:  [           ] [            ] [            ] [            ]        |\n");
        printf(" |                                                                                    |\n");
        printf(" | D�fausse des cartes actions: [            ]                                        |\n");
        printf(" |                                                                                    |\n");
        printf(" ______________________________________________________________________________________\n");


}
