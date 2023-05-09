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


int etoile_presente(S_joueur jr,int ligne, int colonne) //d�termine si une carte �toile est pr�sente a une coordon�e d'un deck
{
    int i;
    for(i=0; i<jr.nb_etoile+1; i++)
        if(jr.pos_etoile[i].ligne==ligne&&jr.pos_etoile[i].colonne==colonne)
            return 1;

    return 0;
}

void recup_carte_nombre_pioche(S_joueur *jr,S_pioche *p,int x,int y) //gestion des cartes quand on r�cup�re une carte action de la pioche
{
    int cpt,ligne=0,colonne=0,reponse,etoile_recuperee=0;

    char choix,c;

    int carte_pioche=tirer_carte(p); //tire une carte de la pioche

    if(carte_pioche==13)//si c'est une carte �toile on lui donne une nouvelle valeur et la variable etoile_recuperee passe a 1, cela est pour l'inscrire apres que l'utilisateur aura rentr� les cordonn�es de la carte
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de piocher une carte �toile,");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("quelle est la valeur que vous voulez lui donner?");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("R�ponse:");
        scanf("%d",&reponse);
        carte_pioche=reponse;
        etoile_recuperee=1;//important pour la suite du code, permet de savoir que la carte pioch� etait une ancienne carte �toile
        getchar();//vide la m�moire tampon
    }
    do
    {
        cpt=0;
        afficher_boite_dialogue();//r�iniatise la partie basse de l'affichage
        Positionner_Curseur(x,y);
        printf("Vous avez pioch� une carte %d! Que voulez vous faire? ",carte_pioche);

        cpt+=1;
        Positionner_Curseur(x,y+cpt);
        printf("La Placer P, ou la jeter dans la D�fausse D");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("R�ponse:");
        scanf("%c",&choix);
        while ((c = getchar()) != '\n' && c != EOF); //vide la m�moire tampon
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        switch(toupper(choix))
        {
        case 'P'://place la carte dans le jeu
            demande_l_c (&ligne,&colonne,x,y);
            swap_carte(jr,p,carte_pioche,ligne,colonne);//jette l'ancienne carte et place carte_pioche aux cordonn�es entr�es
            if(etoile_recuperee==1)//inscrit les cordonn�es de la carte au registre des cartes actions du joueur, pour que celle ci soit bien compt� comme carte action
            {
                jr->nb_etoile++;
                jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;
                jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;
            }

            choix=1;
            break;

        case 'D'://jete la carte dans la d�fausse
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
    afficher_boite_dialogue(); //r�iniatise la partie basse l'affichage
    int cpt=0;
    Positionner_Curseur(x,y+cpt);
    printf("Quelle carte voulez vous remplacer dans votre jeu");
    cpt+=2;
    Positionner_Curseur(x,y+cpt);
    do
    {
        Positionner_Curseur(x,y+cpt);
        printf("Attention, ligne de 1 � 3 \"espace\" colonne de 1 � 4:              ");
        Positionner_Curseur(x+46,y+cpt);
        scanf("%d %d",ligne,colonne);
        (*ligne)--;
        (*colonne)--;
    }
    while(*ligne>3||*ligne<0||*colonne>4||*colonne<0); //tant que les lignes et les colonnes choisies soient correctes

}

void recup_carte_nombre_defausse(S_joueur *jr,S_pioche *p,int x,int y)//gestion de la r�cup�ration d'une carte nombre de la d�fausse
{
    int cpt,carte_pioche,ligne,colonne,reponse,etoile_recuperee=0;

    carte_pioche=p->nombre_defausse[p->nombre_defausse_nb-1];

    p->nombre_defausse_nb--;//d�cr�mente le nombre de carte nomvre dans la pioche
    if(p->nombre_defausse_nb==0)//si il n'a plus de carte dans la pioche
        p->nombre_defausse[0]=30; //�crit 30 dans la premi�re case du tableau
    afficher_actualiser_defausse_nombre(*p); //montre bien que l'on vient de piocher la carte de la pioche

    if(carte_pioche==13)//si la carte pioch� est une carte �toile
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de r�cup�rer une carte �toile,");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf(" quelle est la valeur que vous voulez lui donner?");
        printf("R�ponse:");
        scanf("%d",&reponse);
        carte_pioche=reponse;
        etoile_recuperee=1;
    }

    cpt=0;
    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Vous avez r�cup�r� une carte %d!",carte_pioche);
    demande_l_c (&ligne,&colonne,x,y+cpt);//demande les cordonn�es pour placer la carte
    swap_carte(jr,p,carte_pioche,ligne,colonne); //place la nouvelle carte et jette l'ancienne
    if(etoile_recuperee==1) //si la carte qui a �t� pioch� �tait une carte �toile
    {
        jr->nb_etoile++;
        jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;
        jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;
    }
    cpt+=4; Positionner_Curseur(x,y+cpt);



}

void swap_carte(S_joueur *jr, S_pioche *p,int carte_pioche,int ligne,int colonne)//jette la carte remplac�e et la remplace dans le jeu du joueur par carte_pioche
{
    if(etoile_presente(*jr,ligne,colonne))//si la carte qui va etre jet� est une ancienne carte �toile, elle reprend son �tat initial "13"
    {
        supprimer_pos_etoile (jr,ligne,colonne);
    }
    p->nombre_defausse_nb++;
    p->nombre_defausse[p->nombre_defausse_nb-1]=jr->deck_nombre[ligne][colonne]; //�crit la valeur de la carte jet�e dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120
    jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
    jr->deck_nombre_cache[ligne][colonne]=1; //retourne la carte tout juste d�pos� (l'�tat pr�c�dant de la case n'est pas pris en compte)
}


int tirer_carte(S_pioche *p)
{
    int carte_pioche=p->nombre[p->nombre_nb-1]; //la variable carte pioch� prend la valeur de la premi�re carte sur le paquet
    p->nombre[p->nombre_nb-1]=30; //supprime la carte du paquet
    p->nombre_nb--; //enl�ve un au nombre de cartes
    return carte_pioche;
}
void retourne_carte(S_joueur *jr,S_pioche *p,int x,int y,int parametre,int carte_pioche1,int carte_pioche2,int carte_pioche3)
{
    int cpt=0,ligne,colonne,reponse; //conversationnel
    afficher_boite_dialogue();
    printf("vous devez tout de m�me rerourner une carte. entrez les coordon�es pour la carte");
    cpt+=1;
    Positionner_Curseur(x,y+cpt);
    do
    {
        Positionner_Curseur(x,y+cpt);
        printf("Attention, ligne de 1 � 3 et colonne de 1 � 4:              ");
        Positionner_Curseur(x+46,y+cpt);
        scanf("%d %d",&ligne,&colonne);
        ligne--;
        colonne--;
        if(ligne>3||ligne<0||colonne>4||colonne<0)//si les valeurs ne sont pas bonne on vide la m�moire tampon pour pouvoir recomencer
            getchar();
    }
    while(ligne>3||ligne<0||colonne>4||colonne<0);//tant que les valeurs des cordonn�es sont corectes
    if(jr->deck_nombre[ligne][colonne]==13)
    {
        cpt=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("vous venez de retourner une carte �toile,");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("quelle est la valeur que vous voulez lui donner?");
        cpt++;
        Positionner_Curseur(x,y+cpt);
        printf("R�ponse:");
        scanf("%d",&reponse);
        jr->deck_nombre[ligne][colonne]=reponse;//on �crit la nouvelle valeur de la carte sur l'ancienne valeur
        jr->nb_etoile++;//on incr�mene le nombre d'�toiles pr�sentes dans le jeu
        jr->pos_etoile[jr->nb_etoile-1].ligne=ligne;//on enregiste la position de l'�toile dans le registe pos_etoile
        jr->pos_etoile[jr->nb_etoile-1].colonne=colonne;//suite
    }
    jr->deck_nombre_cache[ligne][colonne]=1;

    if(parametre==1) //on retoune 1 carte dans la pioche
    {
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche1; //�crit la valeur de la carte pioch� dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120
    }
    else if(parametre==2) //on retourne 2 cartes dans la pioche (cette option n'est jamais utilis� dans le jeu)
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



void recup_carte_action_presente(S_joueur *jr,S_pioche *p,int x,int y)//g�re la r�cup�ration de carte action face visible
{
    int cpt,c_choisi;
    do
    {
        cpt=0;
        c_choisi=0;
        afficher_boite_dialogue();
        Positionner_Curseur(x,y);
        printf("quelle carte voulez vous piocher (1�4)");
        cpt+=2;
        Positionner_Curseur(x,y+cpt);
        printf("R�ponse: ");
        scanf("%d",&c_choisi);
        if(c_choisi<1||c_choisi>4) //si le nombre est inorrect, on supprime la m�moire tampon pour ne pas coincer le programme
            getchar();
    }while(c_choisi<1||c_choisi>4);
    jr->nb_action++; //on incr�mente le nombre de carte action du joueur
    jr->deck_action[jr->nb_action-1]=p->action_visible[c_choisi-1];//on place la carte action choisie par le joueur dans son jeu
    p->action_visible[c_choisi-1]=p->action[p->action_nb-1];//on remet une carte action � la place de celle qui a �t� pioch�
    p->action_nb--;//on d�cr�mente le nombre de carte action (pioche)


}
void recup_carte_action_pioche(S_joueur *jr,S_pioche *p,int x,int y)//g�re la r�cup�ration de carte action venant de la pioche (al�atoire)
{
    int carte_pioche;

    carte_pioche=p->action[p->action_nb-1];//carte_pioche prend la valeur de la carte action du haut de la pioche
    p->action_nb--;//d�cr�mentation du nombre de carte action

    afficher_boite_dialogue();
    Positionner_Curseur(x,y);
    printf("Vous venez de piocher la carte ");
    afficher_action(carte_pioche);//affichage ergonomique de la carte action
    printf("!");
    jr->nb_action++;//on incr�mente le nombre de carte action du joueur
    jr->deck_action[jr->nb_action-1]=carte_pioche;//on inscit cette nouvelle carte dans le deck des cartes action du joueur � la bonne place

}


void placer_carte_piochee(S_joueur *jr,S_pioche *p,int ligne, int colonne,int parametre)
{
    int carte_pioche=tirer_carte(p);//tire la carte de la pioche des cartes nombres
    jr->deck_nombre[ligne][colonne]=carte_pioche;//pose la carte de la pioche dans le jeu
    jr->deck_nombre_cache[ligne][colonne]=1;//retourne la carte
    if(parametre==1)//si le parametre est 1, la carte va dans la d�fausse "normale" pour etre possiblement repioch�
    {
        p->nombre_defausse_nb++;
        p->nombre_defausse[p->nombre_defausse_nb-1]=carte_pioche; //�crit la valeur de la carte pioch� dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120
    }
    if(parametre==2)//si le parametre est a 2, les cartes vont "sous la d�fausse des cartes nombres"
    {
        p->nombre_defausse_dessous_nb++;
        p->nombre_defausse_dessous[p->nombre_defausse_dessous_nb-1]=carte_pioche; //�crit la valeur de la carte pioch� dans la n-i�me case de la d�fausse ici elles sont ajout�es de 0 � 120
    }
}

void deplacer_carte_jeu(S_joueur *j1,S_joueur *j2,int x1,int y1,int x2,int y2)//d�place deux cartes entre deux jeu (les jeux peuvent etre les memes)
{
    int tampon_carte, tampon_carte_cachee;
    tampon_carte=j1->deck_nombre[y1][x1];//stocke dans tampon_carte pour qu'en suite puisse �crire des nouvelles donn�es sans perdre les anciennes
    tampon_carte_cachee=j1->deck_nombre_cache[y1][x1];
    j1->deck_nombre[y1][x1]=j2->deck_nombre[y2][x2];//copie des infos de j2 �j1
    j1->deck_nombre_cache[y1][x1]=j2->deck_nombre_cache[y2][x2];
    j2->deck_nombre[y2][x2]=tampon_carte;//copie des infos des variables tampons � j2
    j2->deck_nombre_cache[y2][x2]=tampon_carte_cachee;

}

void supprimer_pos_etoile (S_joueur *jr,int ligne,int colonne)//si une carte est pr�sente aux cordonn�es entr�es, le programme supprime cette information
{
    int i,j;
    for(i=0; i<jr->nb_etoile; i++)
        if(jr->pos_etoile[i].ligne==ligne||jr->pos_etoile[i].colonne==colonne)//si les ligne et colonne entr�es correspondent � une �toile parmis le tableau pos_etoile;
            for(j=i; i<jr->nb_etoile; j++)
            {
                jr->pos_etoile[j]=jr->pos_etoile[j+1];//alors cette donn�e est "supprim�" en �crivant les suivantes dessus
            }
    jr->nb_etoile--;//on enl�ve 1 au nombre d'�toile pr�sent dans le jeu du joueur
}
