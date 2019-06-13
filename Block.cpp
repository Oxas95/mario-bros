#include "Block.hpp"
#include "texture.hpp"

void Block::setSprite(sf::Sprite& s){
	sprite = s;
}

Block::Block(sf::Vector2i pos) : sprite(textures::lettres[textures::getSpriteChar(' ')]), position(pos) {}

Block::Block(int x, int y) : sprite(textures::lettres[textures::getSpriteChar(' ')]), position(x, y) {}

Block::~Block(){
	
}

sf::Vector2i Block::getPosition(){
	return position;
}

void Block::drawAt(Fenetre& w, int x, int y){
	w.drawSprite(x, y, sprite);
}

void Block::drawAtCases(Fenetre& w, int x, int y){
	w.drawSpriteCases(x, y, sprite);
}

bool Block::isHitted(sf::Sprite& s){
	return false;
}
