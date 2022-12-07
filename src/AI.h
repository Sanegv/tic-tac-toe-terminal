#include "fonctions.h"

/**
 * @brief affiche le menu du jeu : propose de jouer à un ou deux joueurs, et lance la fonction requise en conséquence
 * 
 */
void menu();

/**
 * @brief prend en entrée le numéro de l'ordinateur (0 ou 1) (et plus tard la difficulté de l'ia) et joue une partie
 * 
 * @param ia 
 */
void jeu_ia(int ia);

/**
 * @brief sélectionne une case vide aléatoire, et y place le char de l'ordinateur 
 * 
 * @param grille 
 */
char tour_ia_simple(char** grille, char joueur);