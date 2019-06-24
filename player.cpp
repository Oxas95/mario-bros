#include "player.hpp"
#include "texture.hpp"
#include "global.hpp"

Player::Player() : Player(0,0){}

Player::Player(int x, int y) : Player(sf::Vector2i(x,y)){}

Player::Player(sf::Vector2i position) : sprite(textures::mario) {
    position.x *= sizeof(cases);
	position.y *= sizeof(cases);
    this->position = position;
    size = 0;
    rotation = 1;
    mp = stop;
}

void Player::changeSprite(marioPosition mp){
    this->mp = mp;
    switch(mp){
        case marioPosition::stop : textures::load_sprite(sprite, textures::TmarioStop[size]);   break;
        case marioPosition::jump : textures::load_sprite(sprite, textures::TmarioJump[size]);   break;
        case marioPosition::run  : textures::load_sprite(sprite, textures::TmarioRun[size][0]); break;
        case marioPosition::turn : textures::load_sprite(sprite, textures::TmarioTurn[size]);   break;
        case marioPosition::dead : textures::load_sprite(sprite, textures::TmarioDead);         break;
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

void Player::setPosition(int x, int y){
    setPosition(sf::Vector2i(x,y));
}

void Player::setPositionCases(int x, int y){
    setPosition(x * sizeof(cases), y * sizeof(cases));
}

void Player::setPosition(sf::Vector2i position){
    this->position = position;
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

short Player::getSize(){
	return size;
}

Player::~Player(){

}
