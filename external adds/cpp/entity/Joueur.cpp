#include "Joueur.h"

Joueur::Joueur(int x, int y,int vie,bool bleu) : Entity_ronde(x,y,20,vie), rectangle(sf::Vector2f(25.f, 4.f)){

	if(bleu) set_texture("Somb3-bleu.png"); 
	
	else set_texture("Somb3-red.png");
	
	rectangle.setFillColor(sf::Color(80, 57, 50));
	rectangle.setPosition(centre.x,centre.y);
	balle = NULL;
}

Joueur::~Joueur(){
	printf("destruction Joueur\n");
	if(balle != NULL) delete balle;
}

void Joueur::draw(Fenetre& w){
	w.getWindow().draw(rectangle);
	Entity::draw(w);
}

void Joueur::drawAt(Fenetre& w, sf::Vector2i point){
	rectangle.setPosition(point.x + rayon, point.y + rayon);
	Entity::drawAt(w, point);
	rectangle.setPosition(centre.x,centre.y);
}

void Joueur::setPosition(int x, int y){
	Entity_ronde::setPosition(x, y);
	rectangle.setPosition(centre.x,centre.y);
}

void Joueur::setRotation(int i){
	rectangle.rotate(i);
}

float Joueur::getRotation(){
	return rectangle.getRotation();
	
}

entityType Joueur::getType(){
	return joueur; //6
}

void Joueur  :: save ( FILE* fs){
	fprintf( fs, "joueur  \n" ); 
	Entity_ronde :: save (fs); 
}

Balle& Joueur :: get_balle(){
	return *balle;
}

void Joueur::set_balle(int x, int y, int rayon, int vie){
	if(balle) delete balle, balle = NULL;
	balle = new Balle(x, y, rayon, 1);
}
