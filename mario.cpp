#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "global.hpp"
#include "fenetre.hpp"
#include "menu.hpp"
#include "texture.hpp"

#include <unistd.h>

using namespace std;

int main(){
	
	cout << "Chargement des textures" << endl;
	textures::loadTextures();
	
	sleep(1);
	
	Fenetre w;
	
	sf::Thread thread(&textures::funcGif);
	thread.launch();
	
	call_menu(w);

	exit(0);
}
