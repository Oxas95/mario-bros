#include "player.hpp"
#include "texture.hpp"
#include "global.hpp"

Player::Player() : sprite(textures::mario) {
	setPositionCases(sf::Vector2i(0,0));
    size = 0;
    rotation = 1;
    mp = stop;
}

Player::Player(int x, int y) : sprite(textures::mario) {
	setPositionCases(sf::Vector2i(x,y));
    size = 0;
    rotation = 1;
    mp = stop;
}

Player::Player(sf::Vector2i position) : sprite(textures::mario) {
    setPositionCases(position);
    size = 0;
    rotation = 1;
    mp = stop;
}

void Player::changeSprite(actionBody mp){
    this->mp = mp;
    switch(mp){
        case stop : textures::load_sprite(sprite, textures::TmarioStop[size]);   break;
        case jump : textures::load_sprite(sprite, textures::TmarioJump[size]);   break;
        case turn : textures::load_sprite(sprite, textures::TmarioTurn[size]);   break;
        case dead : textures::load_sprite(sprite, textures::TmarioDead);         break;
        default : break; //run et sprint sont gérés par le thread qui permet de faire un gif pendant la marche
    }
}

void Player::turnLeft(int zoomFenetre){
    if(rotation > 0){
		rotation = -1;
		sprite.setScale(rotation * zoomFenetre, zoomFenetre);
		position.x += sizeof(bigcases);
	}
}

void Player::turnRight(int zoomFenetre){
	if(rotation < 0){
		rotation = 1;
		sprite.setScale(rotation * zoomFenetre, zoomFenetre);
		position.x -= sizeof(bigcases);
	}
}

void Player::move(short vitesse){
	vitesse *= rotation;
	position.x += vitesse;
	
}

void Player::setPosition(int x, int y){
    setPosition(sf::Vector2i(x,y));
}

void Player::setPositionCases(int x, int y){
    setPosition(x * sizeof(cases), y * sizeof(cases));
}

void Player::setPosition(sf::Vector2i position){
    this->position = position;
}

void Player::setPositionCases(sf::Vector2i position){
    setPosition(position.x * sizeof(cases), position.y * sizeof(cases));
}

sf::Vector2i Player::getPosition(){
    return position;
}

void Player::drawAt(Fenetre& w, int x, int y){
	sprite.setScale(w.getZoom() * rotation, w.getZoom());
	w.drawSprite(x,y,sprite);
}

void Player::drawAtCase(Fenetre& w, int x, int y){
    x *= sizeof(cases) * w.getZoom();
	y *= sizeof(cases) * w.getZoom();
    sprite.setScale(w.getZoom() * rotation, w.getZoom());
    w.drawSprite(x,y, sprite);
}

void Player::grandir(){
    if(size < 2) {
        size++;
        changeSprite(mp);
    }
}

void Player::retrecir(){
    if(size > 0) {
        size--;
        changeSprite(mp);
    }
}

actionBody Player::getActionBody(){
	return mp;
}

short Player::getRotation(){
    return rotation;
}

short Player::getSize(){
	return size;
}

Player::~Player(){

}
