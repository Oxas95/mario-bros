#ifndef texture_hpp
#define texture_hpp

#include <SFML/Graphics.hpp>
#include "fenetre.hpp"

class textures{
	
	public :
		static sf::Sprite lettres[26+10+4+1];
		static sf::Texture Tlettres[26+10+4+1];
		
		static sf::Sprite vide;
		
		static sf::Sprite logo;
		static sf::Texture Tlogo;
		
		static sf::Sprite nombrePieces;
		static sf::Texture TnombrePieces[5];
		
		static sf::Sprite goobaMenu;
		static sf::Texture TgoobaMenu;
		
		static sf::Sprite colline[2];
		static sf::Texture Tcolline[2];
		
		static sf::Sprite nuage[3];
		static sf::Texture Tnuage[3];
		
		static sf::Sprite buisson[3];
		static sf::Texture Tbuisson[3];
		
		static sf::Sprite ground[4];
		static sf::Texture Tground[4];
		
		static sf::Sprite block[4];
		static sf::Texture Tblock[4];
		
		static sf::Sprite brick[4];
		static sf::Texture Tbrick[4];
		
		static sf::Sprite block_coin[4];
		static sf::Texture Tblock_coin[4][5];
		
		static sf::Sprite coin[4];
		static sf::Texture Tcoin[4][5];

		static sf::Sprite hit[4];
		static sf::Texture Thit[4];
		
		static sf::Sprite mario;
		
		static sf::Texture TmarioStop[3];
		static sf::Texture TmarioRun[3][4];
		static sf::Texture TmarioDead;
		static sf::Texture TmarioJump[3];
		static sf::Texture TmarioTurn[3];
	
		static void load_sprite(sf::Sprite &s, sf::Texture &t, const char* path);
		static void load_texture(sf::Texture &texture, const char* path);
		static void load_sprite(sf::Sprite &sprite, sf::Texture &texture);
		static void funcGif();
		static void loadTextures();
		static int getSpriteChar(char);
		
	private :
		static void loadSpriteChar();
		static void loadSpriteBackground();
		static void loadSpritePetitMario();
		static void loadSpriteDayBlock();
		static void loadSpriteDay();
};

#endif //texture_hpp
