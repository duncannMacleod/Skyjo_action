#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#include "affichage.h"
#include "declaration.h"
#include "suivi_score.h"
#include "initialisation.h"
#include "deroulement_tour.h"
#include "deplacements_cartes.h"


int etoile_presente(S_joueur jr,int ligne, int colonne) //détermine si une carte étoile est présente a une coordonée d'un deck
{
    int i;
    for(i=0; i<jr.nb_etoile+1; i++)
        if(jr.pos_etoile[i].ligne==ligne&&jr.pos_etoile[i].colonne==colonne)
            return 1;

    return 0;
}

void recup_carte_nombre_pioche(S_joueur *jr,S_pioche *p,int x,int y) //gestion des cartes quand on récupère une carte action de la pioche
{
    int cpt,ligne=0,colonne=0,reponse,etoile_recuperee=0;

    char choix,c;

    int carte_pioche=tirer_carte(p); //tire une carte de la pioche

    if(carte_pioche==13)//si c'est une carte étoile on lui donne une nouvelle valeur et la variable etoile_recuperee passe a 1, cela est pour l'inscrire apres que l'utilisateur aura rentré les cordonnées de la carte
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de piocher une carte étoile,");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("quelle est la valeur que vous voulez lui donner?");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%d",&reponse);
        carte_pioche=reponse;
        etoile_recuperee=1;//important pour la suite du code, permet de savoir que la carte pioché etait une ancienne carte étoile
        getchar();//vide la mémoire tampon
    }
    do
    {
        cpt=0;
        afficher_boite_dialogue();//réiniatise la partie basse de l'affichage
        Positionner_Curseur(x,y);
        printf("Vous avez pioché une carte %d! Que voulez vous faire? ",carte_pioche);

        cpt+=1;
        Positionner_Curseur(x,y+cpt);
        printf("La Placer P, ou la jeter dans la Défausse D");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF); //vide la mémoire tampon
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'P'://place la carte dans le jeu
            demande_l_c (&ligne,&colonne,x,y);
            swap_carte(jr,p,carte_pioche,ligne,colonne);//jette l'ancienne carte et place carte_pioche aux cordonnées entrées
            if(etoile_recuperee==1)//inscrit les cordonnées de la carte au registre des cartes actions du joueur, pour que celle ci soit bien compté comme carte action
            {
                jr->nb_etoile++;
                jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;
                jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;
            }

            choix=1;
            break;

        case 'D'://jete la carte dans la défausse
            retourne_carte(jr,p,x,y,1,carte_pioche,0,0);//le joueur doit tout de meme jeter la carte, et retourner une carte de son jeu
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
    while (choix==0);//tant que le choix n'est pas bon "default"
    cpt++;
    Positionner_Curseur(x,y+cpt);


}

void demande_l_c (int *ligne,int *colonne,int x,int y)
{
    afficher_boite_dialogue(); //réiniatise la partie basse l'affichage
    int cpt=0;
    Positionner_Curseur(x,y+cpt);
    printf("Quelle carte voulez vous remplacer dans votre jeu");
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    do
    {
        Positionner_Curseur(x,y+cpt);
        printf("Attention, ligne de 1 à 3 \"espace\" colonne de 1 à 4:              ");
        Positionner_Curseur(x+46,y+cpt);
        scanf("%d %d",ligne,colonne);
        (*ligne)--;
        (*colonne)--;
    }
    while(*ligne>3||*ligne<0||*colonne>4||*colonne<0); //tant que les lignes et les colonnes choisies soient correctes

}

void recup_carte_nombre_defausse(S_joueur *jr,S_pioche *p,int x,int y)//gestion de la récupération d'une carte nombre de la défausse
{
    int cpt,carte_pioche,ligne,colonne,reponse,etoile_recuperee=0;

    carte_pioche=p->nombre_defausse[p->nombre_defausse_nb-1];

    p->nombre_defausse_nb--;//décrémente le nombre de carte nomvre dans la pioche
    if(p->nombre_defausse_nb==0)//si il n'a plus de carte dans la pioche
        p->nombre_defausse[0]=30; //écrit 30 dans la première case du tableau
    afficher_actualiser_defausse_nombre(*p); //montre bien que l'on vient de piocher la carte de la pioche

    if(carte_pioche==13)//si la carte pioché est une carte étoile
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de récupérer une carte étoile,");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf(" quelle est la valeur que vous voulez lui donner?");
        printf("Réponse:");
        scanf("%d",&reponse);
        carte_pioche=reponse;
        etoile_recuperee=1;
    }

    cpt=0;
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Vous avez récupéré une carte %d!",carte_pioche);
    demande_l_c (&ligne,&colonne,x,y+cpt);//demande les cordonnées pour placer la carte
    swap_carte(jr,p,carte_pioche,ligne,colonne); //place la nouvelle carte et jette l'ancienne
    if(etoile_recuperee==1) //si la carte qui a été pioché était une carte étoile
    {
        jr->nb_etoile++;
        jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;
        jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;
    }
    cpt+=4; Positionner_Curseur(x,y+cpt);



}

void swap_carte(S_joueur *jr, S_pioche *p,int carte_pioche,int ligne,int colonne)//jette la carte remplacée et la remplace dans le jeu du joueur par carte_pioche
{
    if(etoile_presente(*jr,ligne,colonne))//si la carte qui va etre jeté est une ancienne carte étoile, elle reprend son état initial "13"
    {
        supprimer_pos_etoile (jr,ligne,colonne);
    }
    p->nombre_defausse_nb++;
    p->nombre_defausse[p->nombre_defausse_nb-1]=jr->deck_nombre[ligne][colonne]; //écrit la valeur de la carte jetée dans la n-ième case de la défausse ici elles sont ajoutées de 0 à 120
    jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
    jr->deck_nombre_cache[ligne][colonne]=1; //retourne la carte tout juste déposé (l'état précédant de la case n'est pas pris en compte)
}


int tirer_carte(S_pioche *p)
{
    int carte_pioche=p->nombre[p->nombre_nb-1]; //la variable carte pioché prend la valeur de la première carte sur le paquet
    p->nombre[p->nombre_nb-1]=30; //supprime la carte du paquet
    p->nombre_nb--; //enlève un au nombre de cartes
    return carte_pioche;
}
void retourne_carte(S_joueur *jr,S_pioche *p,int x,int y,int parametre,int carte_pioche1,int carte_pioche2,int carte_pioche3)
{
    int cpt=0,ligne,colonne,reponse; //conversationnel
    afficher_boite_dialogue();
    printf("vous devez tout de même rerourner une carte. entrez les coordonées pour la carte");
    cpt+=1;
    Positionner_Curseur(x,y+cpt);
    do
    {
        Positionner_Curseur(x,y+cpt);
        printf("Attention, ligne de 1 à 3 et colonne de 1 à 4:              ");
        Positionner_Curseur(x+46,y+cpt);
        scanf("%d %d",&ligne,&colonne);
        ligne--;
        colonne--;
        if(ligne>3||ligne<0||colonne>4||colonne<0)//si les valeurs ne sont pas bonne on vide la mémoire tampon pour pouvoir recomencer
            getchar();
    }
    while(ligne>3||ligne<0||colonne>4||colonne<0);//tant que les valeurs des cordonnées sont corectes
    if(jr->deck_nombre[ligne][colonne]==13)
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de retourner une carte étoile,");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("quelle est la valeur que vous voulez lui donner?");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("Réponse:");
        scanf("%d",&reponse);
        jr->deck_nombre[ligne][colonne]=reponse;//on écrit la nouvelle valeur de la carte sur l'ancienne valeur
        jr->nb_etoile++;//on incrémene le nombre d'étoiles présentes dans le jeu
        jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;//on enregiste la position de l'étoile dans le registe pos_etoile
        jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;//suite
    }
    jr->deck_nombre_cache[ligne][colonne]=1;

    if(parametre==1) //on retoune 1 carte dans la pioche
    {
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche1; //écrit la valeur de la carte pioché dans la n-ième case de la défausse ici elles sont ajoutées de 0 à 120
    }
    else if(parametre==2) //on retourne 2 cartes dans la pioche (cette option n'est jamais utilisé dans le jeu)
    {
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche1;
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche2;
    }
    else if(parametre==3) //on retourne 3 cartes dans la pioche
    {
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche1;
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche2;
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche3;
    }

}



void recup_carte_action_presente(S_joueur *jr,S_pioche *p,int x,int y)//gère la récupération de carte action face visible
{
    int cpt,c_choisi;
    do
    {
        cpt=0;
        c_choisi=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("quelle carte voulez vous piocher (1à4)");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("Réponse: ");
        scanf("%d",&c_choisi);
        if(c_choisi<1||c_choisi>4) //si le nombre est inorrect, on supprime la mémoire tampon pour ne pas coincer le programme
            getchar();
    }while(c_choisi<1||c_choisi>4);
    jr->nb_action++; //on incrémente le nombre de carte action du joueur
    jr->deck_action[jr->nb_action-1]=p->action_visible[c_choisi-1];//on place la carte action choisie par le joueur dans son jeu
    p->action_visible[c_choisi-1]=p->action[p->action_nb-1];//on remet une carte action à la place de celle qui a été pioché
    p->action_nb--;//on décrémente le nombre de carte action (pioche)


}
void recup_carte_action_pioche(S_joueur *jr,S_pioche *p,int x,int y)//gère la récupération de carte action venant de la pioche (aléatoire)
{
    int carte_pioche;

    carte_pioche=p->action[p->action_nb-1];//carte_pioche prend la valeur de la carte action du haut de la pioche
    p->action_nb--;//décrémentation du nombre de carte action

    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Vous venez de piocher la carte ");
    afficher_action(carte_pioche);//affichage ergonomique de la carte action
    printf("!");
    jr->nb_action++;//on incrémente le nombre de carte action du joueur
    jr->deck_action[jr->nb_action-1]=carte_pioche;//on inscit cette nouvelle carte dans le deck des cartes action du joueur à la bonne place

}


void placer_carte_piochee(S_joueur *jr,S_pioche *p,int ligne, int colonne,int parametre)
{
    int carte_pioche=tirer_carte(p);//tire la carte de la pioche des cartes nombres
    jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
    jr->deck_nombre_cache[ligne][colonne]=1;//retourne la carte
    if(parametre==1)//si le parametre est 1, la carte va dans la défausse "normale" pour etre possiblement repioché
    {
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche; //écrit la valeur de la carte pioché dans la n-ième case de la défausse ici elles sont ajoutées de 0 à 120
    }
    if(parametre==2)//si le parametre est a 2, les cartes vont "sous la défausse des cartes nombres"
    {
        p->nombre_defausse_dessous_nb++;
        p->nombre_defausse_dessous[p->nombre_defausse_dessous_nb-1]=carte_pioche; //écrit la valeur de la carte pioché dans la n-ième case de la défausse ici elles sont ajoutées de 0 à 120
    }
}

void deplacer_carte_jeu(S_joueur *j1,S_joueur *j2,int x1,int y1,int x2,int y2)//déplace deux cartes entre deux jeu (les jeux peuvent etre les memes)
{
    int tampon_carte, tampon_carte_cachee;
    tampon_carte=j1->deck_nombre[y1][x1];//stocke dans tampon_carte pour qu'en suite puisse écrire des nouvelles données sans perdre les anciennes
    tampon_carte_cachee=j1->deck_nombre_cache[y1][x1];
    j1->deck_nombre[y1][x1]=j2->deck_nombre[y2][x2];//copie des infos de j2 àj1
    j1->deck_nombre_cache[y1][x1]=j2->deck_nombre_cache[y2][x2];
    j2->deck_nombre[y2][x2]=tampon_carte;//copie des infos des variables tampons à j2
    j2->deck_nombre_cache[y2][x2]=tampon_carte_cachee;

}

void supprimer_pos_etoile (S_joueur *jr,int ligne,int colonne)//si une carte est présente aux cordonnées entrées, le programme supprime cette information
{
    int i,j;
    for(i=0; i<jr->nb_etoile; i++)
        if(jr->pos_etoile[i].ligne==ligne||jr->pos_etoile[i].colonne==colonne)//si les ligne et colonne entrées correspondent à une étoile parmis le tableau pos_etoile;
            for(j=i; i<jr->nb_etoile; j++)
            {
                jr->pos_etoile[j]=jr->pos_etoile[j+1];//alors cette donnée est "supprimé" en écrivant les suivantes dessus
            }
    jr->nb_etoile--;//on enlève 1 au nombre d'étoile présent dans le jeu du joueur
}
