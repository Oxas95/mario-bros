#include "jouer.h"
#include "Carte.h"
#include "entity/Joueur.h"
#include <math.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "deplacementIA.cpp"
#include "selecteur_carte.h"

using namespace std;

//vie

void JoueurVie (Fenetre& w,int J_vie){
	w.draw_fillRect(10,10,2*J_vie, 4, sf::Color(0, 70, 33));
}

typedef struct {
	bool up;
	bool down;
	bool left;
	bool right;
} Key;

sf::Keyboard::Key get_key(Fenetre& window, Key& k){
	sf::Event event;
	while (window.getWindow().pollEvent(event)){
		if (event.type == sf::Event::Closed){
			window.close();
		}
		if(event.type == sf::Event::KeyPressed){
			if(event.key.code == sf::Keyboard::Left)
				k.left = true;
			else if(event.key.code == sf::Keyboard::Right)
				k.right = true;
			else if(event.key.code == sf::Keyboard::Up)
				k.up = true;
			else if(event.key.code == sf::Keyboard::Down)
				k.down = true;
			else return event.key.code;
		}
		
		if(event.type == sf::Event::KeyReleased){
			if(event.key.code == sf::Keyboard::Left)
				k.left = false;
			else if(event.key.code == sf::Keyboard::Right)
				k.right = false;
			else if(event.key.code == sf::Keyboard::Up)
				k.up = false;
			else if(event.key.code == sf::Keyboard::Down)
				k.down = false;
		}
	}
	return sf::Keyboard::Unknown;
}

void gestion_touches(Key& k, sf::Keyboard::Key& touche, Carte& c, Joueur& J, bool bleuJoue, int move, int& cptMove, bool avancer, Fenetre & w){
	double Cos, Sin;
	string str = "";
	
	int rotation = J.getRotation();
	if(k.down){
		rotation += 180;
		if(rotation > 360) rotation -= 360;
	}
	
	Cos = cos(rotation * PI / 180) * 5;
	Sin = sin(rotation * PI / 180) * 5;
	
	int x = J.getPosition().x, y = J.getPosition().y;
	
	if(k.left){
		J.setRotation(-move);
	}
	if(k.right){
		J.setRotation(move);
	}
	if(((k.up && !k.down) || (k.down && !k.up)) && avancer){ //une seule des 2 est appuyé sinon le déplacement s'annule
		
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
	
	if(touche == sf::Keyboard::Space){
		
		int limite_gauche = J.getRotation() - 45;
		if(limite_gauche < 0) limite_gauche += 360;
		int limite_droite = J.getRotation() + 45;
		if(limite_droite > 360) limite_droite -= 360;		
		Joueur &Adversaire = (bleuJoue) ? Jr : Jb;
		touche = sf::Keyboard::A;
		while(touche != sf::Keyboard::Space && touche != sf::Keyboard::Escape && w.isOpen()){
			touche = get_key(w, k);
			
			if(k.left){
				J.setRotation(-move);
				if(J.getRotation() > limite_gauche - move &&  J.getRotation() < limite_gauche){
					J.setRotation(move);
				}
				
			}
			if(k.right){
				J.setRotation(move);
				if(J.getRotation()  > limite_droite &&  J.getRotation() < limite_droite + move){
					J.setRotation(-move);
				}
			}
			if(touche == sf::Keyboard::Space && J.getVie() - J.get_balle().get_dommage() > 0 ){
				
				Cos = cos(J.getRotation() * PI / 180) * 10 ;
				Sin = sin(J.getRotation() * PI / 180) * 10 ;
				
				J.get_balle().setPosition(J.getPosition().x + 20 - J.get_balle().get_rayon() / 2, J.getPosition().y + 20 - J.get_balle().get_rayon() / 2);
				int i,j;
				for(i = 0 ; i < J.get_balle().get_distance()* 2 && (j = c.collisionEntity(J.get_balle().getSprite())) == -1 && c.collisionJoueur(J.get_balle().getSprite(), !bleuJoue) == false; i++){
					sleep(0.5);
					J.get_balle().setPosition(J.get_balle().getPosition().x + Cos , J.get_balle().getPosition().y + Sin);
					if(bleuJoue){
						 drawFond(w, Jb, c.getLargeur(), c.getHauteur());
					 }
					else {
						drawFond(w, Jr, c.getLargeur(), c.getHauteur());	
					}
					c.drawAroundJoueur(w, bleuJoue);
					JoueurVie(w,Jb.getVie()); //vie du joueur
					w.getWindow().display();
					
				}
				 
				if(j != -1){
					if(c.getEntity(j)->degats(J.get_balle().get_dommage())==false)c.deleteEntity(j);
				}
				else if(c.collisionJoueur(J.get_balle().getSprite(), !bleuJoue)){
					Adversaire.degats(Adversaire.getVie());
				}
				J.degats(J.get_balle().get_dommage());
				
				J.get_balle().setPosition(-100, -100);
				if(bleuJoue){
					 drawFond(w, Jb, c.getLargeur(), c.getHauteur());
				 }
				else {
					drawFond(w, Jr, c.getLargeur(), c.getHauteur());	
				}
				c.drawAroundJoueur(w, bleuJoue);
				JoueurVie(w,Jb.getVie()); //vie du joueur
				w.getWindow().display();
				sleep(1);
				touche = sf::Keyboard::Escape;
			}
			if(bleuJoue){
				 drawFond(w, Jb, c.getLargeur(), c.getHauteur());
			 }
			else {
				drawFond(w, Jr, c.getLargeur(), c.getHauteur());
			}
			c.drawAroundJoueur(w, bleuJoue);
			JoueurVie(w,Jr.getVie()); 
			w.getWindow().display();
		}
	}
	
	if(J.getPosition().x != x || J.getPosition().y != y) cptMove++;
}

void changeJoueur(Fenetre& w, bool bleu){
	w.getWindow().clear();
	string str = "Joueur ";
	(bleu)? str.append("bleu") : str.append("rouge");
	int size = w.getFont(str.c_str(),40);
	w.write(str.c_str(),40,sf::Color::White, (w.getLargeur() - size) / 2, (500 - 40) / 2);
	w.getWindow().display();
	sleep(2);
}

void fin(Fenetre& w, Carte& c){
	string str = "";
	if(Jb.getVie() < 1)
		str.append("Victoire pour Joueur rouge");
	else if(Jr.getVie() < 1)
		str.append("Victoire pour Joueur bleu");
	if(Jb.getVie() < 1 || Jr.getVie() < 1){
		sleep(1);
		w.getWindow().clear();
		int size = w.getFont(str.c_str(),40);
		w.write(str.c_str(),40,sf::Color::White, (w.getLargeur() - size) / 2, (500 - 40) / 2);
		w.getWindow().display();
		sleep(3);
		w.close();
	}
}

void drawFond(Fenetre& w, Joueur& J, int largeur, int hauteur){
    w.getWindow().clear();
    sf::Vector2i position, beginTo, size; // points pour dessiner en decalé la photo de fond

    position.x = w.getLargeur() / 2 - J.getPosition().x;
    //beginTo.x = (position.x >= 0)? 0 : -position.x;
    //if(position.x < 0) position.x = 0;
    size.x = largeur;
    //size.x -= (J.getPosition().x + w.getLargeur() / 2) - largeur;

    position.y = w.getHauteur() / 2 - J.getPosition().y;
    //beginTo.y = (position.y >= 0)? 0 : -position.y;
    //if(position.y < 0) position.y = 0;
    size.y = hauteur;
    //size.y -= (J.getPosition().y + w.getHauteur() / 2) - hauteur;

    //w.drawSprite(position, beginTo, size,"sol_1500.png");
    w.draw_fillRect(position.x, position.y, size.x, size.y, sf::Color(160,62,35));
}

void affiche(Fenetre& window, Carte& c){
	
	int move = 2;
	Key k = {false, false, false, false};
	int cptMove = 0;
	bool bleuJoue = false;
	sf::Keyboard::Key touche;
	
	while (window.isOpen()){
		if((bleuJoue && !c.getBleuIA()) || (!bleuJoue && !c.getRougeIA())){
			touche = get_key(window, k);
			if(bleuJoue){
				 drawFond(window, Jb, c.getLargeur(), c.getHauteur());
				 gestion_touches(k, touche, c, Jb, true, move, cptMove, cptMove < 30, window);
			 }
			else {
				drawFond(window, Jr, c.getLargeur(), c.getHauteur());
				gestion_touches(k, touche,c, Jr, false, move, cptMove, cptMove < 30 , window);
			}
			
			c.drawAroundJoueur(window, bleuJoue);
			JoueurVie(window,Jb.getVie()); //vie du joueur
			window.getWindow().display();
			
			if(touche == sf::Keyboard::Escape){
				bleuJoue = !bleuJoue;
				changeJoueur(window, bleuJoue);
				cptMove = 0;
			}
		}
		else {
			if(bleuJoue){
				if(c.getRougeIA())  deplacementIA(c, IAb, NULL, &IAr, bleuJoue, move, cptMove, window);
				else 				deplacementIA(c, IAb, &Jr, NULL, bleuJoue, move, cptMove, window);
			}
			else {
				if(c.getBleuIA())  deplacementIA(c, IAr, NULL, &IAb, bleuJoue, move, cptMove, window);
				else 			   deplacementIA(c, IAr, &Jb, NULL, bleuJoue, move, cptMove, window);
			}
			bleuJoue = !bleuJoue;
			changeJoueur(window, bleuJoue);
			cptMove = 0;
		}
		
		fin(window, c);
		
	}
}

int choixJoueurs(Fenetre& window){
    int choix = -1;
	while (window.isOpen() && choix < 0){
        sf::Event event;
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                choix = 0;
			}
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Up && choix < -1) choix++;
				if(event.key.code == sf::Keyboard::Down && choix > -4 ) choix--;
				if(event.key.code == sf::Keyboard::Return) choix = -choix;
			}
        }
        window.drawSprite(0,0,600,500,"fond.png");
        
        window.write("Joueur vs Joueur", 40, sf::Color::Black, 165, 50);
        window.write("Joueur vs IA", 40, sf::Color::Black, 200, 170);
        window.write("Ordi vs Ordi", 40, sf::Color::Black, 205, 290);
        window.write("Revenir en arriere", 40, sf::Color::Black, 165, 410);
        
        if(choix == -1){
			window.write(">", 40, sf::Color::Black, 60, 50);
		}
		else if(choix == -2){
			window.write(">", 40, sf::Color::Black, 60, 170);
		}
        else if(choix == -3){
			window.write(">", 40, sf::Color::Black, 60, 290);
		}
        else if(choix == -4){
			window.write(">", 40, sf::Color::Black, 60, 410);
		}

        window.getWindow().display();
    }
    return choix;
}

int nombreChiffre(int nb){
	int cmp = 1;
	while((nb = (nb / 10))){
		cmp++;
	}
	return cmp;	
}

char* itoa(int entier){
	int taille = nombreChiffre(entier);
	char* nombre = (char*)malloc((taille + 1) * sizeof(char));
	int i,chiffre;
	for(i = taille - 1; i >= 0; i--){
		chiffre = entier % 10;
		nombre[i] = chiffre + '0';
		entier /= 10;
	}
	nombre[taille] = '\0';
	return nombre;
}

int choixJoueurs(Fenetre& window, int& choix1, int& choix2){
    int choix = -1;
    string s1,s2;
    s1 = "Joueur 1 : Balle de taille ", s2 = "Joueur 2 : Balle de taille ";
    s1.append(itoa(choix1));
    s2.append(itoa(choix2));
	while (window.isOpen() && choix < 0){
        sf::Event event;
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                choix = 0;
			}
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Up && choix < -1) choix++;
				if(event.key.code == sf::Keyboard::Down && choix > -2 ) choix--;
				if(event.key.code == sf::Keyboard::Left){
					if(choix == -1 && choix1 > 1) choix1--;
					if(choix == -2 && choix2 > 1) choix2--;
				}
				if(event.key.code == sf::Keyboard::Right){
					if(choix == -1 && choix1 < 5) choix1++;
					if(choix == -2 && choix2 < 5) choix2++;
				}
				if(event.key.code == sf::Keyboard::Return) return choix;
			}
        }
        window.drawSprite(0,0,600,500,"fond.png");
        s1 = "Balle de taille ", s2 = "Balle de taille ";
		s1.append(itoa(choix1));
		s2.append(itoa(choix2));
        window.write(s1.c_str(), 40, sf::Color::Black, 165, 50);
        window.write(s2.c_str(), 40, sf::Color::Black, 165, 170);
        
        if(choix == -1){
			window.write(">", 40, sf::Color::Black, 120, 50);
		}
		else if(choix == -2){
			window.write(">", 40, sf::Color::Black, 120, 170);
		}
        window.getWindow().display();
    }
    return choix;
}

void option(Fenetre& w){
	bool IAbleu = false, IArouge = false;
	int tailleBalle1 = 1,tailleBalle2 = 1;
	int choix = choixJoueurs(w);
	if(choix == 2) IArouge = true;
	if(choix == 3) IArouge = IAbleu = true;
	if(choix != 4){
		choixJoueurs(w, tailleBalle1, tailleBalle2);
		const char* str = Selecteur::select_carte(w);
		string s = ""; s.append (str);
		if(str) {
			Carte* c = new Carte (s.substr(0,s.length() - 6).c_str(), true, IAbleu, IArouge);
			if(IAbleu){
				c->getIABleu().set_balle(-100,-100, tailleBalle1, 1);
			}
			else{
				c->getJoueurBleu().set_balle(-100,-100, tailleBalle1, 1);
			}
			if(IArouge){
				c->getIARouge().set_balle(-100,-100, tailleBalle2, 1);
			}
			else{
				c->getJoueurRouge().set_balle(-100,-100, tailleBalle2, 1);
			}
			printf("%s\n",s.substr(0, s.length() - 6).c_str());
			affiche(w,*c);
			delete[] str;
		}
	}
}
