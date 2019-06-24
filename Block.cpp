#include "Block.hpp"
#include "texture.hpp"
#include "Collision.hpp"
#include "fenetre.hpp"

void Block::setSprite(sf::Sprite* s){
	if(sprite) delete sprite;
	sprite = s;
}

Block::Block(sf::Vector2i pos) : position(pos) {
	sprite = NULL;
}

Block::Block(int x, int y) : position(x, y) {
	sprite = NULL;
}

Block::~Block() {}

sf::Vector2i Block::getPosition(){
	return position;
}

void Block::drawAt(Fenetre& w, int x, int y){
	w.drawSprite(x, y, *sprite);
}

void Block::drawAtCases(Fenetre& w, int x, int y){
	w.drawSpriteCases(x, y, *sprite);
}

void Block::setSpritePosition(sf::Vector2i pos){
	setSpritePosition(pos.x,pos.y);
}

void Block::setSpritePosition(int x, int y){
	sprite->setPosition(x,y);
}

bool Block::isHitted(sf::Sprite& s){
	return Collision::BoundingBoxTest(*sprite, s);
}

bool Block::isHitted(Block* b){
	sprite->setPosition(position.x,position.y);
	b->sprite->setPosition(sf::Vector2f(b->getPosition()));
	return Collision::BoundingBoxTest(*sprite, *b->sprite);
}