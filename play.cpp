#include "play.hpp"

short vies = 3;
int score = 0;

int nombreChiffre(int nb){
	int cmp = 1;
	while((nb = (nb / 10))){
		cmp++;
	}
	return cmp;	
}

char* itoa(int entier){
	int taille = nombreChiffre(entier);
	char* nombre = (char*) malloc((taille + 1) * sizeof(char));
	int i,chiffre;
	for(i = taille - 1; i >= 0; i--){
		chiffre = entier % 10;
		nombre[i] = chiffre + '0';
		entier /= 10;
	}
	nombre[taille] = '\0';
	return nombre;
}

void play(Fenetre &w){
	
}
