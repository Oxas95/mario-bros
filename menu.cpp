#include "menu.hpp"
#include "fenetre.hpp"
#include "global.hpp"
#include "texture.hpp"

namespace menu{
	
void affiche_textures(Fenetre& w){
	int i;
	w.clear(skyColor);
	w.drawSpriteCases(5,3,textures::logo);
	w.drawSpriteCases(0,20,textures::colline[1]);
	w.drawSpriteCases(23,23,textures::buisson[2]);
	w.drawSpriteCases(5,23,textures::mario);
	w.writeCases("@ 2019 Kino",16,14);
	w.writeCases("Play a Game",11,17);
	w.writeCases("Make a Game",11,19);
	w.writeCases("Settings",11,21);
	w.writeCases("Exit",11,23);
	
	w.writeCases("Mario          World  Time",3,1);
	w.writeCases("000000  .*00    1-1",3,2);
	
	for (i = 0; i < nbBigCasesX * 2; i += 2){
		w.drawSpriteCases(i, 25, textures::ground[0]);
		w.drawSpriteCases(i, 27, textures::ground[0]);
	}
	
}
	
}//namespace menu

using namespace menu;

int menu_selection(Fenetre& w){
	static int res = 0;
	bool continuer = true;
	bool pressed;
	sf::Keyboard::Key k;
	affiche_textures(w);
	while(continuer){
		k = w.getKey(pressed);
		
		if	   (k == sf::Keyboard::Up && pressed){
			if(res > 0){
				w.writeCases(" ",9,17 + res * 2);
				res--;
			}
		}
		else if(k == sf::Keyboard::Down && pressed){
			if(res < 3){
				w.writeCases(" ",9,17 + res * 2);
				res++;
			}
		}
		else if(k == sf::Keyboard::Return) continuer = false;
		else if(w.isOpen() == false) res = 3, continuer = false;
		elseif_buttonResize();
		
		w.writeCases("$",11,2);
		w.drawSpriteCases(9,17 + res * 2,textures::goobaMenu);
		
		w.display();
	}
	return res;
}

void call_menu(Fenetre& w){
	bool continuer = true;
	static int res = 2;
	while(continuer){
		res = menu_selection(w);
		
		printf("choisit : %d\n",res);
		
		if(res == 0){
			//play
		}
		else if(res == 1){
			//make
		}
		else if(res == 2){
			//parametres
		}
		else continuer = false;
	}
}
