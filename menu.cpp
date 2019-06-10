#include "menu.hpp"
#include "fenetre.hpp"
#include "global.hpp"
#include "texture.hpp"

namespace menu{
	
void affiche_textures(Fenetre& w){
	
	w.clear(skyColor);
	w.drawSpriteCases(5,3,textures::logo);
	w.writeCases("Play a Game",11,17);
	w.writeCases("Make a Game",11,19);
	w.writeCases("Settings",11,21);
	w.writeCases("Exit",11,23);
}
	
}//namespace menu

using namespace menu;

int menu_selection(Fenetre& w){
	int res = 0;
	bool continuer = true;
	bool pressed;
	sf::Keyboard::Key k;
	int choix;
	affiche_textures(w);
	while(continuer){
		k = w.getKey(pressed);
		
		if	   (k == sf::Keyboard::Up){
			
		}
		else if(k == sf::Keyboard::Down){
			
		}
		else if(k == sf::Keyboard::Return) continuer = false;
		else if(w.isOpen() == false || res == 4) res = 0, continuer = false;
		elseif_buttonResize();
		
		w.display();
	}
	return res;
}

void call_menu(Fenetre& w){
	bool continuer = true;
	int res;
	while(continuer){
		res = menu_selection(w);
		
		if(res == 1){
			//play
		}
		else if(res == 2){
			//make
		}
		else if(res == 3){
			//parametres
		}
		else continuer = false;
	}
}
