#include "texture.hpp"
#include <string>
#include <iostream>
#include "fenetre.hpp" 

using namespace std;

sf::Sprite textures::lettres[26+10+4+1];

sf::Texture textures::Tlettres[26+10+4+1];

sf::Sprite textures::logo;
sf::Texture textures::Tlogo;

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
	load_sprite(lettres[i],Tlettres[i],"sprites/lettres/co.png");
}

void textures::loadSpritePetitMario(){
	
}

void textures::loadSpriteJourBlock(){
	
}

void textures::loadSpriteLogo(){
	load_sprite(logo, Tlogo, "sprites/logo.png");
}

void textures::load_sprite(sf::Sprite &sprite, sf::Texture &texture, const char* path){
	string str = "";
	if(path)str.append(path);

	if (!texture.loadFromFile(str)){
		std::cout << "unable to load texture" << str << std::endl;
	}
	else {
		cout << "texture " << str << " loaded" << endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(0, 0));
	}
}

void textures::loadTextures(){
	loadSpriteChar();
	loadSpriteLogo();
}

int textures::getSpriteChar(char c){
	
	if(c >= 'A' && c <= 'Z')
		return c - 'A';
	else if(c >= 'a' && c <= 'z')
		return c - 'a';
	else if(c >= '0' && c <= '9')
		return c - '0';
	else if (c == '*')
		return 0;
	else if (c == '-')
		return 1;
	else if (c == '!')
		return 2;
	else if (c == '@')
		return 3;
	else return 26+10+4;
}
