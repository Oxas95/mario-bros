#ifndef carte_hpp
#define carte_hpp

#include "Block.hpp"
#include "global.hpp"
#include <iostream>
#include <string>

using namespace std;

typedef struct colonne_carte{
	Block* tab[nbCasesY];
	struct colonne_carte* next;
} Colonne;

typedef enum{
	day,
	night,
	under,
	castle,
	water
}areaType;

class Carte{
	private :
		int timer;
		Colonne* debut;
		string nomMonde;
		string nomCarte;
		Block*** tab_carte;
		int size;
		bool usingArray;
	
	public :
		Carte();
		Carte(const char* path);
		~Carte();
		bool ajoutBlock(Block*, int x, int y);
		bool suppBlock(int x, int y);
		void ajoutColonne();
		void suppColonne();
};

#endif //carte_hpp
