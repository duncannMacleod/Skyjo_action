#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#define CARTE_JOUEUR_NOMBRE_L 3             //dimension du plateau de jeu 3 lignes x 4 colonnes
#define CARTE_JOUEUR_NOMBRE_C 4             //idem

#define CARTE_PIOCHE_ACTION_NB 27           //il n'y a pas de limite sur le nombre de carte action dans le jeu d'un joueur, il peut donc avoir les 27 cartes dans son jeu
#define CARTE_PIOCHE_ACTION_FACE_VISIBLE 4  //voir règle jeu

#define CARTE_PIOCHE_NOMBRE_NB 120          //il y a en tout 120 cartes de jeu

#define DIM_STR 20


struct joueur
{
                int deck_nombre [CARTE_JOUEUR_NOMBRE_L][CARTE_JOUEUR_NOMBRE_C]; //prenant de -2 à 13 + pas de carte->30
                int deck_nombre_cache [CARTE_JOUEUR_NOMBRE_L][CARTE_JOUEUR_NOMBRE_C]; //0 si carte caché, 1 si carte visible
                int deck_action[CARTE_JOUEUR_ACTION_NB]; //prenant de 14 à 22
                char prenom [DIM_STR]; //nom du joueur
                int score;


};
typedef struct joueur S_joueur


struct pioche
{
                int nombre[CARTE_PIOCHE_NOMBRE_NB]; //tableau de la pioche des nombres à remplir et à "mélanger"
                int nombre_defausse[CARTE_PIOCHE_NOMBRE_NB]; //prévoir de refaire la pioche nombre quand celle ci est épuisé.
                int nombre_defausse_dessous[9]; //il ne peut avoir qu'au maximum 9 cartes sous la pioche par manche.
                int nombre_nb; //dans l'absolu pas besoin, a discuter


                int action[CARTE_PIOCHE_ACTION_NB]; //tableau de la pioche des actions à remplir et à "mélanger"
                int action_visible[CARTE_PIOCHE_ACTION_FACE_VISIBLE]; //les 4 cartes acrtions présentées
                int action_nb; //dans l'absolu pas besoin, à discuter



                //après chaque manche, les pioches sont réinitialisées
};

typedef struct pioche S_pioche;

#endif // DECLARATION_H_INCLUDED
