#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief initialise un tableau de 3*3 char qui servira de grille de jeu
 * 
 * @return char** 
 */
char** init_grille();

/**
 * @brief affiche la grille dans le terminal
 * 
 */
void print_grille(char** grille);

/**
 * @brief libère la mémoire allouée pour la grille
 * 
 * @param grille 
 */
void free_grille(char** grille);

/**
 * @brief place le char du joueur dans la grille donnée en entrée. 
 * Renvoie également le char du joueur si celui-ci gagne, 0 sinon. 
 * 
 * @param grille 
 * @param joueur 
 * @return char 
 */
char tour_humains(char** grille, char joueur);

/**
 * @brief vérifie qu'un des joueurs a gagné
 * 
 * @param grille 
 * @return true 
 * @return false 
 */
bool check_victoire(char** grille);

/**
 * @brief vérifie qu'il reste des cases libres
 * 
 * @param grille 
 * @return true 
 * @return false 
 */
bool check_nulle(char** grille);

/**
 * @brief appelle toutes les fonctions précédentes pour faire une partie
 * 
 */
void jeu_humains();

/**
 * @brief renvoie true si la grille est vide, faux sinon
 * 
 * @param grille 
 * @return bool
 */
bool check_grille_vide(char** grille);

/**
 * @brief renvoie vrai si exactement l'un des coins est rempli, mais que le reste de la grille est vide, renvoie faux si toute la grille est vide
 * 
 * @param grille 
 * @return true 
 * @return false 
 */
bool check_coins(char** grille);