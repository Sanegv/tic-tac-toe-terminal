#include "AI.h"
#include <time.h>

char tour_ia_simple(char** grille, char joueur){
	int x, y;
    printf("\n\n\nAu tour de %c\n", joueur);

	//on reste dans cette boucle tant que le joueur n'a pas entré un coup valide
	while(true){
		x = rand()%3;
		y = rand()%3;

		//on vérifie que le coup est valide, si oui on place le char et on sort de la boucle
		if(grille[x][y] == 0){
			grille[x][y] = joueur;
            printf("%c joue %d %d.\n", joueur, x, y);
			break;
		}
	}
    print_grille(grille);

	//on vérifie si le joueur a gagné, si oui on renvoie le char du joueur, sinon on renvoie 0
	if(check_victoire(grille)) return joueur;
	return 0;	
}

void jeu_ia(int ia){
    char** grille = init_grille();
	char joueur[2] = {'X', 'O'};
	int compteur = 0;
	//etat prendra la valeur du joueur ayant gagné, tant que etat vaut 0, personne n'a gagné
	char etat = 0;

	//la boucle principale du jeu
	while(true){
        //on vérifie si c'est au tour de l'ia de jouer, et on appelle la fonction de jeu requise
        if(compteur == ia) etat = tour_ia_simple(grille, joueur[ia]);
        else etat = tour_humains(grille, joueur[compteur]);

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

void menu(){
    printf("Bienvenue ! Voulez-vous jouer seul (1) ou contre un autre joueur (2) ?\n");
    int choix = 0;
    while(choix < 1 || choix > 2){
        printf("Entrez 1 ou 2:\n>");
        scanf("%d", &choix);
    }

    if(choix == 2) jeu_humains();
    else {
        printf("Voulez-vous jouer les X (1), les O (2), ou l'un des deux au hasard (3) ?\n");
        choix = 0;
        while(choix < 1 || choix > 3){
            printf("Entrez 1, 2 ou 3\n>");
            scanf("%d", &choix);
        }

        if(choix == 3) choix = rand();
        choix %= 2;
        jeu_ia(choix);
    }
}