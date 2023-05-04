#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#include "cartes_actions.h"
#include "affichage.h"
#include "declaration.h"
#include "suivi_score.h"
#include "initialisation.h"
#include "deroulement_tour.h"
#include "detection_skyjo.h"
#include "deplacements_cartes.h"


void choix_carte_a_jouer(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr,int x,int y)//gère la demande et l'utilisation des cartes actions
{
    int choix,carte_a_jouer;
    char c;
    do
    {
        voir_deck_action(jr[no_jr-1],x,y,2); //affiche les cartes du joueur
        scanf("%d",&choix);
        while ((c = getchar()) != '\n' && c != EOF); //vide la mémoire tampon
    }
    while(choix<1||choix>jr[no_jr-1].nb_action); //tant que le choix n'est pas entre 1 et le nombre de carte qu'a le joueur

    carte_a_jouer=recup_du_deck(jr,no_jr,choix);//récupère et supprime la carte action du deck pour etre consommé
    switch(carte_a_jouer) //le switch se fait avec le nombre correspondant à la carte action que le joueur a sélectionné
    {
    case 14: //si la carte_a_jouer est égale à 14
        jouer_14(jr,p,no_jr,nb_jr,x,y);//on exécute le SSP jouer_14 qui fait permet de jouer la carte 14
        break;
    case 15:
        jouer_15(jr,p,no_jr,nb_jr,x,y);//idem
        break;
    case 16:
        jouer_16(jr,p,no_jr,nb_jr,x,y);//idem
        break;
    case 17:
        jouer_17(jr,p,no_jr,nb_jr,x,y);//idem
        break;
    case 18:
        jouer_18(jr,p,no_jr,nb_jr,x,y);//idem
        break;
    case 19:
        jouer_19(jr,p,no_jr,nb_jr,x,y);//idem
        break;
    case 20:
        jouer_20(jr,p,no_jr,nb_jr,x,y);//idem
		break;
    case 21:
        jouer_21(jr,p,no_jr,nb_jr,x,y);//idem
		break;
    case 22:
        jouer_22(jr,p,no_jr,nb_jr,x,y);//idem
        break;
    }
    p->action_defausse[p->action_defausse_nb]=carte_a_jouer; //déplace la carte qui a été joué dans dans la défausse des cartes actions
    p->action_defausse_nb++;//incrémente le nombre de carte action dans la défausse
    getchar(); //permet de vider la mémoire tampon


}

int recup_du_deck(S_joueur jr[],int no_jr,int choix) //supprime la carte du deck et la renvoie
{
    int i,carte_a_jouer;
    carte_a_jouer=jr[no_jr-1].deck_action[choix-1]; //carte_a_jouer prend la valeur de la carte choisie par l'utilisateur
    for(i=choix-1; i<jr[no_jr-1].nb_action; i++)
    {
        jr[no_jr-1].deck_action[i]=jr[no_jr-1].deck_action[i+1];//on décale toute les cartes après celle qui va etre prise pour la "supprimer"
    }

    jr[no_jr-1].nb_action--;//on décrémente le nombre de carte action
    return carte_a_jouer; //on retourne la valeur que la carte prise


}

void jouer_14(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y) //retire des cartes dans le jeu des autres
{
    int cpt=2,ligne,colonne,i;
    regarder_jeu_des_autres(jr,no_jr,nb_jr,x,y); //affiche le jeu des autres
    for(i=0; i<nb_jr; i++)
    {
        if(i!=(no_jr-1)&&verif_carte_def(jr[i])==0)
        {

            Positionner_Curseur(x,y+cpt); 							//conversationnel
            printf("quelle carte voulez vous enlever de jeu de ");
            puts(jr[i].prenom);
            cpt++;
            Positionner_Curseur(x,y+cpt);
            printf("Réponse (coordonnées ligne 1à3 esp. 1à4): ");
            scanf("%d %d",&ligne,&colonne);
            ligne--;
            colonne--;												//fin conversationnel
            placer_carte_piochee(&jr[i],p,ligne,colonne,2);//place une carte qui a été pioché a la place de celle sélectionné par l'utilisateur
            if(etoile_presente(jr[i],ligne,colonne)) //si avant le changement il y avait une carte étoile,
                supprimer_pos_etoile(&jr[i],ligne,colonne);//alors on la supprime du tableau de localisation des postions des étoiles du joueur
            cpt+=2;
        }
        if(i!=(no_jr-1)&&verif_carte_def(jr[i])!=0) //si le joueur i avait une carte défense dans son jeu
        {
            Positionner_Curseur(x,y+cpt);
            printf("vous ne pouvez pas piocher dans le jeu de %s car,",jr[i].prenom);//on lui informe que au joueur que le jr i avait une carte défense
            cpt++;
            Positionner_Curseur(x,y+cpt);
            printf("car il possédait une carte défense (celle ci vient d'etre consommé)");
            recup_du_deck(&jr[i],no_jr,verif_carte_def(jr[i])); //et on supprime la carte défense dans le jeu du jr i.
            cpt+=1;
            Positionner_Curseur(x,y+cpt);system("pause");//pour permettre au joueur de lire cela puisque on ne lui demande rien.
        }


    }




}
void jouer_15(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y)//échanger ses propres cartes
{
    int ligne1,ligne2,colonne1,colonne2,cpt=0;
    afficher_boite_dialogue();													//conversationnel
    Positionner_Curseur(x,y);
    printf("Quelle carte voulez vous échanger (linge 1à3 esp colonne 1à4)? :");
    scanf("%d %d",&ligne1,&colonne1);											//fin conversationnel
    ligne1--;
    colonne1--;
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    printf("avec quelle carte? :");
    scanf("%d %d",&ligne2,&colonne2);
    ligne2--;
    colonne2--;
    deplacer_carte_jeu(&jr[no_jr-1],&jr[no_jr-1],colonne1,ligne1,colonne2,ligne2); //échange la carte présente à la ligne1-colonne1 avec la carte de la ligne2-colonne2


}

void jouer_16(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y)//plus deux tours
{
    jr[no_jr-1].nb_coups+=2;//ajoute 2 coups suppémentaires a compteur personnel du joueur (réinitilalisé a chaque début de tour à 1)
}

void jouer_17(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y)//pioche 3 carte
{
    int carte_pioche1=tirer_carte(p),carte_pioche2=tirer_carte(p),carte_pioche3=tirer_carte(p),cpt=0,reponse,ligne,colonne; //les variables carte_pioche1&2&3 sont inititalisés avec la fonction tirer_carte. Cette fnct tire une carte de la pioche et retourne sa valeur
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);

	printf("Voici les 3 cartes que vous avez pioché:");
    if(carte_pioche1==13) //affichage ergonomique en fonction de la carte pioché, notamment la carte étoile
        printf(" ** ");
	else
		printf(" %d ",carte_pioche1);

	if(carte_pioche2==13) //affichage ergonomique en fonction de la carte pioché, notamment la carte étoile
        printf(" ** ");
	else
		printf(" %d ",carte_pioche2);

	if(carte_pioche3==13) //affichage ergonomique en fonction de la carte pioché, notamment la carte étoile
        printf(" ** ");
	else
		printf(" %d ",carte_pioche3);

    cpt+=2; Positionner_Curseur(x,y+cpt);
    printf("Quelle carte voulez vous garder 1à3 ou 0 si aucune: "); //conversationnel
    scanf("%d",&reponse);
    if(reponse==0)//si le joueur veut se débarasser de toute les cartes
    {
        retourne_carte(jr,p,x,y+cpt,3,carte_pioche1,carte_pioche2,carte_pioche3);//il doit tout de meme retourner une carte de son jeu
    }
    else if(reponse==1)//si le joueur veut garder la première carte
    {
        demande_l_c(&ligne,&colonne,x,y); //on lui demande ou il veut positionner sa nouvelle carte
        swap_carte(&jr[no_jr-1],p,carte_pioche1,ligne,colonne);//on échange la nouvelle carte avec l'ancienne
        p->nombre_defausse_nb++; //incrémente le nombre de carte de la défausse des cartes nombre
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche2;//et on jette l'une des deux cartes non choisie
        p->nombre_defausse_nb++;//idem
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche3;//idem
    }
    else if(reponse==2)//idem
    {
        demande_l_c(&ligne,&colonne,x,y);
        swap_carte(&jr[no_jr-1],p,carte_pioche2,ligne,colonne);
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche1;
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche3;
    }
    else if(reponse==3)//idem
    {
        demande_l_c(&ligne,&colonne,x,y);
        swap_carte(&jr[no_jr-1],p,carte_pioche3,ligne,colonne);
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche1;
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche2;
    }

}

void jouer_18(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y)//regarder une colonne ou une ligne dans nimporte quel jeu
{
    int cpt=0,choix,i;
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    for(i=0; i<nb_jr; i++)
    {
        printf("Voulez vous voir le jeu de %s (entrez %d)",jr[i].prenom,i+1);
        cpt++;
        Positionner_Curseur(x,y+cpt);
    }
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    printf("Réponse: ");
    scanf("%d",&choix);
    if(choix==1)
        voir_l_ou_c(jr[0],x,y); //montre la ligne ou la colonne du joueur numéro 1 (soit la case 0 du tableau)
    if(choix==2)
        voir_l_ou_c(jr[1],x,y);
    if(choix==3)
        voir_l_ou_c(jr[2],x,y);
    if(choix==4)
        voir_l_ou_c(jr[3],x,y);

}

void jouer_19(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y)//défense + coup supplémentaire
{
    jr[no_jr-1].nb_coups+=1; //quand cette carte est jouée, elle n'a d'effect que d'augmenter le nombre de coups de 1.
}

void jouer_20(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y)//récupérer une carte de la défausse des cartes action et la jouer imédiatement
{
    if(p->action_defausse_nb!=0)//si il y a des cartes actions dans la défausse
    {
        jr[no_jr-1].deck_action[jr[no_jr-1].nb_action]=p->action_defausse[p->action_defausse_nb-1];//la carte action de la défausse est déplacé vers le deck du joueur
        p->action_defausse_nb--;//décrémente le nombre de carte action
        jr[no_jr-1].nb_action++;
        jr[no_jr-1].nb_coups++;
    }
    else//sinon on prévient le joueur, et tout de meme sa carte est jouée, il aurait du regarder la défausse avant de jouer...
    {
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("Il n'y a pas de carte dans la pioche, dommage cette carte vient être perdu.");
    }

}

void jouer_21(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y) //voler une carte action
{
    int cpt=0
    ,carte_vol,choix,i;
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    for(i=0; i<nb_jr; i++)//affiche tout les joueurs sauf soi meme
    {
        if(i!=no_jr-1&&verif_carte_def(jr[i])==0)//si ce n'est pas nous meme ou bien si le joueur i n'a pas de carte défense
        {

            Positionner_Curseur(x,y+cpt);
            printf("Voulez vous voler une carte action du jeu de %s (choix %d )",jr[i].prenom,i+1);
            cpt++;
        }
        if(i!=no_jr-1&&verif_carte_def(jr[i])!=0)//si il possède une carte défense
        {
            Positionner_Curseur(x,y+cpt);
            printf("vous ne pouvez pas piocher dans le jeu de %s car,",jr[i].prenom);
            cpt++;
            Positionner_Curseur(x,y+cpt);
            printf("car il possédait une carte défense (celle ci vient d'etre consommé)");
            recup_du_deck(&jr[i],no_jr,verif_carte_def(jr[i]));
            cpt+=2;

        }
    }
    Positionner_Curseur(x,y+cpt);
    printf("Réponse: ");
    scanf("%d",&choix);
        voir_deck_action(jr[choix-1],x,y,3);//affiche le deck des carte action du joueur i avec le paramètre 3, correspondant au paramètre d'affichge pour le vol
        scanf("%d",&carte_vol);
        jr[no_jr-1].deck_action[jr[no_jr-1].nb_action]=recup_du_deck(&jr[choix-1],choix,carte_vol);//récupère la carte choise du deck de l'adversaire et la place dans je jeu du joueur
        jr[no_jr-1].nb_action++;

    jr[no_jr-1].nb_coups++;//incrémente le nombre de coup pour permettre au joueur de jouer sa carte dirrectement

}

void jouer_22(S_joueur jr[],S_pioche *p,int no_jr,int nb_jr, int x, int y)
{
    int cpt,a,i,reponse,ligne1,ligne2,colonne1,colonne2;
    for(a=1; a>=0; a--)//boucle gérant le nombre d'échange que le joueur peut faire
    {
        cpt=0;
        afficher_actualiser_jeu_des_autres(jr,no_jr,nb_jr);
        Positionner_Curseur(50,15);
        printf("nombres d'échanges restant: %d",a);//affiche le nombre d'échange restant au joueur
        afficher_boite_dialogue();
        Positionner_Curseur(x,y+cpt);
        for(i=0; i<nb_jr; i++)
        {
            if(no_jr-1!=i)
            {
                printf("Voulez échanger des cartes avec %s? (entrez %d)",jr[i].prenom,i+1);
                cpt++;
                Positionner_Curseur(x,y+cpt);
            }

        }
        Positionner_Curseur(x,y+cpt);
        printf("Réponse: ");
        scanf("%d",&reponse);
        afficher_haut_duo(); //affiche le squelette pour positionner le jeu de deux joueurs (celui jouant la carte et celui que l'on force à faire l'échange de carte
        afficher_jeu_duo (jr[no_jr-1],jr[reponse-1]);//affiche dans le squellette le jeu du joueur et celui que l'on force
        afficher_boite_dialogue();
        cpt=0;
        Positionner_Curseur(x,y+cpt);
        printf("Quelle carte de votre jeu voulez vous échanger (linge 1à3 esp colonne 1à4)? :");
        scanf("%d %d",&ligne1,&colonne1);
        ligne1--;
        colonne1--;
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("avec quelle carte de %s? :",jr[reponse-1].prenom);
        scanf("%d %d",&ligne2,&colonne2);
        ligne2--;
        colonne2--;
        deplacer_carte_jeu(&jr[no_jr-1],&jr[reponse-1],colonne1,ligne1,colonne2,ligne2);//déplace la carte nombre du joueur utilisant la carte action avec celle du joueur que l'on force a échanger

    }
}


void voir_l_ou_c(S_joueur jr,int x,int y)
{
    int cpt=0,li,cl;
    char choix,c;
    do
    {
        afficher_boite_dialogue();
        Positionner_Curseur(x,y+cpt);
        printf("Voulez vous regarder une Ligne L ou une colonne C? :");
        getchar();
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF);//permet d'effacer la mémoire tampon
        switch(toupper(choix))
        {
        case 'L'://si l'utilisateur veut voir une ligne
            cpt+=2;
            Positionner_Curseur(x,y+cpt);
            printf("Quelle ligne voulez vous voir 1à3: ");
            scanf("%d",&li);
            cpt+=2;
            Positionner_Curseur(x,y+cpt);
            printf("Voici les cartes de la ligne %d de %s ",cl,jr.prenom);
            if(jr.deck_nombre[li-1][0]==13) //affichage ergonomique en fonction de la nature de la carte action
                printf("** ");
            else
                printf("%d ",jr.deck_nombre[li-1][0]);

            if(jr.deck_nombre[li-1][1]==13)//idem
                printf("** ");
            else
                printf("%d ",jr.deck_nombre[li-1][1]);

            if(jr.deck_nombre[li-1][2]==13)//idem
                printf("** ");
            else
                printf("%d ",jr.deck_nombre[li-1][2]);

            if(jr.deck_nombre[li-1][3]==13)//idem
                printf("** ");
            else
                printf("%d ",jr.deck_nombre[li-1][3]);
            break;
        case 'C'://si l'utilisateur veut voir une colonne
            cpt+=2;
            Positionner_Curseur(x,y+cpt);
            printf("Quelle colonne voulez vous voir 1à4: ");
            scanf("%d",&cl);
            cpt+=2;
            Positionner_Curseur(x,y+cpt);

            printf("Voici les cartes de la colonne %d de %s ",cl,jr.prenom);
            if(jr.deck_nombre[0][cl-1]==13)
                printf("** ");
            else
                printf("%d ",jr.deck_nombre[0][cl-1]);

            if(jr.deck_nombre[1][cl-1]==13)
                printf("** ");
            else
                printf("%d ",jr.deck_nombre[1][cl-1]);

            if(jr.deck_nombre[2][cl-1]==13)
                printf("** ");
            else
                printf("%d ",jr.deck_nombre[1][cl-1]);
            break;

        default:
            printf("choix incorrect");
            choix=0;
            break;
        }
    }
    while (choix==0);//tant que le choix est incorrect
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    system("pause");

}


int verif_carte_def(S_joueur jr)//vérifie si le joueur qu'on a donné en paramètre d'entrée possède une carte défense
{
    int i;
    for(i=0;i<jr.nb_action;i++)
    {
        if(jr.deck_action[i]==19) //carte défense
            return i;
    }
    return 0;
}

