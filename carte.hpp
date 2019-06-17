#ifndef carte_hpp
#define carte_hpp

#include "Block.hpp"
#include "global.hpp"
#include <iostream>
#include <string>

using namespace std;

typedef struct colonne_carte{
	Block* tab[14];
	struct colonne_carte* next;
} Colonne;

typedef enum {
	editeur,
	jeu
} mod_carte;

class Carte{
	private :
		int timer;
		Colonne* debut;
		string nomMonde;
		string nomCarte;
		Block* tab_carte[14];
		int size;
	
	public :
		Carte(mod_carte mc);
		~Carte();
};

#endif //carte_hpp
