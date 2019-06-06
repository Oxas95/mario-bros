
#include "IA.h"

IA::IA(int x, int y,int vie,bool bleu,bool tire) : Joueur(x,y,vie,bleu){

	this->tire = tire;
	
}

bool& IA::get_tire(){
	return tire;
}

void IA::set_tire(bool tire){
	this->tire = tire;
}

IA::~IA(){
	printf("destruction IA\n");
}
