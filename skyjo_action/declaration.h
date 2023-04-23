#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#define CARTE_JOUEUR_NOMBRE_L 3             //dimension du plateau de jeu 3 lignes x 4 colonnes
#define CARTE_JOUEUR_NOMBRE_C 4             //idem

#define CARTE_PIOCHE_ACTION_NB 27           //il y a 27 cartes actions dans le jeu
#define CARTE_PIOCHE_ACTION_FACE_VISIBLE 4  //voir r�gle jeu

#define CARTE_PIOCHE_NOMBRE_NB 120          //il y a en tout 120 cartes nombres dans le jeu

#define DIM_STR 10

typedef struct pioche S_pioche; //attention, il n'y aura pas de tableau de S_pioche, juste une variable

struct etoile
{
    int ligne;
    int colonne;
};
typedef struct etoile S_etoile;

struct joueur
{
                int joueur_no; //num�ro du joueur (de 1 � 4), facilitant la r�cup�ration d'information.

                int deck_nombre [CARTE_JOUEUR_NOMBRE_L][CARTE_JOUEUR_NOMBRE_C]; //prenant de -2 � 13 + pas de carte->30
                int deck_nombre_cache [CARTE_JOUEUR_NOMBRE_L][CARTE_JOUEUR_NOMBRE_C]; //0 si carte cach�, 1 si carte visible
                int deck_action[CARTE_PIOCHE_ACTION_NB]; //le joueur n'a pas de limite de carte action, il peux donc prendre les 27 cartes actions
                int nb_action; //nombre de carte action dans le jeu du joueur.
                char prenom [DIM_STR]; //nom du joueur
                int score; //score du joueur
                S_etoile pos_etoile[13]; //position des hypoth�tiques cartes �toiles dans le jeu.
                int nb_etoile; //nombres d'�toiles dont le joueur � atribu� un chiffre
                int nb_skyjo_ligne;
                int nb_skyjo_colonne;

};
typedef struct joueur S_joueur;


struct pioche
{
                int nombre[CARTE_PIOCHE_NOMBRE_NB]; //tableau de la pioche des nombres � remplir et � "m�langer"
                int nombre_nb;
                int nombre_defausse[CARTE_PIOCHE_NOMBRE_NB]; //pr�voir de refaire la pioche nombre quand celle ci est �puis�.
                int nombre_defausse_nb;
                int nombre_defausse_dessous[9]; //il ne peut avoir qu'au maximum 9 cartes sous la pioche par manche.
                int nombre_defausse_dessous_nb;



                int action[CARTE_PIOCHE_ACTION_NB]; //tableau de la pioche des actions � remplir et � "m�langer"
                int action_nb;
                int action_visible[CARTE_PIOCHE_ACTION_FACE_VISIBLE]; //les 4 cartes acrtions pr�sent�es
                int action_defausse[CARTE_PIOCHE_ACTION_NB];
                int action_defausse_nb;





                //apr�s chaque manche, les pioches sont r�initialis�es
                //c-a-d, nombre retrouve sa config initiale, et les defausses sont mises � z�ro
};



#endif // DECLARATION_H_INCLUDED
