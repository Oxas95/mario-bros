#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "global.hpp"
#include "fenetre.hpp"
#include "menu.hpp"
#include "texture.hpp"

using namespace std;

int main(){
	
	cout << "Chargement des textures" << endl;
	textures::loadTextures();
	Fenetre w;
	
	call_menu(w);
	
	exit(0);
}
