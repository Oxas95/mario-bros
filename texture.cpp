#include "texture.hpp"
#include <string>
#include <iostream>
#include "fenetre.hpp" 

#include <SFML/System.hpp>

using namespace std;

sf::Sprite textures::lettres[26+10+4+1];   //lettres + chiffres + caracteres speciaux + sprite sans image
sf::Texture textures::Tlettres[26+10+4+1]; //lettres + chiffres + caracteres speciaux + Tvide (pour le sprite sf::Sprite vide ligne 13)

sf::Sprite textures::vide;

sf::Sprite textures::logo;
sf::Texture textures::Tlogo;

sf::Sprite textures::nombrePieces;
sf::Texture textures::TnombrePieces[5];    //gif

sf::Sprite textures::goobaMenu;
sf::Texture textures::TgoobaMenu;

sf::Sprite textures::colline[2];           //size
sf::Texture textures::Tcolline[2];         //size

sf::Sprite textures::nuage[3];             //size
sf::Texture textures::Tnuage[3];           //size

sf::Sprite textures::buisson[3];           //size
sf::Texture textures::Tbuisson[3];         //size

sf::Sprite textures::ground[4];            //area
sf::Texture textures::Tground[4];          //area

sf::Sprite textures::block[4];             //area
sf::Texture textures::Tblock[4];           //area

sf::Sprite textures::brick[4];             //area
sf::Texture textures::Tbrick[4];           //area

sf::Sprite textures::block_coin[4];        //area
sf::Texture textures::Tblock_coin[4][5];   //area, gif

sf::Sprite textures::coin[4];              //area
sf::Texture textures::Tcoin[4][5];         //area, gif

sf::Sprite textures::hit[4];			   //area
sf::Texture textures::Thit[4];			   //area

sf::Sprite textures::mario;

sf::Texture textures::TmarioStop[3];   //size of mario
sf::Texture textures::TmarioRun[3][4]; //size of mario, gif
sf::Texture textures::TmarioDead;
sf::Texture textures::TmarioJump[3];   //size of mario
sf::Texture textures::TmarioTurn[3];   //size of mario

void textures::loadSpriteChar(){
	int i;
	const char* chemin = "sprites/lettres/";
	string s = chemin;
	char c[2] = {'A','\0'};
	for (i = 0; i < 26; i++){
		s.append(c);
		s.append(".png");
		load_sprite(lettres[i],Tlettres[i],s.c_str());
		s = chemin;
		c[0]++;
	}
	c[0] = '0';
	for (; i < 26 + 10; i++){
		s.append(c);
		s.append(".png");
		load_sprite(lettres[i],Tlettres[i],s.c_str());
		s = chemin;
		c[0]++;
	}
	load_sprite(lettres[i],Tlettres[i],"sprites/lettres/mu.png"); i++;
	load_sprite(lettres[i],Tlettres[i],"sprites/lettres/-.png"); i++;
	load_sprite(lettres[i],Tlettres[i],"sprites/lettres/!.png"); i++;
	load_sprite(lettres[i],Tlettres[i],"sprites/lettres/co.png"); i++;
	load_sprite(vide,Tlettres[i],"sprites/vide.png");
}

void textures::loadSpriteBackground(){
	load_sprite(colline[0],Tcolline[0],"sprites/background/collineS.png");
	load_sprite(colline[1],Tcolline[1],"sprites/background/collineM.png");
	
	load_sprite(nuage[0],Tnuage[0],"sprites/background/nuageS.png");
	load_sprite(nuage[1],Tnuage[1],"sprites/background/nuageM.png");
	load_sprite(nuage[2],Tnuage[2],"sprites/background/nuageL.png");
	
	load_sprite(buisson[0],Tbuisson[0],"sprites/background/buissonS.png");
	load_sprite(buisson[1],Tbuisson[1],"sprites/background/buissonM.png");
	load_sprite(buisson[2],Tbuisson[2],"sprites/background/buissonL.png");
}

void textures::loadSpritePetitMario(){
	load_texture(TmarioStop[0],"sprites/mario/petit/stop.png");
	
	load_texture(TmarioJump[0],"sprites/mario/petit/jump.png");
	
	load_texture(TmarioTurn[0],"sprites/mario/petit/turn.png");
	
	load_texture(TmarioRun[0][0],"sprites/mario/petit/sprint1.png");
	load_texture(TmarioRun[0][1],"sprites/mario/petit/sprint2.png");
	load_texture(TmarioRun[0][2],"sprites/mario/petit/sprint3.png");
	load_texture(TmarioRun[0][3],"sprites/mario/petit/sprint4.png");
	
	load_sprite(mario,TmarioStop[0]); //initialisation de mario a stop
}

void textures::loadSpriteDayBlock(){
	load_sprite(ground[0],Tground[0],"sprites/day/blocks/ground.png");
	load_sprite(block[0],Tblock[0],"sprites/day/blocks/block.png");
	load_sprite(brick[0],Tbrick[0],"sprites/day/blocks/brick.png");
	load_sprite(hit[0],Thit[0],"sprites/day/blocks/hit.png");
	
	load_sprite(block_coin[0],Tblock_coin[0][0],"sprites/day/blocks/b_coin1.png");
	load_texture(Tblock_coin[0][1],"sprites/day/blocks/b_coin2.png");
	load_texture(Tblock_coin[0][2],"sprites/day/blocks/b_coin3.png");
	load_texture(Tblock_coin[0][3],"sprites/day/blocks/b_coin4.png");
	load_texture(Tblock_coin[0][4],"sprites/day/blocks/b_coin5.png");
	
	load_sprite(coin[0],Tcoin[0][0],"sprites/day/blocks/coin1.png");
	load_texture(Tcoin[0][1],"sprites/day/blocks/coin2.png");
	load_texture(Tcoin[0][2],"sprites/day/blocks/coin3.png");
	load_texture(Tcoin[0][3],"sprites/day/blocks/coin4.png");
	load_texture(Tcoin[0][4],"sprites/day/blocks/coin5.png");
}

void textures::loadSpriteDay(){
	loadSpriteDayBlock();
	
	load_sprite(nombrePieces,TnombrePieces[0],"sprites/day/nombrePieces1.png");
	load_texture(TnombrePieces[1],"sprites/day/nombrePieces2.png");
	load_texture(TnombrePieces[2],"sprites/day/nombrePieces3.png");
	load_texture(TnombrePieces[3],"sprites/day/nombrePieces4.png");
	load_texture(TnombrePieces[4],"sprites/day/nombrePieces5.png");
}

void textures::load_texture(sf::Texture &texture, const char* path){
	string str = "";
	if(path)str.append(path);

	if (!texture.loadFromFile(str)){
		//echec
	}
	else {
		cout << "texture " << str << " loaded" << endl;
	}
}

void textures::load_sprite(sf::Sprite &sprite, sf::Texture &texture, const char* path){
	string str = "";
	if(path)str.append(path);

	if (!texture.loadFromFile(str)){
		//echec
	}
	else {
		cout << "texture " << str << " loaded" << endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(0, 0));
	}
}

void textures::load_sprite(sf::Sprite &sprite, sf::Texture &texture){
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, 0));
}

void textures::funcGif(){
	sf::Clock chrono;
	sf::Time t = sf::milliseconds(150);
	sf::Time elapsed;
	chrono.restart();
	int i = 0,j;
	while(1){
		elapsed = chrono.getElapsedTime();
		if(elapsed.asMilliseconds() >= t.asMilliseconds()){
			i++;
			if(i > 4) i = 0;
			load_sprite(nombrePieces,TnombrePieces[i]);
			for(j = 0; j < 4; j++){
				load_sprite(block_coin[j],Tblock_coin[j][i]);
				load_sprite(coin[j],Tcoin[j][i]);
			}
			chrono.restart();
		}
	}
}

void textures::loadTextures(){
	loadSpriteChar();
	load_sprite(logo, Tlogo, "sprites/logo.png");
	load_sprite(goobaMenu, TgoobaMenu, "sprites/gooba_menu.png");
	loadSpriteDay();
	loadSpriteBackground();
	loadSpritePetitMario();
}

int textures::getSpriteChar(char c){
	if(c >= 'A' && c <= 'Z')
		return c - 'A';
	else if(c >= 'a' && c <= 'z')
		return c - 'a';
	else if(c >= '0' && c <= '9')
		return c - '0' + 26;
	else if (c == '*')
		return 26 + 10;
	else if (c == '-')
		return 26 + 11;
	else if (c == '!')
		return  26 + 12;
	else if (c == '@')
		return 26 + 13;
	else return 26+10+4;
}
