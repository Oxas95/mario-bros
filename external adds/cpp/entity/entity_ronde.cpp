#include "entity_ronde.h"
#include <iostream>

using namespace std;

Entity_ronde::Entity_ronde() : Entity() {
	
	rayon = 20;
}

Entity_ronde::~Entity_ronde(){
	cout << "Destruction entité ronde" << endl;
}

Entity_ronde::Entity_ronde(int x, int y, int rayon, int vie) : Entity(x,y){
		
	this->rayon = rayon;
	this->vie = vie;
	centre.x = position.x + rayon;
	centre.y = position.y + rayon;
	
}

int Entity_ronde::get_rayon(){
	return rayon;
}

void Entity_ronde::setPosition(int x, int y){
	Entity::setPosition(x, y);
	centre.x = rayon + x;
	centre.y = rayon + y;
}

entityType Entity_ronde::getPrimaryType(){
	return ronde;
}


void Entity_ronde  :: save ( FILE* fs){
	Entity :: save (fs); 
}
