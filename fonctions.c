#include "fonctions.h"

char** init_grille(){
	char** grille = NULL;
	grille = malloc(9*sizeof(char));
	if(grille == NULL) exit(1);
	for(int i = 0; i < 3; i++){
		grille[i] = calloc(3, sizeof(char));
		if(grille[i] == NULL) exit(1);
	}

	return grille;
}

void print_grille(char** grille){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(grille[i][j] == 0) printf("▯");
			else printf("%c",grille[i][j]);
		}
		printf("\n");
	}
}

void free_grille(char** grille){
	for(int i = 0; i < 3; i++)
		free(grille[i]);
	free(grille);
}

char tour(char** grille, char joueur){
	int x, y;
	//on reste dans cette boucle tant que le joueur n'a pas entré un coup valide
	while(true){
		x = y = -1;
		printf("\n\n\nAu tour de %c\n", joueur);
		print_grille(grille);

		//on demande au joueur d'entrer une ligne tant qu'il n'a pas entré un nombre valide
		while(x < 0 || x > 2){ 
			printf("Ligne ? (0, 1, 2)\n>");
			scanf("%d", &x);
		}

		//même chose avec la ligne
		while(y < 0 || y > 2){ 
			printf("Colonne ? (0, 1, 2)\n>");
			scanf("%d", &y);
		}

		//on vérifie que le coup est valide, si oui on place le char et on sort de la boucle
		if(grille[x][y] == 0){
			grille[x][y] = joueur;
			break;
		}
	}
	//on vérifie si le joueur a gagné, si oui on renvoie le char du joueur, sinon on renvoie 0
	if(check_victoire(grille)) return joueur;
	return 0;	
}

bool check_victoire(char** grille){
	bool victoire = false;

	//on vérifie toutes les lignes, toutes les diagonales et toutes les colonnes
	//on vérifie également, à chaque fois, que les char ne sont pas vides
	victoire = (
		  ((grille[0][0] == grille[0][1]) && (grille[0][0] == grille[0][2]) && grille[0][0])//ligne 0
		||((grille[1][0] == grille[1][1]) && (grille[1][0] == grille[1][2]) && grille[1][0])//ligne 1
		||((grille[2][0] == grille[2][1]) && (grille[2][0] == grille[2][2]) && grille[2][0])//ligne 2
		||((grille[0][0] == grille[1][0]) && (grille[0][0] == grille[2][0]) && grille[0][0])//colonne 0
		||((grille[0][1] == grille[1][1]) && (grille[0][1] == grille[2][1]) && grille[0][1])//colonne 1
		||((grille[0][2] == grille[1][2]) && (grille[0][2] == grille[2][2]) && grille[0][2])//colonne 2
		||((grille[0][0] == grille[1][1]) && (grille[0][0] == grille[2][2]) && grille[0][0])//diagonale 1
		||((grille[0][2] == grille[1][1]) && (grille[0][2] == grille[2][0]) && grille[0][2])//diagonale 1
	);

	return victoire;
}

bool check_nulle(char** grille){
	//on parcourt toutes les cases de la grille
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			//si l'une d'elle est vide, la partie n'est pas nulle
			if(grille[i][j] == 0) return false;
		}
	}
	return true;
}

void jeu(){
	char** grille = init_grille();
	char joueur[2] = {'X', 'O'};
	int compteur = 0;
	//etat prendra la valeur du joueur ayant gagné, tant que etat vaut 0, personne n'a gagné
	char etat = 0;

	//la boucle principale du jeu
	while(true){
		etat = tour(grille, joueur[compteur]);
		//si un joueur a gagné ou si la partie est nulle, on sort du jeu
		if(etat || check_nulle(grille)) break;
		//sinon, on passe au joueur suivant
		compteur++;
		compteur %= 2;
	}

	if(!etat) printf("Match nul !\n");
	else printf("Félicitations %c !\n", etat);

	//on libère la grille avant de partir
	free_grille(grille);
}