#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#define CARTE_JOUEUR_NOMBRE_L 3             //dimension du plateau de jeu 3 lignes x 4 colonnes
#define CARTE_JOUEUR_NOMBRE_C 4             //idem

#define CARTE_PIOCHE_ACTION_NB 27           //il n'y a pas de limite sur le nombre de carte action dans le jeu d'un joueur, il peut donc avoir les 27 cartes dans son jeu
#define CARTE_PIOCHE_ACTION_FACE_VISIBLE 4  //voir r�gle jeu

#define CARTE_PIOCHE_NOMBRE_NB 120          //il y a en tout 120 cartes de jeu

#define DIM_STR 20


struct joueur
{
                char deck_nombre [CARTE_JOUEUR_NOMBRE_L][CARTE_JOUEUR_NOMBRE_C]; //prenant de -2 � 13 + pas de carte->30
                char deck_nombre_cache [CARTE_JOUEUR_NOMBRE_L][CARTE_JOUEUR_NOMBRE_C]; //0 si carte cach�, 1 si carte visible
                char deck_action[CARTE_JOUEUR_ACTION_NB]; //prenant de 14 � 22
                char prenom [DIM_STR]; //nom du joueur
                char score; // 0 � 255


};
typedef struct joueur S_joueur


struct pioche
{
                char nombre[CARTE_PIOCHE_NOMBRE_NB]; //tableau de la pioche des nombres � remplir et � "m�langer"
                char nombre_defausse[CARTE_PIOCHE_NOMBRE_NB]; //pr�voir de refaire la pioche nombre quand celle ci est �puis�.
                char nombre_defausse_dessous[9]; //il ne peut avoir qu'au maximum 9 cartes sous la pioche par manche.
                char nombre_nb; //dans l'absolu pas besoin, a discuter


                char action[CARTE_PIOCHE_ACTION_NB]; //tableau de la pioche des actions � remplir et � "m�langer"
                char action_visible[CARTE_PIOCHE_ACTION_FACE_VISIBLE]; //les 4 cartes acrtions pr�sent�es
                char action_nb; //dans l'absolu pas besoin, � discuter



                //apr�s chaque manche, les pioches sont r�initialis�es
};

typedef struct pioche S_pioche;

#endif // DECLARATION_H_INCLUDED
