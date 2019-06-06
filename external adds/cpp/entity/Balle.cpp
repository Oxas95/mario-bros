#include "Balle.h"

//Constructeur de la balle en fonction du rayon de la balle utilisé
Balle::Balle(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	if(rayon == 7){// balle test
		set_texture("balle_14px.png");
		dommage = 99;
		distance = 5;
	}
	
	if(rayon == 1){
		set_texture("balle_2px.png");
		dommage = 1;
		distance = 5;
		
	}	
	if(rayon == 2){
		set_texture("balle_4px.png");
		dommage = 2;
		distance = 4;
		
	}
	if(rayon == 3){
		set_texture("balle_6px.png");
		dommage = 4;
		distance = 3;
		
	}
	if(rayon == 4){
		set_texture("balle_8px.png");
		dommage = 6;
		distance = 2;
		
	}
	if(rayon == 5){
		set_texture("balle_10px.png");
		dommage = 10;
		distance = 1;
		
	}

}

//Destructeur de la balle
Balle::~Balle(){
	printf("destruction Balle\n");
}

//Récupérer la balle
entityType Balle::getType(){
	return balle; //11
}

//Récupérer les dommage fait par la balle
int Balle::get_dommage(){
	 return dommage;
}
//Récupérer la distance effectuer par la balle
int Balle::get_distance(){
	return distance;
}
