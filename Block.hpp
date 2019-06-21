#ifndef Block_hpp
#define Block_hpp

#include "fenetre.hpp"

class Block{
	private :
		sf::Sprite& sprite;
		sf::Vector2i position;
		void setSprite(sf::Sprite&);
	
	public :
		Block(sf::Vector2i position);
		Block(int x, int y);
		virtual ~Block();
		sf::Vector2i getPosition();
		void drawAt(Fenetre&, int x, int y);
		void drawAtCases(Fenetre&, int x, int y);
		virtual bool isHitted(sf::Sprite&);
		virtual bool isHitted(Block*);
};

#endif //Block_hpp
