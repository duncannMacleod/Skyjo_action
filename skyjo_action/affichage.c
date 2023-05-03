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
        choix=0;
        frappe=0;

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






void afficher_plateau_vide (int nb_jr)
{
    system("cls");
    printf(" ________         Skyjo Action     ___________     Créé par les Boudet          _______\n");
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
    printf(" |  Tour de:                                                                          |\n");
    printf(" |                                                                                    |\n");
    if(nb_jr==2)
    {
        printf(" |                                                  Score: 1er-                       |\n");
        printf(" |       Votre Jeu:                                        2nd-                       |\n");
        printf(" |                                                                                    |\n");
        printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        printf(" |                                                                                    |\n");
    }
    else if (nb_jr==3)
    {
        printf(" |                                                  Score: 1er-                       |\n");
        printf(" |       Votre Jeu:                                        2nd-                       |\n");
        printf(" |                                                         3me-                       |\n");
        printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        printf(" |          [  ] [  ] [  ] [  ]                                                       |\n");
        printf(" |                                                                                    |\n");
    }
    else if (nb_jr==4)
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


void afficher_plateau_des_autres(int nb_jr)
{
    Positionner_Curseur(0,0);
    system("cls");
    printf(" ________         Skyjo Action     ___________     Créé par les Boudet          _______\n");
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
    if(nb_jr==2)
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
    if(nb_jr==3)
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
    if(nb_jr==4)
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
            {
                if(jr.deck_nombre[i][j]==13)
                    printf("[**] ");
                else
                    printf("[%-2d] ",jr.deck_nombre[i][j]);
            }
            else if (jr.deck_nombre_cache[i][j]==0)     //carte face caché
                printf("[%-2s] ","X");
            else if (jr.deck_nombre_cache[i][j]==-1) //plus de carte
                printf("     ");
        }
    }
    surligner_etoile(jr,12,3);

}

void afficher_actualiser_joueur_vision (S_joueur jr,int x,int y)
{
    int i, j;

    Positionner_Curseur(x,y);
    puts(jr.prenom); //affiche le prénom du joueur

    for(i=0; i<CARTE_JOUEUR_NOMBRE_L; i++)
    {
        for(j=0; j<CARTE_JOUEUR_NOMBRE_C; j++)
        {
            Positionner_Curseur(x+j*5-5,y+i+2);
            if (jr.deck_nombre_cache[i][j]==1)          //carte face découverte
            {
                if(jr.deck_nombre[i][j]==13)
                    printf("[**] ");
                else
                    printf("[%-2d] ",jr.deck_nombre[i][j]);
            }
            else if (jr.deck_nombre_cache[i][j]==0)     //carte face caché
                printf("[%-2s] ","X");
            else if (jr.deck_nombre_cache[i][j]==-1) //plus de carte
                printf("     ");



        }

    }
}


void afficher_actualiser_score (int nb_jr, S_joueur jr[])
{
    int i;
    for (i=0; i<nb_jr; i++)
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
    if(p.nombre_defausse[0]==30||p.nombre_defausse_nb==0)
        printf("    ");
    else if (p.nombre_defausse[p.nombre_defausse_nb-1]==30)//ne numéro 30 signifie pas de carte, la defausse est actualisé comme cela
        printf("    ");
    else if (p.nombre_defausse[p.nombre_defausse_nb-1]==13)
        printf("[**]");
    else
        printf("[%-2d]",p.nombre_defausse[p.nombre_defausse_nb-1]); //CARTE_PIOCHE_NOMBRE_NB-p.nombre_nb correspond au rang de la dernière carte nombre dans la pioche
}

void afficher_actualiser_pioche_action (S_pioche p)
{
    int i;
    for(i=0; i<CARTE_PIOCHE_ACTION_FACE_VISIBLE; i++)
    {
        Positionner_Curseur(19+17*i,16);
        if(p.action_visible[i]==14)
            printf("Force à Jeter");
        else if(p.action_visible[i]==15)
            printf("Bouge tes C");
        else if(p.action_visible[i]==16)
            printf("2 Tours supp");
        else if(p.action_visible[i]==17)
            printf("Pioche 3 C.");
        else if(p.action_visible[i]==18)
            printf("Look 1 L ou C");
        else if(p.action_visible[i]==19)
            printf("Def + 1 tour");
        else if(p.action_visible[i]==20)
            printf("Rejoue la C.AC");
        else if(p.action_visible[i]==21)
            printf("Vole C.ACT");
        else if(p.action_visible[i]==22)
            printf("Echange de C.");
    }
}


void afficher_actualiser_defausse_action (S_pioche p)
{

    if (p.action_defausse_nb==0)//si il n'y a pas de carte dans la pioche, il n'affiche rien
    {
        Positionner_Curseur(31,18);
        printf("                               ");
    }
    Positionner_Curseur(33,18);
    afficher_action(p.action_defausse[p.nombre_defausse_nb-1]);
}

void afficher_action(int nb)
{
    if (nb==0)//si il n'y a pas de carte dans la pioche, il n'affiche rien
        printf("                  ");//n'imprime rien
    else if(nb==14) //p.nombre_defausse_nb définit le rang de la dernière carte jouée
        printf("Force à Jeter");
    else if(nb==15)
        printf("Bouge tes C");
    else if(nb==16)
        printf("2 Tours supp");
    else if(nb==17)
        printf("Pioche 3 C.");
    else if(nb==18)
        printf("Look 1 L ou C");
    else if(nb==19)
        printf("Def + 1 tour");
    else if(nb==20)
        printf("Rejoue la C.AC");
    else if(nb==21)
        printf("Vole C.AC");
    else if(nb==22)
        printf("Echange de C.");
}

void afficher_actualiser_jeu_des_autres(S_joueur jr[],int no_observateur,int nb_jr)
{
    int i,cpt=0;
    afficher_plateau_des_autres(nb_jr);

    for(i=0; i<nb_jr; i++)
    {
        if(i!=no_observateur-1)
        {
            cpt++;
            if(cpt==1)
            {
                afficher_actualiser_joueur_vision (jr[i],17,6);
                surligner_etoile_des_autres(jr[i],17,6);
            }

            if(cpt==2)
            {
                afficher_actualiser_joueur_vision (jr[i],49,6);
                surligner_etoile_des_autres(jr[i],49,6);
            }


            if(cpt==3)
            {
                afficher_actualiser_joueur_vision (jr[i],17,12);
                surligner_etoile_des_autres(jr[i],17,12);
            }



        }
    }
}

void surligner_etoile(S_joueur jr,int x,int y)
{
    int i,ligne,colonne;
    for(i=0; i<jr.nb_etoile; i++)
    {
        ligne=jr.pos_etoile[i].ligne;
        colonne=jr.pos_etoile[i].colonne;
        Positionner_Curseur(x+colonne*5,y+ligne+5);

        if(jr.deck_nombre_cache[ligne][colonne]==1)
        {
            color(0,14);
            printf("[%-2d]",jr.deck_nombre[ligne][colonne]);
            color(15,0);
        }

    }

}

void surligner_etoile_des_autres(S_joueur jr,int x,int y)
{
    int i,ligne,colonne;
    for(i=0; i<jr.nb_etoile; i++)
    {
        ligne=jr.pos_etoile[i].ligne;
        colonne=jr.pos_etoile[i].colonne;
        Positionner_Curseur(x+colonne*5-5,y+ligne+2);

        if(jr.deck_nombre_cache[ligne][colonne]==1)
        {
            color(0,14);
            printf("[%-2d]",jr.deck_nombre[ligne][colonne]);
            color(15,0);
        }

    }

}

void voir_deck_action(S_joueur jr,int x,int y,int parametre)
{
    int i,cpt=0,cpt2=0;
    afficher_boite_dialogue();
    if(jr.nb_action==0)
    {
        Positionner_Curseur(x,y);
        printf("%s n'a pas de carte action",jr.prenom);
        cpt+=2;
    }
    else
    {
        Positionner_Curseur(x,y+cpt);
        printf("%s a %d cartes action:",jr.prenom,jr.nb_action);
        cpt+=2;
        if(jr.nb_action<12)
        {
            for(i=0; i<jr.nb_action; i++)
            {
                Positionner_Curseur(x,y+cpt);
                printf("%d- ",i+1);
                afficher_action(jr.deck_action[i]);
                cpt++;
            }
        }
        else if (jr.nb_action>=12)
        {
            for(i=0; i<12; i++)
            {
                Positionner_Curseur(x,y+cpt);
                printf("%d- ",i+1);
                afficher_action(jr.deck_action[i]);
                cpt++;
            }
            for(i=12; i<jr.nb_action; i++)
            {
                Positionner_Curseur(x+25,y+cpt2+2);
                printf("%d- ",i+1);
                afficher_action(jr.deck_action[i]);
                cpt2++;
            }
        }
    }
    if (parametre==1)
    {
        Positionner_Curseur(x,y+cpt);
        system("pause");
    }
    else if (parametre==2)
    {
        Positionner_Curseur(x,y+cpt);
        printf("Quelle carte voulez vous jouer? :");
    }
    else if (parametre==3)
    {
        Positionner_Curseur(x,y+cpt);
        printf("Quelle carte voulez vous voler? :");
    }


}



void afficher_coups(S_joueur jr)
{
    Positionner_Curseur(56,11);
    printf("nb de coups: %d",jr.nb_coups);
}
void afficher_dernier_tour(S_joueur jr[],int nb_jr)
{
    int i;
    for(i=0;i<nb_jr;i++)
    if(jr[i].init_fin_manche==1)
    {
        Positionner_Curseur(56,10);
        color(15,12);
        printf("Dernier tour !");
        color(15,0);
    }
}

void afficher_jeu_duo (S_joueur jr1,S_joueur jr2)
{
    afficher_actualiser_joueur_vision (jr1,17,6);
    surligner_etoile_des_autres(jr1,17,6);


    afficher_actualiser_joueur_vision (jr2,49,6);
    surligner_etoile_des_autres(jr2,49,6);
}

void afficher_haut_duo()
{
    Positionner_Curseur(0,0);
    system("cls");
    printf(" ________         Skyjo Action     ___________     Créé par les Boudet          _______\n");
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
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
    printf(" |                                                                                    |\n");
    printf(" |                                                                                    |\n");
    printf(" ______________________________________________________________________________________\n");
}


void recap_manche(S_joueur jr[], S_pioche p,int nb_jr,int x,int y,int parametre)
{
    int i,cpt=0;
    S_joueur jr_vainqueur;
    afficher_boite_dialogue();
    Positionner_Curseur(x,y+cpt);
    cpt+=2;
    printf("Résumé de la manche:");
    Positionner_Curseur(x,y+cpt);
    jr_vainqueur=test_init_jr(jr,nb_jr,p);
    Positionner_Curseur(x,y+cpt);
    if(jr_vainqueur.init_fin_manche==1&&p.premier_fin_manche-1==jr_vainqueur.joueur_no-1)//si deplus apres avoir initié la fin de la manche, il est le premier au score
        printf("%s avait initié la fin de manche, et c'est lui qui a le moins de points.",jr_vainqueur.prenom);
    else if (jr_vainqueur.init_fin_manche==-1)//si il a inititié la fin de partie mais qu'il n'est pas premier au score de la manche
    {
        printf("%s avait initié la fin de manche, mais il ne finit pas avec le plus bas score",jr_vainqueur.prenom);
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("le score qu'il fera a cette manche est donc doublé");
        cpt++;
        jr[jr_vainqueur.joueur_no-1].score_manche=(jr[jr_vainqueur.joueur_no-1].score_manche)*2;
    }
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    printf("les scores de cette manche sont donc");
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    for(i=0; i<nb_jr; i++)
    {
        printf("le score de %s cette manche est %d",jr[i].prenom,jr[i].score_manche);
        cpt++;
        Positionner_Curseur(x,y+cpt);
    }
    for(i=0; i<nb_jr; i++)
    {
        jr[i].score+=jr[i].score_manche;
    }
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
}
