//made in lapegue thibault

#include "jouer.h"
#include "Carte.h"
#include "entity/Joueur.h"
#include <math.h>
#include <string>
#include <iostream>
#include <unistd.h>


void deplacementIA2(Carte& c, IA& J, bool bleuJoue, int move, int& cptMove, Fenetre & w){
	
	if(bleuJoue){
		 drawFond(w, J, c.getLargeur(), c.getHauteur());
		 JoueurVie(w,J.getVie()); //vie du joueur
	 }
	else {
		drawFond(w, J, c.getLargeur(), c.getHauteur());
		JoueurVie(w,J.getVie()); 	
	}
	c.drawAroundJoueur(w, bleuJoue);
	w.getWindow().display();
	sleep(2);
	
	double Cos, Sin;
	//tire dois etre init a false
	string str = "";
	int rotation = J.getRotation();
	int aleadegres ;
	int aleaAvence;
	int aleatourne;
	int aleatire;
	bool obligation ;
	obligation = false ;
	int cbAvence, pos , r ,diff ;
	aleatourne = rand() %1000;

	int x = J.getPosition().x, y = J.getPosition().y;
	
	if(J.getVie() <= 30)
		J.set_tire(false);
	
	if(aleatourne <= 333 && J.get_tire() == false){
		diff = 360- 1;
		
		pos = 1;
		while (pos < diff) {
			pos *= 2;
		}
		
		
		do {
			r = rand() % pos;
		} while(r >= diff);
		
		aleadegres= 1 + r;
		J.setRotation(aleadegres);
		obligation = true;
	}
	if(bleuJoue){
		 drawFond(w, J, c.getLargeur(), c.getHauteur());
		 JoueurVie(w,J.getVie()); //vie du joueur
	 }
	else {
		drawFond(w, J, c.getLargeur(), c.getHauteur());
		JoueurVie(w,J.getVie()); 	
	}
	c.drawAroundJoueur(w, bleuJoue);
	w.getWindow().display();
	sleep(2);

	
	Cos = cos(rotation * PI / 180) * 5;
	Sin = sin(rotation * PI / 180) * 5;
	
	
	aleaAvence = rand() %1000;
	
	// l ordi avence 
	if(aleaAvence < 500 || obligation){
			
		cbAvence = rand()% 30;
		for (int i = 0; i < cbAvence /*&& c.obstacle_entre_joueurs(w)*/; i++){
			
			J.setPosition(J.getPosition().x + (int)Cos, J.getPosition().y + (int)Sin);
			if((c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){//collision avec un autre sprite
				J.setPosition(x, y + (int)Sin);
				if((c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
					J.setPosition(x + (int)Cos, y);
					if(( c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
						J.setPosition(x,y);
					}
				}
			}
		
			if(x + Cos - 20 < 0 || x + 20 + Cos > c.getLargeur())
				J.setPosition(x, J.getPosition().y);
			if(y + Sin - 20 < 0 || y + 20 + Sin > c.getHauteur())
				J.setPosition(J.getPosition().x, y);
		}		
	}

	if(bleuJoue){
		 drawFond(w, J, c.getLargeur(), c.getHauteur());
		 JoueurVie(w,J.getVie()); //vie du joueur
	}
	else {
		drawFond(w, J, c.getLargeur(), c.getHauteur());
		JoueurVie(w,J.getVie()); 	
	}
	c.drawAroundJoueur(w, bleuJoue);
	w.getWindow().display();
	sleep(2);
		
		
	aleatire = rand()%1000;
	/*
	if( (c.collisionEntity(J.getPosition().x + Cos * 5, J.getPosition().y + Sin * 5) != -1 && (aleatire <= 500 ||  J.get_tire() == true))&& J.getVie() > 30){   // c est pour tirer  a faire apret
		//pas finie
		
		int limite_gauche = J.getRotation() - 45;
		if(limite_gauche < 0) limite_gauche += 360;
		int limite_droite = J.getRotation() + 45;
		if(limite_droite > 360) limite_droite -= 360;		
		Joueur &Adversaire = (bleuJoue) ? Jr : Jb;
		while(touche != sf::Keyboard::Space){  
			
			if(k.left){//la  rotation tire si on a trouvé le joueur 
				J.setRotation(-move);
				if(J.getRotation() > limite_gauche - move &&  J.getRotation() < limite_gauche){
					J.setRotation(move);
				}
				
			}
			if(k.right){ // la de meme
				J.setRotation(move);
				if(J.getRotation()  > limite_droite &&  J.getRotation() < limite_droite + move){
					J.setRotation(-move);
				}
			}
			if(touche == sf::Keyboard::Space && J.getVie() - J.get_balle().get_dommage() > 0 ){// le if a modi c tout 
				
				Cos = cos(J.getRotation() * PI / 180) ;
				Sin = sin(J.getRotation() * PI / 180) ;
				 
				J.get_balle().setPosition(J.getPosition().x + 20 - 7, J.getPosition().y + 20 - 7);
				int i,j;
				 
				J.degats(J.get_balle().get_dommage());
				for(i=0 ; i < J.get_balle().get_distance()*8 && (j = c.collisionEntity(J.get_balle().getSprite())) == -1 && c.collisionJoueur(J.get_balle().getSprite(), !bleuJoue) == false; i++){
					sleep(0.01);
					J.get_balle().setPosition(J.get_balle().getPosition().x + Cos * 2 , J.get_balle().getPosition().y + Sin * 2 );
					J.get_balle().draw(w);
					if(bleuJoue){
						 drawFond(w, J, c.getLargeur(), c.getHauteur());
						 JoueurVie(w,J.getVie()); //vie du joueur
					 }
					else {
						drawFond(w, J, c.getLargeur(), c.getHauteur());
						JoueurVie(w,J.getVie()); 	
					}
					c.drawAroundJoueur(w, bleuJoue);
					w.getWindow().display();
					
				}
				 
				if(j != -1){
					if(c.getEntity(j)->degats(J.get_balle().get_dommage())==false)c.deleteEntity(j);
				}
				else if(c.collisionJoueur(J.get_balle().getSprite(), !bleuJoue)){
					Adversaire.degats(Adversaire.getVie());
				} 
			}
			if(bleuJoue){
				 drawFond(w, J, c.getLargeur(), c.getHauteur());
				 JoueurVie(w,J.getVie()); //vie du joueur
			 }
			else {
				drawFond(w, J, c.getLargeur(), c.getHauteur());
				JoueurVie(w,J.getVie()); 	
			}
			c.drawAroundJoueur(w, bleuJoue);
			w.getWindow().display();
		}
	}*/
	if((J.getPosition().x != x || J.getPosition().y != y) && J.get_tire())
		J.set_tire(false);
	cptMove = 0;
}



int absolue(int value){
	return (value > 0) ? value : -value;
}

int regarderJoueur(sf::Vector2i J, sf::Vector2i adversaire){
	
	sf::Vector2i angleDroit(J.x, adversaire.y);
	
	int degre;
	int adj = absolue(J.y - adversaire.y);
	int oppo = absolue(adversaire.x - angleDroit.x);
	int hypo = sqrt(adj * adj + oppo * oppo); 
	
	degre = acos (oppo * 1.0 / hypo * 1.0) * 180 / PI;
	
	if(adversaire.x - angleDroit.x > 0) return -degre;
	return degre;
}

void deplacementIA(Carte& c, IA& J, Joueur* adversaireJ, IA* adversaireIA, bool bleuJoue, int move, int& cptMove, Fenetre & w){
	double Cos = 0, Sin = 0;
	string str = "";
	int alea = rand()%1000;
	int pos,r,seuil;
	int x = J.getPosition().x, y = J.getPosition().y;
	bool tourne=false ;
	
	seuil=0;
	
	//if(c.obstacle_entre_joueurs(w)){ //si on voit pas le joueur	
		//rotation de l'IA
		if(alea > 500){
			//alea = rand()%360 + 1;
			
			;
		
		pos = 1;
		while (pos < 360) {
			pos *= 2;
		}
		
		
		do {
			r = rand() % pos;
		} while(r >= 360);
		
		alea= 1 + r;
		
			for (int i = 0; i < alea; i += move){
				J.setRotation(move);
				
				//affichage pendant rotation
				drawFond(w, J, c.getLargeur(), c.getHauteur());
				JoueurVie(w,J.getVie()); 	
				c.drawAroundJoueur(w, bleuJoue);
				w.getWindow().display();
			}
			seuil= 250;
		}
		
		Cos = cos(J.getRotation() * PI / 180) * 5;
		Sin = sin(J.getRotation() * PI / 180) * 5;
		
		//deplacement de l'IA
		alea = rand()%1000+seuil;
		if(alea > 250){
			int i;
			alea = rand()%20 + 10;
			for (i = 0; i < alea /*&& c.obstacle_entre_joueurs(w)*/ ; i++){
				int x = J.getPosition().x, y = J.getPosition().y;
				J.setPosition(J.getPosition().x + (int)Cos, J.getPosition().y + (int)Sin);
				if((c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){//collision avec un autre sprite
					J.setPosition(x, y + (int)Sin);
					if((c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
						J.setPosition(x + (int)Cos, y);
						if(( c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
							J.setPosition(x,y);
						}
					}
				}
			
				if(x + Cos - 20 < 0 || x + 20 + Cos > c.getLargeur())
					J.setPosition(x, J.getPosition().y);
				if(y + Sin - 20 < 0 || y + 20 + Sin > c.getHauteur())
					J.setPosition(J.getPosition().x, y);
					
				//affichage pendant deplacement
				drawFond(w, J, c.getLargeur(), c.getHauteur());
				JoueurVie(w,J.getVie()); 	
				c.drawAroundJoueur(w, bleuJoue);
				w.getWindow().display();
			}
		}
	//}
/*	else{//la 
		//rotation vers le haut ou vers le bas
		if(J.getPosition().y > ((adversaireJ) ? adversaireJ->getPosition().y : adversaireIA->getPosition().y)){
			while(J.getRotation() != 270){
				J.setRotation(move);
				//affichage pendant rotation
				drawFond(w, J, c.getLargeur(), c.getHauteur());
				JoueurVie(w,J.getVie()); 	
				c.drawAroundJoueur(w, bleuJoue);
				w.getWindow().display();
			}
		}
		else{
			while(J.getRotation() != 90){
				J.setRotation(move);
				//affichage pendant rotation
				drawFond(w, J, c.getLargeur(), c.getHauteur());
				JoueurVie(w,J.getVie()); 	
				c.drawAroundJoueur(w, bleuJoue);
				w.getWindow().display();
			}
		}
		
		//rotation vers joueur
		int degre = regarderJoueur(J.getPosition(), (adversaireJ) ? adversaireJ->getPosition() : adversaireIA->getPosition());
		printf("degre : %d\n",degre);
		degre += J.getRotation();
		if(degre < 0) degre += 360;
		if(degre > 360) degre -= 360;
		
		
		while(J.getRotation() != degre - 1 && J.getRotation() != degre){
			printf("degre : %d -- %f\n",degre, J.getRotation());
			J.setRotation(move);
			//affichage pendant rotation
			drawFond(w, J, c.getLargeur(), c.getHauteur());
			JoueurVie(w,J.getVie()); 	
			c.drawAroundJoueur(w, bleuJoue);
			w.getWindow().display();
		}
		
		//deplacement vers l'adversaire parce qu'il le voit
		for (int i = 0; i < alea && !c.obstacle_entre_joueurs(w); i++){
			int x = J.getPosition().x, y = J.getPosition().y;
			J.setPosition(J.getPosition().x + (int)Cos, J.getPosition().y + (int)Sin);
			if((c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){//collision avec un autre sprite
				J.setPosition(x, y + (int)Sin);
				if((c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
					J.setPosition(x + (int)Cos, y);
					if(( c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
						J.setPosition(x,y);
					}
				}
			}
		
			if(x + Cos - 20 < 0 || x + 20 + Cos > c.getLargeur())
				J.setPosition(x, J.getPosition().y);
			if(y + Sin - 20 < 0 || y + 20 + Sin > c.getHauteur())
				J.setPosition(J.getPosition().x, y);
				
			//affichage pendant deplacement
			drawFond(w, J, c.getLargeur(), c.getHauteur());
			JoueurVie(w,J.getVie()); 	
			c.drawAroundJoueur(w, bleuJoue);
			w.getWindow().display();
		}
	}*/
	//affichage final

	drawFond(w, J, c.getLargeur(), c.getHauteur());
	JoueurVie(w,J.getVie()); 	
	c.drawAroundJoueur(w, bleuJoue);
	w.getWindow().display();
	sleep(2);
}

