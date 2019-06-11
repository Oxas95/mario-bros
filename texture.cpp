#include "texture.hpp"
#include <string>
#include <iostream>
#include "fenetre.hpp" 

#include <SFML/System.hpp>

using namespace std;

sf::Sprite textures::lettres[26+10+4+1];

sf::Texture textures::Tlettres[26+10+4+1];

sf::Sprite textures::logo;
sf::Texture textures::Tlogo;

sf::Sprite textures::nombrePieces;
sf::Texture textures::TnombrePieces[5];

sf::Sprite textures::goobaMenu;
sf::Texture textures::TgoobaMenu;

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
	load_sprite(lettres[i],Tlettres[i],"sprites/vide.png"); i++;
}

void textures::loadSpritePetitMario(){
	
}

void textures::loadSpriteJourBlock(){
	
}

void textures::loadSpriteJour(){
	load_sprite(nombrePieces,TnombrePieces[0],"sprites/jour/nombrePieces1.png");
	load_texture(TnombrePieces[1],"sprites/jour/nombrePieces2.png");
	load_texture(TnombrePieces[2],"sprites/jour/nombrePieces3.png");
	load_texture(TnombrePieces[3],"sprites/jour/nombrePieces4.png");
	load_texture(TnombrePieces[4],"sprites/jour/nombrePieces5.png");
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
	int i = 1;
	while(1){
		elapsed = chrono.getElapsedTime();
		if(elapsed.asMilliseconds() >= t.asMilliseconds()){
			load_sprite(nombrePieces,TnombrePieces[i]);
			i++;
			if(i > 4) i = 0;
			chrono.restart();
		}
	}
} 

void textures::loadTextures(){
	loadSpriteChar();
	load_sprite(logo, Tlogo, "sprites/logo.png");
	load_sprite(goobaMenu, TgoobaMenu, "sprites/gooba_menu.png");
	loadSpriteJour();
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
