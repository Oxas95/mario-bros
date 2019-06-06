#include "Entity.h"
#include <string.h>
#include <iostream>

using namespace std;

Entity::Entity() : position(100,100){
	vie = 100;
}

Entity::~Entity(){
	cout << "Destruction entité" << endl;
}

Entity::Entity(int x, int y) : position(x,y){
	vie = 100;
}

bool Entity::degats(int nb){
	vie -= nb;
	if(vie <= 0) return false;
	else return true;
}

void Entity::set_texture(const char* name){
	string str = "Textures/";
	if(name)str.append(name);

	if (!texture.loadFromFile(str)){
		cout << "unable to load texture" << str << endl;
	}
	else {
		//cout << "texture " << str << " loaded" << endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(position.x, position.y));
	}
}


void Entity::draw(Fenetre& w){
	w.getWindow().draw(sprite);	
}

void Entity::drawAt(Fenetre& w, sf::Vector2i point){
	this->sprite.setPosition(point.x, point.y);
	this->draw(w);
	this->sprite.setPosition(position.x, position.y);
}

sf::Vector2i Entity::getPosition(){
	return position;
}

void Entity::setPosition(int x, int y){
	position.x = x;
	position.y = y;
	sprite.setPosition(sf::Vector2f(x, y));
}

int Entity::getVie(){
	return vie;
}

void Entity::setVie(int _vie){
	vie = _vie;
}

sf::Sprite& Entity::getSprite(){
	return sprite;
}

void Entity  :: save ( FILE* fs){
	fprintf(fs, "%d %d\n", position.x, position.y);
	fprintf( fs, "%d\n", vie );
}

