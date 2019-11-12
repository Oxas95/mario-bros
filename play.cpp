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

int zoom;
void funcRun(Player* joueur){
	sf::Clock chronoR;
	sf::Clock chronoM;
	sf::Time run = sf::milliseconds(0);  //temps du gif de mario qui avance
	sf::Time move = sf::milliseconds(20); //temps de déplacement
	sf::Time elapsedR;
	sf::Time elapsedM;
	int i = 0;
	while(joueur->getActionBody() == actionBody::run || joueur->getActionBody() == actionBody::sprint || joueur->getActionBody() == actionBody::jump){
		elapsedR = chronoR.getElapsedTime();
		elapsedM = chronoM.getElapsedTime();
		if(elapsedR.asMilliseconds() >= run.asMilliseconds()){
			run = sf::milliseconds(80);
			i++;
			if(i > 3) i = 0;
			if(joueur->getActionBody() != actionBody::jump) textures::load_sprite(textures::mario,textures::TmarioRun[joueur->getSize()][i]);
			chronoR.restart();
		}
		if(elapsedM.asMilliseconds() >= move.asMilliseconds()){
			if(joueur->getActionBody() == actionBody::sprint) joueur->move(zoom); //il avance une fois de plus s'il sprint
			joueur->move(zoom);
			//ne pas aller en x < 0
			if(joueur->getPosition().x < sizeof(bigcases) && joueur->getRotation() < 0) 
				joueur->setPosition(sizeof(bigcases) - 2,joueur->getPosition().y);
			if(joueur->getPosition().x < 0 && joueur->getRotation() > 0)
				joueur->setPosition(0,joueur->getPosition().y);

			chronoM.restart();
		}
	}
}

void play(Fenetre &w){
	Carte c;
	int i;
	for(i = 0; i < nbCasesX; i+= 2){
		Block* b = new Solid_block(ground, day, i, nbCasesY - 2);
		c.ajoutBlock(b,false);
	}
	
	bool continuer = true;
	sf::Keyboard::Key k;
	bool pressed;
	
	bool isSprinting = false;

	sf::Thread running(&funcRun, &c.joueur);
	bool thread_launched = false;

	zoom = w.getZoom();

	while(continuer){
		k = w.getKey(pressed);

		if(k == sf::Keyboard::Escape || !w.isOpen()) 					continuer = false;
		if(k == sf::Keyboard::Space && pressed) 						c.joueur.changeSprite(jump);
		if(k == sf::Keyboard::Space && !pressed && !thread_launched) 	c.joueur.changeSprite(stop);
		if(k == sf::Keyboard::Space && !pressed &&  thread_launched)	c.joueur.changeSprite(run);

		if(k == sf::Keyboard::Left  && pressed) c.joueur.turnLeft (w.getZoom()), c.joueur.changeSprite(run);
		if(k == sf::Keyboard::Right && pressed) c.joueur.turnRight(w.getZoom()), c.joueur.changeSprite(run);

		if((k == sf::Keyboard::Right || k == sf::Keyboard::Left) && !pressed){ 
			c.joueur.changeSprite(stop);
			thread_launched = false;
		}
		if(k == sf::Keyboard::N && pressed) isSprinting = true;
		if(k == sf::Keyboard::N && !pressed) isSprinting = false;

		if(k == sf::Keyboard::F1 && w.getZoom() > 1 && pressed) w.resize(w.getZoom() - 1), c.draw(w), zoom = w.getZoom();
		else if(k == sf::Keyboard::F2 && pressed) w.resize(w.getZoom() + 1), c.draw(w), zoom = w.getZoom();
		else if(k == sf::Keyboard::F10 && pressed) w.resize(-1), c.draw(w), zoom = w.getZoom();
		
		if(isSprinting) c.joueur.changeSprite(sprint);

		if(c.joueur.getActionBody() == run && !thread_launched){
			running.launch();
			thread_launched = true;
		}
		
		w.clear();
		//c.drawAroundJoueur(w);
		c.draw(w);
		w.display();
	}
}
