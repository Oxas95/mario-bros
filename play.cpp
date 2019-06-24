#include "play.hpp"
#include "carte.hpp"
#include "solid_block.hpp"
#include "texture.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

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
	Carte c;
	int i;
	for(i = 0; i < nbCasesX; i+= 2){
		Block* b = new Solid_block(ground, day, i, nbCasesY - 2);
		c.ajoutBlock(b,false);
	}
	w.clear();
	c.draw(w);
	w.display();
	bool continuer = true;
	sf::Keyboard::Key k;
	bool pressed;
	
	while(continuer){
		k = w.getKey(pressed);
		if(k == sf::Keyboard::Escape || !w.isOpen()) continuer = false;
		if(k == sf::Keyboard::Space && pressed) c.joueur.changeSprite(jump);
		if(k == sf::Keyboard::Space && !pressed) c.joueur.changeSprite(stop);
		if(k == sf::Keyboard::Left && pressed) c.joueur.turnLeft(w.getZoom()),c.joueur.changeSprite(run);
		if(k == sf::Keyboard::Right && pressed) c.joueur.turnRight(w.getZoom()),c.joueur.changeSprite(run);
		if((k == sf::Keyboard::Right || k == sf::Keyboard::Left) && !pressed) c.joueur.changeSprite(stop);
		w.clear();
		c.draw(w);
		w.display();
	}
}
