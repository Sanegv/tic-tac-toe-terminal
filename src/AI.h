#include "fonctions.h"

/**
 * @brief affiche le menu du jeu : propose de jouer à un ou deux joueurs, et lance la fonction requise en conséquence
 * 
 */
void menu();

/**
 * @brief prend en entrée le numéro de l'ordinateur (0 ou 1) et joue une partie en utilisant des coups aléatoires
 * 
 * @param ia 
 */
void jeu_ia_simple(int ia);

/**
 * @brief sélectionne une case vide aléatoire, et y place le char de l'ordinateur 
 * 
 * @param grille 
 */
char tour_ia_simple(char** grille, char joueur);

/**
 * @brief prend en entrée le numéro de l'ortdinateur (0 ou 1) et joue une partie en utilisant des coups réfléchis
 * 
 * @param ia 
 */
void jeu_ia_moyenne(int ia);

/**
 * @brief joue un coup soit pour la victoire, soit pour éviter la défaite, sans réfléchir au delà d'un coup d'avance
 * 
 * @param grille 
 * @param joueur 
 * @return char 
 */
char tour_ia_moyenne(char** grille, char joueur);

/**
 * @brief demande au joueur quel char il veut jouer, ou s'il veut jouer au hasard, et renvoie l'int correspondant *QUI SERA UTILISÉ POUR L'IA !*
 * 
 * @return int 
 */
int choix_char();

/**
 * @brief joue le char joueur dans l'un des quatre coins au hasard (boucle infinie si tous les coins sont déjà pleins)
 * 
 * @param grille 
 * @param joueur 
 */
void joue_coins(char** grille, char joueur);

/**
 * @brief joue le char joueur au centre
 * 
 * @param grille 
 * @param joueur 
 */
void joue_centre(char** grille, char joueur);

/**
 * @brief vérifie toutes les tuiles non vides de la grille, fait semblant d'y jouer un coup, si ce coup est gagnant, l'ordinateur le joue vraiment
 * 
 * @param grille 
 * @param joueur 
 * @return true 
 * @return false 
 */
bool coup_victoire(char** grille, char joueur);

/**
 * @brief vérifie toutes les tuiles non vides de la grille, fait semblant que l'adversaire y a joué un coup, si le coup de l'adversaire est gagnant, l'ordinateur bloque la tuile
 * 
 * @param grille 
 * @param joueur 
 * @return true 
 * @return false 
 */
bool coup_defense(char** grille, char joueur);

/**
 * @brief joue le char en entrée dans l'une des cases vides de la grille (boucle infinie si la grille est pleine)
 * 
 * @param grille 
 * @param joueur 
 */
void coup_random(char** grille, char joueur);