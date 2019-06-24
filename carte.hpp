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

typedef struct liste_block{
	Block* backgroundBlock;
	struct liste_block* next;
}listeBlocks;

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
		listeBlocks* background;

		string nomMonde;
		string nomCarte;

		Block*** tab_carte;

		int size;

		bool usingArray;
	
	public :
		Carte();
		Carte(const char* path);
		~Carte();
		void ajoutBlock(Block*, bool isBlockBackground);
		void suppBlock(bool isBlockBackground, sf::Vector2i position);
		void suppBlock(bool isBlockBackground, int x, int y);
		void ajoutColonne();
		bool ajoutColonne(int posX);
		bool suppColonne();
};

#endif //carte_hpp
