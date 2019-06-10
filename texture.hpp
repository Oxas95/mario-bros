#ifndef texture_hpp
#define texture_hpp

#include <SFML/Graphics.hpp>
#include "fenetre.hpp"

class textures{
	
	public :
		static sf::Sprite lettres[26+10+4+1];
		
		static sf::Texture Tlettres[26+10+4+1];
		
		static sf::Sprite logo;
		static sf::Texture Tlogo;
		
		static sf::Sprite vide;
	
		static void load_sprite(sf::Sprite &s, sf::Texture &t, const char* path);
		static void loadTextures();
		static int getSpriteChar(char);
		
	private :
		static void loadSpriteChar();
		static void loadSpritePetitMario();
		static void loadSpriteJourBlock();
		static void loadSpriteLogo();
};

#endif //texture_hpp
