#include "AI.h"
#include <time.h>

char tour_ia_simple(char** grille, char joueur){
    printf("\n\n\nAu tour de %c\n", joueur);

	coup_random(grille, joueur);
    print_grille(grille);

	//on vérifie si le joueur a gagné, si oui on renvoie le char du joueur, sinon on renvoie 0
	if(check_victoire(grille)) return joueur;
	return 0;	
}

void jeu_ia_simple(int ia){
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
        printf("Voulez-vous jouer contre une IA basique (1) ou plus intelligente (2) ?\n");
		choix = 0;
		while(choix < 1 || choix > 2){
			printf("Entrez 1 ou 2\n>");
			scanf("%d", &choix);
		}
		if(choix == 1) jeu_ia_simple(choix_char());
		else if(choix == 2) jeu_ia_moyenne(choix_char());
    }
}

int choix_char(){
	printf("Voulez-vous jouer les X (1), les O (2), ou l'un des deux au hasard (3) ?\n");
        int choix = 0;
        while(choix < 1 || choix > 3){
            printf("Entrez 1, 2 ou 3\n>");
            scanf("%d", &choix);
        }
		//on pioche au hasard si besoin est
		if(choix == 3) choix = rand();
		//on garde la parité dans tous les cas, puisque choix sera utilisé pour définir le char de l'IA, donc l'inverse du choix du joueur
        choix %= 2;
		return choix;
}

void jeu_ia_moyenne(int ia){
   char** grille = init_grille();
	char joueur[2] = {'X', 'O'};
	int compteur = 0;
	//etat prendra la valeur du joueur ayant gagné, tant que etat vaut 0, personne n'a gagné
	char etat = 0;

	//la boucle principale du jeu
	while(true){
        //on vérifie si c'est au tour de l'ia de jouer, et on appelle la fonction de jeu requise
        if(compteur == ia) etat = tour_ia_moyenne(grille, joueur[ia]);
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

char tour_ia_moyenne(char** grille, char joueur){
    printf("\n\n\nAu tour de %c\n", joueur);

	//si la grille est vide, l'ordinateur joue dans un coin
	if(check_grille_vide(grille)){
		joue_coins(grille, joueur);
		return 0;
	}

	//si exactement un coin est rempli, l'ordinateur joue au centre
	if(check_coins(grille)){
		joue_centre(grille, joueur);
		return 0;
	}

	bool tour_termine = false;
	if(tour_termine = coup_victoire(grille, joueur)) return joueur; //on vérifie si l'ordi peut gagner avec un coup, si oui on joue ce coup et on termine le tour
	if(tour_termine = coup_defense(grille, joueur)) return 0; //on vérifie si l'ordi peut empecher l'humain de gagner avec un coup, si oui, on joue ce coup et on termine le tour
	coup_random(grille, joueur);

	
    print_grille(grille);

	//on vérifie si le joueur a gagné, si oui on renvoie le char du joueur, sinon on renvoie 0
	if(check_victoire(grille)) return joueur;
	return 0;	
}

void joue_centre(char** grille, char joueur){
	grille[1][1] = joueur;
}

void joue_coins(char** grille, char joueur){
	int coin;
	int x, y;
	
	while(true){
		coin = rand()%4;
		x = 2*(coin%2); //si coin est pair, on est à gauche de la grille, sinon on est à droite
		y = 2*(coin/2); //su coin > 2, on est en haut de la grille, sinon on est en bas 

		//si le coin est vide, on place le char et on sort de la boucle
		if(grille[y][x] == 0){
			grille[y][x] = joueur;
			break;
		}
	}
}

void coup_random(char** grille, char joueur){
	int x, y;
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
}

bool coup_defense(char** grille, char joueur){
	//on regarde la valeur du char de l'humain pour fair esemblant de jouer à sa place
	char humain = 0;
	if(joueur == 'X') humain = 'O';
	else humain = 'X';

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			//on vérifie d'abord que la case est vide
			if(grille[i][j] == 0){
				grille[i][j] = humain; //on joue un coup dans la case en faisant semblant d'être l'humain
				if(check_victoire(grille)){ //si ce coup est gagnant, on le remplace par un coup de l'ordinateur pour bloquer l'humain
					grille[i][j] = joueur;
					printf("%c joue %d %d.\n", joueur, i, j);
					return true;
				}
				grille[i][j] = 0; //sinon, on le défait
			}
		}
	}

	return false; //si on arrive ici, l'ordinateur n'a pas joué
}

bool coup_victoire(char** grille, char joueur){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			//on vérifie d'abord que la case est vide
			if(grille[i][j] == 0){
				grille[i][j] = joueur; //on joue un coup dans la case
				if(check_victoire(grille)) { //si ce coup est gagnant, on le joue vraiment
						printf("%c joue %d %d.\n", joueur, i, j);
						return true; 
					}
				grille[i][j] = 0; //sinon, on le défait
			}
		}
	}

	return false; //si on arrive ici, l'ordinateur n'a pas joué
}